import QtQuick 2.15
import QtQuick.Controls 2.5
import QtQuick.Layouts 1.0
import Widgets 1.0
import Themes 1.0
Rectangle{
    property RectangelStyle sideBarInterface: SkinManager.currentSkin.sideBarInterface
    property var dataModel: ["时间,本地", "日期,本地", "计数,本地", "时间,UTC", "日期,UTC", "计数,零起", "时间,小时-分钟-秒", "日期,日月年"]
    property var dataModel1: ["hh:mm:ss", "yyyyMMdd", "1234", "hh:mm:ss", "yyyyMMdd", "12", "hh-mm-ss", "dd-MM-yy"]
    color: sideBarInterface.backgroundColor
    border.color: sideBarInterface.borderColor
    Item {
        id:save
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            spacing: 10
            Layout.fillHeight: true
            Layout.fillWidth: true
            BaseTextSmall{
                text: "数据存储"
                font.bold: true
            }
            BaseTextSmall{
                text: "数据文件夹"
            }
            Row{
                Layout.fillWidth: true
                spacing: 10
                BaseTextInput{

                    textBoxWidth:save.width/2-100
                    textContent:"D:/DATA/"
                }
                TextButton{
                    width: 70
                    height: 20
                    text: "浏览"
                }
            }
            BaseTextSmall{
                text: "导出文件夹"
            }
            Row{
                Layout.fillWidth: true
                spacing: 10
                BaseTextInput{
                    textBoxWidth:save.width/2-100
                    textContent:"E:/DATA/"
                }
                TextButton{
                    width: 70
                    height: 20
                    text: "浏览"
                }
            }
            BaseTextSmall{
                font.bold: true
                text: "存储文件名"
            }

            Rectangle{
                width: save.width/2-100
                height: 100
                TextInput{
                    anchors.fill: parent
                    font.pixelSize: 20
                    font.family: "微软雅黑"
                    text: "m_#{Date}_#{Time}"
                }
            }

            Item{
                width: save.width/2-100
                height: 250
                Grid {
                    id:grid
                    columns: 3
                    rows: 3
                    spacing: 10
                    anchors.centerIn: parent
                    Repeater {
                        id:pagerect
                        model: dataModel
                        delegate: Rectangle {
                            id:rect
                            width: (save.width/2-130)/3
                            height: 60
                            color: "#efefef"
                            Column{
                                anchors.fill: parent
                                Item{
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        anchors.left: parent.left
                                        anchors.leftMargin: 10
                                        text: modelData
                                    }
                                }
                                Item {
                                    width: parent.width
                                    height: parent.height/2
                                    BaseTextSmall{
                                        anchors.left: parent.left
                                        anchors.leftMargin: 10
                                        color: "#cfcfcf"
                                        font.pointSize: 7
                                        text: dataModel1[index]
                                    }
                                }
                            }
                        }
                    }
                }
            }

            BaseTextSmall{
                text: "文件名预览"
            }
            BaseTextSmall{
                color: "#a4a4a4"
                text: "xxx-xxxxxxx.dmd"
            }
            BaseTextSmall{
                text: "本地计数起始"
            }
            BaseTextInput{
                textContent: "1"
            }
            BaseCheckBox{
                checkText: "存储前输入文件名"
            }
            BaseCheckBox{
                checkText: "存储结束后自动打开DMD文件"
            }
        }
    }

}
