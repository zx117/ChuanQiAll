import QtQuick 2.0
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
Item {
    id:list
    width: parent.width
    height: parent.height
    property var listModel: null
    ColumnLayout{
        anchors.fill: parent
        spacing: 0
        Rectangle{
            id:listhead
            Layout.fillWidth: true
            height: 30
            color: "#a4a4a4"
            RowLayout{
                anchors.fill: parent
                spacing: 0
                Item{
                    height: 30
                    Layout.preferredWidth: parent.width*3/5
                    BaseTextModerate{
                        text: "文件名"
                        anchors.centerIn: parent
                        color: "#ffffff"
                    }

                }
                Rectangle{
                    height: 15
                    width: 2
                    Layout.alignment: Qt.AlignVCenter
                    color: "#cfcfcf"
                }
                Item{
                    height: 30
                    Layout.preferredWidth: parent.width*1/5-2
                    BaseTextSmall{
                        text: "文件大小"
                        anchors.centerIn: parent
                        color: "#ffffff"
                    }
                }
                Rectangle{
                    height: 15
                    width: 2
                    Layout.alignment: Qt.AlignVCenter
                    color: "#cfcfcf"
                }
                Item{
                    height: 30
                    Layout.preferredWidth: parent.width*1/5-2
                    BaseTextSmall{
                        text: "日期"
                        anchors.centerIn: parent
                        color: "#ffffff"
                    }
                }
            }
        }
        ListView{
            Layout.fillWidth: true
            Layout.fillHeight: true
            clip: true
            model: listModel
            delegate: Rectangle{
                width: list.width
                height: 30
                color: checkbox.checked?"#b3ceea":(index % 2 === 0? "lightgray" : "white")
                BaseCheckBox{
                    id:checkbox
                    anchors.verticalCenter: parent.verticalCenter
                    checkText:model.filename
                }

            }
        }
    }
}
