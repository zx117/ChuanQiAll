#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QQuickView>
#include <QSurfaceFormat>
#include <QLocale>
#include <QTranslator>
#include <QDir>

#include "appfactory.h"
#include "appsystem.h"
#include "apphost.h"

#include "listmodel.h"
#include "tablemodel.h"
#include "treemodel.h"
#include "displayfilesystemmodel.h"
#include "interface.h"
#include "pugixmlinterface.h"
#include "logoperations.h"

#include <chrono>
#include <iostream>
#include <thread>
#include <cqdaq/cqdaq.h>

#include <sqlite3.h>

int main(int argc, char *argv[])
{

#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QApplication app(argc, argv);
    QTranslator translator;
    const QStringList uiLanguages = QLocale::system().uiLanguages();
    for (const QString &locale : uiLanguages) {
        const QString baseName = "ChuanQiAll_" + QLocale(locale).name();
        if (translator.load(":/i18n/" + baseName)) {
            app.installTranslator(&translator);
            break;
        }
    }

    QQmlApplicationEngine engine;
    engine.addImportPath(QStringLiteral("qrc:/qml/components"));

    qmlRegisterUncreatableType<AbstractApp>("ThisApp", 1, 0, "ThisApp", "ThisApp");
    qmlRegisterUncreatableType<AppHost>("AppHost", 1, 0, "AppHost", "AppHost");

    LogOperations* spdlog = new LogOperations();
    QString path = QCoreApplication::applicationDirPath() + "/logs";
    spdlog->createLogger(path,"log");
    engine.rootContext()->setContextProperty("spdlog", spdlog);

    PugiXMLInterface* pugixml = new PugiXMLInterface;
    QString filepath=QCoreApplication::applicationDirPath()+"/xmldms/configurationfiles.xml";
    pugixml->initialization(filepath);
    engine.rootContext()->setContextProperty("pugixml", pugixml);

    TreeModel *treeModel=new TreeModel();
    treeModel->parseXmlFile("C:\\Users\\CQ\\Desktop\\ChuanQiAll\\ceshi.xml");
    qmlRegisterSingletonInstance("MyTreeModel",1,0,"MyTreeModel",treeModel);

    ListModel *listModel=new ListModel();
    qmlRegisterSingletonInstance("MyListModel",1,0,"MyListModel",listModel);

    TableModel *tableModel=new TableModel();
    qmlRegisterSingletonInstance("MyTableModel",1,0,"MyTableModel",tableModel);

    DisplayFileSystemModel * fileModel = new DisplayFileSystemModel();
    fileModel->setRootPath("D:/DATA");
    qmlRegisterSingletonInstance("MyFileSystemModel",1,0,"MyFileSystemModel",fileModel);

    DisplayFileSystemModel * diskModel = new DisplayFileSystemModel();
    diskModel->setRootPath("disk");
    qmlRegisterSingletonInstance("MyDiskModel",1,0,"MyDiskModel",diskModel);

    // 初始化采集引擎，生成数采控制实例
    // 1. 装载所有插件：数据采集、计算功能。插件以模块形式存在。装载进内存
    // 2. 加载功能组件（初始化）：日志、任务调度
    daq::InstancePtr instance = daq::Instance("");

    // Find and connect to a device hosting an OPC UA TMS server
    // 罗列出装载了多少个有效设备，也就是识别到的设备。
    const auto availableDevices = instance.getAvailableDevices();
    daq::DevicePtr device;
    for (const auto& deviceInfo : availableDevices)
    {
        /*        for (const auto & capability : deviceInfo.getServerCapabilities())
        {
            if (capability.getProtocolName() == "cqDAQ OpcUa")
            {
                device = instance.addDevice(capability.getConnectionString());
                break;
            }
        }
*/
        // 把有效设备进行控制，需要激活的加进来
        // 需要加上界面控制激活逻辑，激活之后再加进来
        // 目前加进去是自启动，以后改成start指令去启动采集
        device = instance.addDevice(deviceInfo.getConnectionString());

        const auto config = device.saveConfiguration();
        std::cout << config;
    }

    // Exit if no device is found
    if (!device.assigned())
    {
        std::cerr << "No relevant device found!" << std::endl;
        return 0;
    }

    // Output the name of the added device
    std::cout << device.getInfo().getName() << std::endl;

    // Output 10 samples using reader
    using namespace std::chrono_literals;

    // Get the first channel and its signal
    // device.getChannels()返回通道列表。
    // 再决定取哪个通道的数值
    daq::ListPtr<daq::IChannel> channelList = device.getChannels();
    daq::ChannelPtr channel = device.getChannels()[0];
    // 取出通道之后，对应哪个通道的数据：信号表示
    daq::SignalPtr signal = channel.getSignals()[0]; // 信号

    // 使用StreamReader读数据，两组数据《时戳、测量值》
    daq::StreamReaderPtr reader = daq::StreamReader<double, uint64_t>(signal);

    // Get the resolution and origin
    daq::DataDescriptorPtr descriptor = signal.getDomainSignal().getDescriptor(); // 针对时戳数据
    daq::RatioPtr resolution = descriptor.getTickResolution(); // 根据描述符 解析数据
    std::cout << "resolution: " << resolution << std::endl;
    daq::StringPtr origin = descriptor.getOrigin();
    daq::StringPtr unitSymbol = descriptor.getUnit().getSymbol();

    std::cout << "Reading signal: " << signal.getName() << std::endl;
    std::cout << "Origin: " << origin << std::endl;

    // Allocate buffer for reading double samples
    double samples[100];
    uint64_t domainSamples[100];
     int cnt = 0;
    // while (cnt < 40)
    {
        std::this_thread::sleep_for(100ms);

        // Read up to 100 samples every 25ms, storing the amount read into `count`
        daq::SizeT count = 100;
        reader.readWithDomain(samples, domainSamples, &count);
        if (count > 0)
        {
            std::cout << "count: " << count << std::endl;
            // for(int i=0; i<count; ++i)
            // {
            //     // daq::Float domainValue = (daq::Int) domainSamples[count - 1] * resolution;
            //     daq::Float domainValue = (daq::Int) domainSamples[i] * resolution;
            //     std::cout << "Value1: " << samples[count - 1] << ", Domain: " << domainValue << unitSymbol << std::endl;
            // }
            std::cout << "Value2: " << samples[count - 1] << ", Domain: " << domainSamples[count - 1]  << (daq::Int) domainSamples[count - 1] * resolution<< std::endl;
            cnt++;
        }
    }

    using namespace date;

    // From here on the reader returns system-clock time-points as a domain
    auto timeReader = daq::TimeReader(reader);

    // Allocate buffer for reading time-stamps
    std::chrono::system_clock::time_point timeStamps[100];
    cnt = 0;
    // while (cnt < 40)
    {
        std::this_thread::sleep_for(100ms);

        // Read up to 100 samples every 25ms, storing the amount read into `count`
        daq::SizeT count = 100;
        reader.readWithDomain(samples, timeStamps, &count);
        if (count > 0)
        {
            std::cout << "Value2: " << samples[count - 1] << ", Domain: " << timeStamps[count - 1] << std::endl;
            cnt++;
        }
    }

    // 加工模块 得到所有有效功能模块类型。功能模块 类似上面获取设备
    auto bts = instance.getAvailableFunctionBlockTypes();
    qDebug() << "===================1111";
    daq::FunctionBlockPtr fft = instance.addFunctionBlock("ref_fb_module_fft"); // 计算的功能模块
    fft.getInputPorts()[0].connect(signal); // 连接信号

    // 保存数据，是否也要设计成功能模块
    // 获取数据，是否和保存一起

    daq::FunctionBlockPtr save = instance.addFunctionBlock("ref_fb_module_saver"); // 保存的功能模块
    int sigIndex = 0;
    for (const auto& channel : channelList) {
        daq::ListPtr<daq::ISignal> signas = channel.getSignals(); // 信号
        for (const auto& sig : signas) {
            save.getInputPorts()[sigIndex].connect(sig);
            sigIndex ++;
        }
    }

    // Create an instance of the renderer function block
    daq::FunctionBlockPtr renderer = instance.addFunctionBlock("ref_fb_module_renderer"); // 显示的模块
    // Connect the first output signal of the device to the renderer
    renderer.getInputPorts()[0].connect(signal);
    renderer.getInputPorts()[1].connect(fft.getSignals()[0]);

    // Create an instance of the statistics function block
    daq::FunctionBlockPtr statistics = instance.addFunctionBlock("ref_fb_module_statistics"); // 统计的功能模块

    // Connect the first output signal of the device to the statistics
    statistics.getInputPorts()[0].connect(signal);
    // Connect the first output signal of the statistics to the renderer
    renderer.getInputPorts()[2].connect(statistics.getSignals()[0]);

    // List the names of all properties
    for (daq::PropertyPtr prop : channel.getVisibleProperties())
        std::cout << prop.getName() << std::endl;

    // Set the frequency to 5Hz
    //channel.setPropertyValue("Frequency", 5);
    // Set the noise amplitude to 0.75
    //channel.setPropertyValue("NoiseAmplitude", 0.75);


    AppHost *host = new AppHost();
    host->init(&engine);

    qmlRegisterType<Interface>("MyInterface", 1, 0, "MyInterface");

    engine.rootContext()->setContextProperty("AppHost", host);

    const QUrl url(QStringLiteral("qrc:/qml/main.qml"));
    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreated,
        &app,
        [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        },
        Qt::QueuedConnection);

    engine.load(url);

    int ret = app.exec();

    delete host;
    delete spdlog;
    delete pugixml;
    delete treeModel;
    delete listModel;
    delete tableModel;
    delete fileModel;
    delete diskModel;
    return ret;
}
