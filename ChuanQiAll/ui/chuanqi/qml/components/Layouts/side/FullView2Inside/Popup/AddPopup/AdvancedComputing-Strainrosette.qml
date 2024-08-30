import QtQuick 2.15
import QtQuick.Controls 1.4
import QtQuick.Layouts 1.1
import MyTreeModel 1.0
import Widgets 1.0
import Themes 1.0
Item {
    anchors.fill: parent
    Item {
        width: parent.width-20
        height: parent.height-20
        anchors.centerIn: parent
        Column{
            anchors.fill: parent
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    text: "应变花类型"
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    ExclusiveGroup { id: buttonGroup }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "45°"
                        exclusiveGroup: buttonGroup
                        enabled: true
                        checked: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "60°"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "90°"
                        exclusiveGroup: buttonGroup
                        enabled: true
                    }

                }
            }
            Item {
                width: parent.width
                height: 30
                BaseTextSmall{
                    text: "角度参考"
                }
            }
            Item{
                width: parent.width
                height: 30
                Row{
                    anchors.fill: parent
                    spacing: 10
                    ExclusiveGroup { id: buttonGroup1 }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "A"
                        exclusiveGroup: buttonGroup1
                        enabled: true
                        checked: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "B"
                        exclusiveGroup: buttonGroup1
                        enabled: true
                    }
                    BaseRadioButton{
                        radioWidth: 100
                        radioHeight: 30
                        radioButtonText: "C"
                        exclusiveGroup: buttonGroup1
                        enabled: true
                    }

                }
            }
            Item{
                width: parent.width
                height: 60
                Row{
                    anchors.fill: parent
                    spacing: 10
                    Column{
                        width: 100
                        height: parent.height
                        spacing: 10
                        BaseTextSmall{
                            text: "泊松比"
                        }
                        BaseTextInput{
                            textBoxWidth:100
                            textBoxHeight: 20
                            textContent: "0.03"
                        }
                    }
                    Column{
                        width: 200
                        height: parent.height
                        spacing: 10
                        BaseTextSmall{
                            text: "杨氏模型"
                        }
                        Row{
                            width: parent.width
                            height: parent.height-30
                            spacing: 10
                            BaseTextInput{
                                textBoxWidth:100
                                textBoxHeight: 20
                                textContent: "69"
                            }
                            ListModel {
                                id: yangmodel
                                ListElement { text: "Mpa" }
                                ListElement { text: "Gpa" }
                                ListElement { text: "kgf/mm2" }
                            }
                            BaseCombobox{
                                id:  windowbox
                                combWidth: 90
                                combHeight: 20
                                model: yangmodel
                                currentIndex: 0
                            }
                        }


                    }
                    Column{
                        width: 100
                        height: parent.height
                        spacing: 10
                        BaseTextSmall{
                            text: "应变单位"
                        }
                        ListModel {
                            id: unitmodel
                            ListElement { text: "um/m" }
                            ListElement { text: "microstrain" }
                        }
                        BaseCombobox{
                            id:  unit
                            combWidth: 90
                            combHeight: 20
                            model: unitmodel
                            currentIndex: 0
                        }
                    }
                }
            }
            Column{
                width: 100
                height: parent.height
                spacing: 5
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "输出通道"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最大主应变"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最小主应变"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "角度"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "平均应变"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最大剪应变"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最大主应力"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最小主应力"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "最大剪应力"
                    ischecked: true
                }
                BaseSwitch{
                    switchWidth: 100
                    switchHeight: 25
                    switchText: "等效应力"
                    ischecked: true
                }
            }
        }
    }
}
