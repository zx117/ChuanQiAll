import QtQuick 2.15
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0

Item {
    id:headerinfchild
    width: parent.width
    height: 50


    Component.onCompleted: {
        spdlog.recordLog("TEXT",1,"testtest1111111")
        // pugixml.addMeasurementTree()
        // pugixml.setStructValue("Enclosure_Name","Local Ports")
        // pugixml.setStructValue("Enclosure_IsMainEnclosure",true)
        // pugixml.setStructValue("Enclosure_PluginId","86aa763f-8904-43dd-b0ec-ab7e70208e3e")
        // pugixml.setStructValue("Enclosure_Id","10000")
        // pugixml.addEnclosure("MeasurementNode","Name","LocalNode")
        // pugixml.channelGroupandChannelStructAddValue("Status","Status_GPS_Mode","0xDAD4FFF300000001")
        // pugixml.channelGroupandChannelStructAddValue("Status","Status_Standstill","0xDAD4FFF300000002")
        // pugixml.channelGroupandChannelStructAddValue("Status","Status_Trig_GPS","0xDAD4FFF300000004")
        // pugixml.channelGroupandChannelStructAddValue("Status","Status_Alignment","0xDAD4FFF300000008")
        // pugixml.channelGroupandChannelStructAddValue("Status","Status_SyncLock","0xDAD4FFF30000000B")
        // pugixml.addChannelGroup("Enclosure","Name","Local Ports")
        // pugixml.channelGroupandChannelStructAddValue("Rates body","Rate_Body_X","0xDAD4FFF300000023")
        // pugixml.channelGroupandChannelStructAddValue("Rates body","Rate_Body_Y","0xDAD4FFF300000024")
        // pugixml.channelGroupandChannelStructAddValue("Rates body","Rate_Body_Z","0xDAD4FFF300000025")
        // pugixml.addChannelGroup("Enclosure","Name","Local Ports")
        // pugixml.channelGroupandChannelStructAddValue("Rates horizontal","Rate_Hor_X","0xA5F4FFF300000026")
        // pugixml.channelGroupandChannelStructAddValue("Rates horizontal","Rate_Hor_Y","0xA5F4FFF300000027")
        // pugixml.channelGroupandChannelStructAddValue("Rates horizontal","Rate_Hor_Z","0xA5F4FFF300000028")
        // pugixml.addChannelGroup("Enclosure","Name","Local Ports")
        // pugixml.channelGroupandChannelStructAddValue("Accelerations body","Acc_Body_X","0xA5F4FFF300000029")
        // pugixml.channelGroupandChannelStructAddValue("Accelerations body","Acc_Body_Y","0xA5F4FFF30000002A")
        // pugixml.channelGroupandChannelStructAddValue("Accelerations body","Acc_Body_Z","0xA5F4FFF30000002B")
        // pugixml.addChannelGroup("Enclosure","Name","Local Ports")
        // pugixml.setStructValue("SystemInfoSettings_Name","OXYGEN")
        // pugixml.setStructValue("SystemInfoSettings_Version","6.5.1")
        // pugixml.setStructValue("SystemInfoSettings_Hash","51ad7677cdfe")
        // pugixml.setStructValue("SystemInfoSettings_Revision","65410")
        // pugixml.setStructValue("SystemInfoSettings_BuildDate","2023-04-13 10:46")
        // pugixml.setStructValue("SystemInfoSettings_Licensee","EVALUATION - MZGK - Bo Li")
        // pugixml.setStructValue("SystemInfoSettings_Serial","Notebook")
        // pugixml.addSystemInfo()
        // pugixml.setStructValue("ViewSetup_ChannelId","11958464329717645313")
        // pugixml.setStructValue("ViewSetup_EnumValue","Auto")
        // pugixml.setStructValue("ViewSetup_SubSecondPrecisionValue",3)
        // pugixml.setStructValue("ViewSetup_ScreenName","\\.\DISPLAY1")
        // pugixml.setStructValue("ViewSetup_ActiveMeasurementArea",0)
        // pugixml.setStructValue("ViewSetup_WindowType","master")
        // pugixml.setStructValue("ViewSetup_WindowX",0)
        // pugixml.setStructValue("ViewSetup_WindowY",0)
        // pugixml.setStructValue("ViewSetup_WindowWidth",1920)
        // pugixml.setStructValue("ViewSetup_WindowHeight",1080)
        // pugixml.setStructValue("ViewSetup_Fullscreen",false)
        // pugixml.addViewSetup()
        // pugixml.deleteNode("ChannelGroup","Name","Accelerations body")
        // pugixml.deleteNode("Channel","Name","Rate_Body_Y")
        // pugixml.setStructValue("ChannelsChannel_Id","15768509614473084928")
        // pugixml.setStructValue("ChannelsChannel_Frequency","ASYNC")
        // pugixml.setStructValue("ChannelsChannel_SampleFormat","utf8str")
        // pugixml.setStructValue("ChannelsChannel_ReducedFormat","r_sf_sf")
        // pugixml.setStructValue("ChannelsChannel_SampleDimension",0)
        // pugixml.addChannelsChannel()
        // pugixml.setStructValue("AcqSource_Uuid","45c29423-6c7b-4752-8fc2-82cd3cba3459")
        // pugixml.setStructValue("AcqSource_Name","ADMA")
        // pugixml.setStructValue("AcqSource_ChannelId",0)
        // pugixml.addAcqSource("15768509614473084928")
        // pugixml.setStructValue("ChainElement_Name","SRDividerChainElement")
        // pugixml.setStructValue("ChainElement_Name","015696a5-4c9c-4286-9a48-f30e6011d3f7")
        // pugixml.addChainElement("15768509614473084928")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","Neon/Color")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","String")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_String","#9d3d3a")
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","Neon/Name")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","String")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_String","Alias")
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","Neon/Active")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","Bool")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Bool",true)
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","Neon/Stored")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","Enum")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_EnumName","ChannelStored")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_EnumValue","Auto")
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","RecordingPosttime")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","Time")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_ScalarValue",1)
        // pugixml.setStructValue("ChannelsChannelConfigProperty_ScalarUnit","s")
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Name","Range")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_Type","Range")
        // pugixml.setStructValue("ChannelsChannelConfigProperty_RangeMin",1)
        // pugixml.setStructValue("ChannelsChannelConfigProperty_RangeMax",2)
        // pugixml.addAcqSourceOrChainElementConfig("15768509614473084928","AcqSource","ADMA")
        // console.log(pugixml.getNodeValue("Property","name","Neon/Color","StringValue"))
        // console.log(pugixml.getAttributeValue("ChannelConfig","","","Property","name"))
        // pugixml.setNodeValue("Property","name","Neon/Color","StringValue","#9d3d3a","#111111")
        // pugixml.setAttributeValue("ChannelConfig","","","Property","name","Neon/Color","Neon/Color1")

    }

    Row{
        ListModel {
            id: typemodel
            ListElement { text: "文本" }
            ListElement { text: "公式常数" }
            ListElement { text: "选择" }
        }
        BaseCombobox{
            anchors.verticalCenter: parent.verticalCenter
            width: type.width-20
            model: typemodel
        }
        Item {
            width: 30
            height: parent.height
        }
        BaseTextInput{
            anchors.verticalCenter: parent.verticalCenter
            textBoxWidth: name.width-20
            textContent: ""
        }
        Item {
            width: 10
            height: parent.height
        }
        BaseTextSmall{
            anchors.verticalCenter: parent.verticalCenter
            text: "="
        }
        Item {
            width: 10
            height: parent.height
        }
        BaseTextInput{
            anchors.verticalCenter: parent.verticalCenter
            textBoxWidth: value.width-20
            textContent: ""
        }
        Item {
            width: 20
            height: parent.height
        }
        ListModel {
            id: pointout
            ListElement { text: "从不" }
            ListElement { text: "存储开始于" }
            ListElement { text: "停止存储" }
        }
        BaseCombobox{
            anchors.verticalCenter: parent.verticalCenter
            width: point.width-20
            model: pointout
        }
        Item {
            width: 20
            height: parent.height
        }
        Item{
            width:force.width-10
            height: force.height
            BaseCheckBox{
                anchors.centerIn: parent
                anchors.verticalCenter: parent.verticalCenter
            }
        }

        Rectangle{
            id:subbtn
            anchors.verticalCenter: parent.verticalCenter
            height: 30
            width: 60
            color: "#cfcfcf"
            BaseTextSmall{
                id: subname
                anchors.centerIn: parent
                text: qsTr("删除")
            }
            MouseArea{
                anchors.fill: parent
                onPressed: {
                    subbtn.color="#a4a4a4"
                    headerinfchild.destroy();
                }
                onReleased: {
                    subbtn.color="#cfcfcf"
                }
            }
        }
    }
}
