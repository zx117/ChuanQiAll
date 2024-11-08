import QtQuick 2.15
import QtQuick.Controls 2.15
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Popup{
    id:addpopup
    closePolicy: Popup.NoAutoClose
    property RectangelStyle sideBarInterface :SkinManager.currentSkin.sideBarInterface
    modal: true
    focus: true
    anchors.centerIn: full2
    background:Rectangle{
        anchors.fill: parent
        color: "#ffffff"
        border.color: "#cfcfcf"
    }
    ListModel{
        id:basicMathe
        ListElement{txt:"公式";qmlFile:"BasicMathe-Formula.qml";isActive:false}
        ListElement{txt:"统计";qmlFile:"BasicMathe-Statistics.qml";isActive:false}
        ListElement{txt:"IIR Filters";qmlFile:"BasicMathe-IIRFilters.qml";isActive:false}
        ListElement{txt:"FIR Filters";qmlFile:"BasicMathe-FIRFilters.qml";isActive:false}
        ListElement{txt:"FFT";qmlFile:"BasicMathe-FFT.qml";isActive:false}
        ListElement{txt:"Cepstrum/Quefrency";qmlFile:"BasicMathe-Cepstrum.qml";isActive:false}
        ListElement{txt:"Correlation";qmlFile:"BasicMathe-Correlation.qml";isActive:false}
    }
    ListModel{
        id:advancedComputing
        ListElement{txt:"电力组";qmlFile:"AdvancedComputing-Powergroup.qml";isActive:false}
        ListElement{txt:"阶次分析";qmlFile:"AdvancedComputing-Orderanalysis.qml";isActive:false}
        ListElement{txt:"正弦扫频";qmlFile:"AdvancedComputing-Sinesweep.qml";isActive:false}
        ListElement{txt:"应变花";qmlFile:"AdvancedComputing-Strainrosette.qml";isActive:false}
        ListElement{txt:"噪声计";qmlFile:"AdvancedComputing-Noisemeter.qml";isActive:false}
        ListElement{txt:"声级计";qmlFile:"AdvancedComputing-Soundlevelmeter.qml";isActive:false}
        ListElement{txt:"机械效率图";qmlFile:"AdvancedComputing-Mechanicalefficiencychart.qml";isActive:false}
        ListElement{txt:"倍频程(CPB)";qmlFile:"AdvancedComputing-CPB.qml";isActive:false}
    }
    ListModel{
        id:dataSources
        ListElement{txt:"以太网信号接收";qmlFile:"DataSources-Ethernet.qml";isActive:false}
    }
    ListModel{
        id:unregistered
        ListElement{txt:"Tape Sensor";qmlFile:"Unregistered-TapeSensor.qml";isActive:false}
        ListElement{txt:"Resolver";qmlFile:"Unregistered-Resolver.qml";isActive:false}
    }
    ListModel{
        id:protocols
        ListElement{txt:"XR/CPAD Decoder";qmlFile:"Protocols-XR.qml";isActive:false}
        ListElement{txt:"OBD2";qmlFile:"Protocols-OBD2.qml";isActive:false}
        ListElement{txt:"MIL-STD-1553 Decoder";qmlFile:"Protocols-MILSTD.qml";isActive:false}
        ListElement{txt:"ARINC Decoder";qmlFile:"Protocols-ARINC.qml";isActive:false}
    }
    ListModel{
        id:dataTransfer
        ListElement{txt:"Ethernet Sender";qmlFile:"DataTransfer-Ethernet.qml";isActive:false}
    }
    ListModel{
        id:dataSource
        ListElement{txt:"SCPI Query";qmlFile:"DataSource-SCPI.qml";isActive:false}
        ListElement{txt:"Modbus Receiver";qmlFile:"DataSource-Modbus.qml";isActive:false}
        ListElement{txt:"External Video";qmlFile:"DataSource-ExternalVideo.qml";isActive:false}
        ListElement{txt:"DEWE3 Power Manager";qmlFile:"DataSource-DEWE3.qml";isActive:false}
        ListElement{txt:"CSV import";qmlFile:"DataSource-CSVImport.qml";isActive:false}
    }
    ListModel{
        id:basicMath
        ListElement{txt:"Frequency Measurement";qmlFile:"BasicMath-Frequency.qml";isActive:false}
    }
    Item {
        anchors.fill: parent
        Column{
            anchors.fill: parent
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    anchors.verticalCenter: parent.verticalCenter
                    text: "添加通道"
                }
            }
            Item{
                width: parent.width
                height: parent.height-60
                Row{
                    anchors.fill: parent
                    Flickable {
                        id:flickable
                        width: parent.width/4
                        height: parent.height
                        contentHeight: 1200
                        contentWidth:parent.width/4
                        clip: true
                        Column{
                            width: parent.width
                            height: parent.height
                            spacing: 5
                            Column{
                                width: parent.width
                                height: 240
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "基本数学运算"
                                    }
                                }
                                Frame{
                                    id:frame
                                    width: parent.width
                                    height: 210
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:basicmathe
                                            width: parent.width
                                            height:parent.height
                                            model: basicMathe
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        basicmathe.currentIndex = index;
                                                        for (var i = 0; i < basicMathe.count; ++i) {
                                                            if(basicMathe.get(i).isActive===false)
                                                            {
                                                                basicMathe.get(i).isActive = (i === index);

                                                            }
                                                            else
                                                            {
                                                                basicMathe.get(i).isActive=false

                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 270
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "高级运算"
                                    }
                                }
                                Frame{
                                    id:frame1
                                    width: parent.width
                                    height: 240
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:advancedcomputing
                                            width: parent.width
                                            height:parent.height
                                            model: advancedComputing
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame1.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        advancedcomputing.currentIndex = index;
                                                        for (var i = 0; i < advancedComputing.count; ++i) {
                                                            if(advancedComputing.get(i).isActive===false)
                                                            {
                                                                advancedComputing.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                advancedComputing.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 60
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "数据来源"
                                    }
                                }
                                Frame{
                                    id:frame2
                                    width: parent.width
                                    height: 30
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:datasources
                                            width: parent.width
                                            height:parent.height
                                            model: dataSources
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame2.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        datasources.currentIndex = index;
                                                        for (var i = 0; i < dataSources.count; ++i) {
                                                            if(dataSources.get(i).isActive===false)
                                                            {
                                                                dataSources.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                dataSources.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)

                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 90
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "未注册"
                                    }
                                }
                                Frame{
                                    id:frame3
                                    width: parent.width
                                    height: 60
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:unregisteredlsit
                                            width: parent.width
                                            height:parent.height
                                            model: unregistered
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame3.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        unregisteredlsit.currentIndex = index;
                                                        for (var i = 0; i < unregistered.count; ++i) {
                                                            if(unregistered.get(i).isActive===false)
                                                            {
                                                                unregistered.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                unregistered.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 150
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "Protocols"
                                    }
                                }
                                Frame{
                                    id:frame4
                                    width: parent.width
                                    height: 120
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:protocolslist
                                            width: parent.width
                                            height:parent.height
                                            model: protocols
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame4.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        protocolslist.currentIndex = index;
                                                        for (var i = 0; i < protocols.count; ++i) {
                                                            if(protocols.get(i).isActive===false)
                                                            {
                                                                protocols.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                protocols.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 60
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "Data Transfer"
                                    }
                                }
                                Frame{
                                    id:frame5
                                    width: parent.width
                                    height: 30
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:dataTransferlist
                                            width: parent.width
                                            height:parent.height
                                            model: dataTransfer
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame5.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        dataTransferlist.currentIndex = index;
                                                        for (var i = 0; i < dataTransfer.count; ++i) {
                                                            if(dataTransfer.get(i).isActive===false)
                                                            {
                                                                dataTransfer.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                dataTransfer.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 180
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "Data Sources"
                                    }
                                }
                                Frame{
                                    id:frame6
                                    width: parent.width
                                    height: 150
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:dataSourcelist
                                            width: parent.width
                                            height:parent.height
                                            model: dataSource
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame5.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        dataSourcelist.currentIndex = index;
                                                        for (var i = 0; i < dataSource.count; ++i) {
                                                            if(dataSource.get(i).isActive===false)
                                                            {
                                                                dataSource.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                dataSource.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }

                                            }
                                        }
                                    }
                                }

                            }
                            Column{
                                width: parent.width
                                height: 60
                                Item {
                                    width: parent.width
                                    height: 30
                                    BaseTextSmall{
                                        anchors.verticalCenter: parent.verticalCenter
                                        text: "Basic Math"
                                    }
                                }
                                Frame{
                                    id:frame7
                                    width: parent.width
                                    height: 30
                                    padding: 0
                                    Column {
                                        anchors.fill: parent
                                        spacing: 0
                                        ListView {
                                            id:basicmath
                                            width: parent.width
                                            height:parent.height
                                            model: basicMath
                                            interactive: false
                                            delegate:Rectangle{
                                                width: frame7.width
                                                height: 30
                                                border.color: sideBarInterface.borderColor
                                                color: model.isActive?"#91b8e0":sideBarInterface.menuBackColor
                                                Rectangle{
                                                    height: parent.height
                                                    width: 3
                                                    color: "#005bb6"
                                                    anchors.left: parent.left
                                                    visible: isActive?true:false
                                                }

                                                BaseTextSmall{
                                                    text: model.txt
                                                    color:"black"
                                                    anchors.left: parent.left
                                                    anchors.leftMargin: 20
                                                    anchors.verticalCenter: parent.verticalCenter
                                                }
                                                MouseArea{
                                                    anchors.fill: parent
                                                    onClicked: {
                                                        initListModel()
                                                        basicmath.currentIndex = index;
                                                        for (var i = 0; i < basicMath.count; ++i) {
                                                            if(basicMath.get(i).isActive===false)
                                                            {
                                                                basicMath.get(i).isActive = (i === index);
                                                            }
                                                            else
                                                            {
                                                                basicMath.get(i).isActive=false
                                                            }
                                                        }
                                                        loadPage(qmlFile)
                                                    }
                                                }
                                            }
                                        }
                                    }
                                }
                            }
                        }
                        ScrollBar.vertical: ScrollBar{}
                    }
                    Item{
                        width: parent.width*3/4
                        height: parent.height
                        Loader {
                            id:loader
                            width: parent.width
                            height: parent.height
                        }
                    }
                }

            }
            Rectangle{
                width: parent.width
                height: 30
                color: "#cfcfcf"
                Row{
                    anchors.fill: parent
                    spacing: 10
                    Item {
                        width: parent.width-220
                        height: parent.height
                    }
                    Rectangle{
                        id:closerect
                        width: 100
                        height: parent.height
                        color: "#cfcfcf"
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "取消"
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {
                                addpopup.close()
                            }
                        }
                    }
                    Rectangle{
                        width: 100
                        height: parent.height
                        color: "#cfcfcf"
                        BaseTextSmall{
                            anchors.centerIn: parent
                            text: "添加"
                        }
                        MouseArea{
                            anchors.fill: parent
                            onClicked: {


                            }
                        }
                    }

                }
            }
        }
    }
    function loadPage(qmlFile) {
        loader.source = "qrc:/qml/components/Layouts/side/FullView2Inside/Popup/AddPopup/" + qmlFile;
    }
    function initListModel(){
        for (var i = 0; i < basicMathe.count; ++i) {
            basicMathe.get(i).isActive=false
        }
        for (var i = 0; i < advancedComputing.count; ++i) {
            advancedComputing.get(i).isActive=false
        }
        for (var i = 0; i < dataSources.count; ++i) {
            dataSources.get(i).isActive=false
        }
        for (var i = 0; i < unregistered.count; ++i) {
            unregistered.get(i).isActive=false
        }
        for (var i = 0; i < protocols.count; ++i) {
            protocols.get(i).isActive=false
        }
        for (var i = 0; i < dataTransfer.count; ++i) {
            dataTransfer.get(i).isActive=false
        }
        for (var i = 0; i < dataSource.count; ++i) {
            dataSource.get(i).isActive=false
        }
        for (var i = 0; i < basicMath.count; ++i) {
            basicMath.get(i).isActive=false
        }
    }
}

