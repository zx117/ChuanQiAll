import QtQuick 2.15;
import Widgets 1.0
import Themes 1.0
Rectangle {
    width: 200;
    height: 250;
    color: "#efefef";
    Column{
        anchors.fill: parent
        BaseTextModerate{
            text: "DESKTOP-IUDABC2"
            font.bold: true
        }
        BaseTextSmall{
            text: "OXYGEN-NET"
        }
        BaseTextSmall{
            text: "v6.51"
        }
        BaseTextSmall{
            text: "ADMA Ensolure"
            font.bold: true
        }
        Row{
            BaseTextSmall{
                text: "IP:"
            }
            BaseTextSmall{
                text: "127.0.0.1"
            }
        }
        Row{
            BaseTextSmall{
                text: "Status:"
            }
            BaseTextSmall{
                text: "Not claimable"
            }
        }
        BaseTextSmall{
            text: "Local Node"
        }
    }
}
