#ifndef THREADPOOL_HPP
#define THREADPOOL_HPP

#include <thread>
#include <mutex>
#include <condition_variable>
#include <future>
#include <functional>
#include <queue>
#include <vector>

class ThreadPool {
public:
    ThreadPool(int num_threads);
    ~ThreadPool();

    template<class F, class... Args>
    auto enqueue(F&&f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>>;

private:
    void worker();
    bool is_stop;
    std::mutex _mtx;
    std::condition_variable _cv;
    std::vector<std::thread> workers;
    std::queue<std::function<void()>> _tasks;
};

ThreadPool::ThreadPool(int num_threads) : is_stop(false) {
    for (size_t i = 0; i < num_threads; ++i) {
        workers.emplace_back([this] {
            this->worker();
        });
    }
}

ThreadPool::~ThreadPool() {
    {
        std::unique_lock<std::mutex> lock(_mtx);
        is_stop = true;
    }

    _cv.notify_all();

    for (auto& worker : workers) {
        worker.join();
    }
}

template<class F, class... Args>
auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<std::invoke_result_t<F, Args...>> { 
    using result_type = std::invoke_result_t<F, Args...>;
    auto task = std::make_shared<std::packaged_task<result_type()>>(
        std::bind(std::forward<F>(f), std::forward<Args>(args)...)
    );

    std::future<result_type> res = task->get_future();

    {
        std::lock_guard<std::mutex> lock(_mtx);
        if (is_stop)
            throw std::runtime_error("enqueue on stopped ThreadPool");

        _tasks.emplace([task]() { 
            (*task)(); 
        });
    }
    
    _cv.notify_one();
    return res;
}

auto ThreadPool::worker() -> void {
    while (true) {
        std::function<void()> task;
        {
            std::unique_lock<std::mutex> lock(_mtx);
            _cv.wait(lock, [this] { return is_stop || !_tasks.empty(); });

            if (is_stop && _tasks.empty())
                return;
            
            task = std::move(_tasks.front());
            _tasks.pop();
        }

        task();
    };
}

#endif // THREADPOOL_HPP
