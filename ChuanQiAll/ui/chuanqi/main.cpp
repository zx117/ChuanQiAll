#include <QApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <QQuickView>
#include <QSurfaceFormat>
#include <QLocale>
#include <QTranslator>
#include <QDir>
#include <QDebug>

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
#include <QQuickWidget>

#include <cqdaq/worker.h>
#include <cqdaq/ncc_ptr.h>
#include <cqdaq/data_center_ptr.h>
#include <cqdaq/instance_ptr.h>

#include <save/icommunication.h>


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

    // Find and load all actived device
    const auto availableDevices = instance.getAvailableDevices();
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
        instance.addDevice(deviceInfo.getConnectionString());
        qDebug() << deviceInfo.getConnectionString().toStdString().c_str();
    }

    // Init all loaded
    daq::NccPtr ncc = instance.getNccManager();
    daq::WorkerPtr ctrl = ncc.asPtr<daq::IWorker>();
    ctrl.initialize();
    ctrl.channelCreate();
    ctrl.applyConfigChanged();

    // load configuration
    daq::StringPtr last_config("");
    ctrl.stopAcquisition();
    //instance.loadConfiguration(last_config);
    ctrl.channelCreate();
    ctrl.applyConfigChanged();
    ctrl.loadFinish();

    //acqusition
    last_config = instance.saveConfiguration();
    ctrl.initializeAcquisition();
    ctrl.startAcquisition();

    //stop
    //ctrl.stopAcquisition();
    //ctrl.finalizeAcquisition();

    // topology and channel
    daq::DataCenterPtr dc;
    dc = instance.getDataCenter();

    daq::FolderPtr topo = dc.getChannelTopology();
    daq::ListPtr<daq::IChannel> channels = dc.getAllChannels();

    //device info
    daq::DevicePtr device;
    device = instance.getRootDevice();
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

    // Get the first channel and property
    daq::ChannelPtr channel = device.getChannels()[1];
    daq::PropertyPtr nameProp = channel.getProperty("Name");
    daq::PropertyPtr samplerateProp = channel.getProperty("SampleRate");
    daq::PropertyPtr usedProp = channel.getProperty("Used");
    daq::PropertyPtr rangeProp = channel.getProperty("Range");
    daq::PropertyPtr unitProp = channel.getProperty("Unit");
    daq::PropertyPtr colorProp = channel.getProperty("Color");
    daq::PropertyPtr factorProp = channel.getProperty("Factor");
    daq::PropertyPtr offsetProp = channel.getProperty("Offset");

    // Get property value
    double sv = channel.getPropertyValue("SampleRate");
    daq::StringPtr name = channel.getPropertyValue("Name");
    daq::Float factor = channel.getPropertyValue("Factor");

    // Set property value
    channel.setPropertyValue("Name","NewName");
    name = channel.getPropertyValue("Name");

    channel.setPropertyValue("Used", false);
    channel.setPropertyValue("SampleRate", 1500.0);
    sv = channel.getPropertyValue("SampleRate");

    channel.setPropertyValue("Unit", "V");
    daq::StringPtr unit = channel.getPropertyValue("Unit");

    channel.setPropertyValue("Factor", 10.0);

    // 取出通道之后，对应哪个通道的数据：信号表示
    daq::ListPtr<daq::IChannel> channelList = device.getChannels();
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

    // // Allocate buffer for reading double samples
    // double samples[100];
    // uint64_t domainSamples[100];
    //  int cnt = 0;
    // while (cnt < 40)
    // {
    //     std::this_thread::sleep_for(100ms);

    //     // Read up to 100 samples every 25ms, storing the amount read into `count`
    //     daq::SizeT count = 100;
    //     reader.readWithDomain(samples, domainSamples, &count);
    //     if (count > 0)
    //     {
    //         std::cout << "count: " << count << std::endl;
    //         // for(int i=0; i<count; ++i)
    //         // {
    //         //     // daq::Float domainValue = (daq::Int) domainSamples[count - 1] * resolution;
    //         //     daq::Float domainValue = (daq::Int) domainSamples[i] * resolution;
    //         //     std::cout << "Value1: " << samples[count - 1] << ", Domain: " << domainValue << unitSymbol << std::endl;
    //         // }
    //         std::cout << "Value2: " << samples[count - 1] << ", Domain: " << domainSamples[count - 1]  << (daq::Int) domainSamples[count - 1] * resolution<< std::endl;
    //         cnt++;
    //     }
    // }

    // using namespace date;

    // // From here on the reader returns system-clock time-points as a domain
    // auto timeReader = daq::TimeReader(reader);

    // // Allocate buffer for reading time-stamps
    // std::chrono::system_clock::time_point timeStamps[100];
    // cnt = 0;
    // // while (cnt < 40)
    // {
    //     std::this_thread::sleep_for(100ms);

    //     // Read up to 100 samples every 25ms, storing the amount read into `count`
    //     daq::SizeT count = 100;
    //     reader.readWithDomain(samples, timeStamps, &count);
    //     if (count > 0)
    //     {
    //         std::cout << "Value2: " << samples[count - 1] << ", Domain: " << timeStamps[count - 1] << std::endl;
    //         cnt++;
    //     }
    // }

    // 加工模块 得到所有有效功能模块类型。功能模块 类似上面获取设备
    auto bts = instance.getAvailableFunctionBlockTypes();
    auto test = instance.getFunctionBlocks();
    qDebug() << "===================1111" << test.getCount() << bts.getCount();
    auto ks = bts.getKeys();
    for(auto i : ks){
        qDebug() << "===================222" << QString::fromStdString(i.toStdString());
    }

    daq::FunctionBlockPtr fft = instance.addFunctionBlock("ref_fb_module_fft"); // 计算的功能模块
    fft.getInputPorts()[0].connect(signal); // 连接信号

    // 保存数据，是否也要设计成功能模块
    // 获取数据，是否和保存一起

    daq::FunctionBlockPtr save = instance.addFunctionBlock("ref_fb_module_saver"); // 保存的功能模块
    daq::ICommunication* com = save.as<daq::ICommunication>(true);
    com->startSaving();

    int sigIndex = 0;
    qDebug() << "========== channel count : " << channelList.getCount();
    for (const auto& channel : channelList) {
        daq::ListPtr<daq::ISignal> signas = channel.getSignals(); // 信号
        for (const auto& sig : signas) {
            qDebug() << "========== signals\n" << sig.getName().toStdString().c_str();
            save.getInputPorts()[sigIndex].connect(sig);
            sigIndex ++;
        }
    }

    com->pauseSaving();
    com->continueSaving();
    // com->pauseSaving();

    // com->stopSaving();

    // // Create an instance of the renderer function block
    // daq::FunctionBlockPtr renderer = instance.addFunctionBlock("ref_fb_module_renderer"); // 显示的模块
    // // Connect the first output signal of the device to the renderer
    // renderer.getInputPorts()[0].connect(signal);
    // renderer.getInputPorts()[1].connect(fft.getSignals()[0]);

    // // Create an instance of the statistics function block
    // daq::FunctionBlockPtr statistics = instance.addFunctionBlock("ref_fb_module_statistics"); // 统计的功能模块

    // // Connect the first output signal of the device to the statistics
    // statistics.getInputPorts()[0].connect(signal);
    // // Connect the first output signal of the statistics to the renderer
    // renderer.getInputPorts()[2].connect(statistics.getSignals()[0]);

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

    // QQuickWidget *quickWidget = new QQuickWidget(engine, );
    // quickWidget->setSource(QUrl("qrc:/qml/main.qml"));
    // quickWidget->show();

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
