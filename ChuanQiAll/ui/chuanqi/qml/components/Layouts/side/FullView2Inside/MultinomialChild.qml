import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import Widgets 1.0
import Themes 1.0
import MyInterface 1.0
Item{
    id:formchild
    width:parent.width
    height: 30
    Row{
        spacing: 10
        width: parent.width
        height: 30
        Item {
            width: parent.width*2/5-5
            height: 30
            BaseTextSmall{
                anchors.verticalCenter: parent.verticalCenter
                text: "X"
            }
        }
        BaseTextInput{
            textBoxWidth: parent.width*2/5-5
            textBoxHeight: 30
            textContent: "0"
        }
        Item{
            width: parent.width/5
            height: 30
            Rectangle{
                id:subbtn
                width: parent.width-40
                height: 20
                color: "#efefef"
                anchors.centerIn: parent
                BaseTextSmall{
                    anchors.centerIn: parent
                    text: "减少"
                    MouseArea{
                        anchors.fill: parent
                        onPressed: {
                            subbtn.color="#a4a4a4"
                            formchild.destroy();
                        }
                        onReleased: {
                            subbtn.color="#efefef"
                        }
                    }
                }
            }
        }
    }
}
