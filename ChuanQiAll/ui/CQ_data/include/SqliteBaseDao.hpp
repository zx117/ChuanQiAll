#ifndef SQLITEBASEDAO_H
#define SQLITEBASEDAO_H

#include <future>
#include <functional>


class SqliteBaseDao
{
public:
    SqliteBaseDao() {}
    ~SqliteBaseDao() {}

    template<typename Callback, typename Func, typename Obj, typename... Args>
    auto execute_in_thread(Callback&& callback, Func&& func, Obj&& obj, Args&&... args)
        -> std::future<decltype((obj->*func)(args...))>
    {
        using return_type = decltype((obj->*func)(args...));

        auto task = std::make_shared<std::packaged_task<return_type()>>(
            std::bind(std::forward<Func>(func), std::forward<Obj>(obj), std::forward<Args>(args)...)
            );


        std::function<void()> cb = std::forward<Callback>(callback);

        std::thread([task, cb]() {
            (*task)();

            if (cb)
                cb();

        }).detach();

        return task->get_future();
    }

    // template<typename Callback, typename Func, typename Obj, typename... Args>
    // auto execute_in_thread_with_delete_obj(Callback&& callback, Func&& func, Obj&& obj, Args&&... args)
    //     -> std::future<decltype((obj->*func)(args...))>
    // {
    //     using return_type = decltype((obj->*func)(args...));

    //     auto task = std::make_shared<std::packaged_task<return_type()>>(
    //         std::bind(std::forward<Func>(func), std::forward<Obj>(obj), std::forward<Args>(args)...)
    //         );


    //     std::function<void()> cb = std::forward<Callback>(callback);

    //     std::thread([task, cb, obj]() {
    //         (*task)();

    //         delete obj;

    //         if (cb)
    //             cb();

    //     }).detach();

    //     return task->get_future();
    // }

};

#endif // SQLITEBASEDAO_H
