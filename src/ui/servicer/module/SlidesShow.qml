import QtQuick 2.0
import QtQuick.Controls 2.4
import QtQuick.Window 2.2

Item {
    id:shuffing;
    implicitWidth: 400;
    implicitHeight: 200;
    property double opacity_bg: 0.9;
    property int timer_intervel: 6000;
    property bool is_top: false;
    property int choose_table_num : -1;

    signal signal_submit_clicked(int table_num);
    Button {
        text: "提交";
        width: shuffing.width/8;
        height: shuffing.height/6;
        background: Rectangle{
            anchors.fill: parent;
            color:"lightblue";
        }
        anchors.right: parent.right;
        anchors.verticalCenter: parent.verticalCenter;
        onClicked: {
            popup.open();
        }
        z:4;
    }

    Popup {
        id: popup
        anchors.centerIn: Overlay.overlay
        width: parent.width * 0.6;
        height:  parent.height * 0.6;
        modal: true
        focus: true
        background: Rectangle{
            width: parent.width;
            height: parent.height;
            color: "lightblue";
        }

        closePolicy: Popup.CloseOnEscape | Popup.NoAutoClose;
        enter: Transition {
                  NumberAnimation { property: "opacity"; from: 0.0; to: 1.0 }
              }
        exit: Transition {
                  NumberAnimation { property: "opacity"; from: 1.0; to: 0.0 }
              }

        contentItem: Rectangle{
            id:content_item;
            color: "lightgray";
            Text {
                id: txt_warn;
                text: qsTr("");
                anchors.centerIn: parent;
            }
            TextInput{
                id:input_txt;
                anchors.horizontalCenter: parent.horizontalCenter;
                width: parent.width;
                height: parent.height/2;
                focus: true;
                color: "blue";
                onTextChanged: {
                    txt_warn.text = "";
                }
            }
            Button{
               id:btn_close;
               text: "确定";
               width: shuffing.width/8;
               height: shuffing.height/6;

               anchors.right: parent.right;
               anchors.bottom: parent.bottom;
               anchors.margins: 5;
               onClicked: {
                   if(input_txt.text <= 49 && input_txt.text >= 1)
                   {
                       choose_table_num = input_txt.text;
                       signal_submit_clicked(choose_table_num);
                       popup.close();
                   }
                   else
                   {
                       txt_warn.text = "输入非准确数字";
                       input_txt.text="";
                   }
               }
            }

        }
    }
    Rectangle{
        id:rect1;
        anchors.fill: parent;
        color: "lightyellow";
        opacity: opacity_bg;
        z:2;
        state:"show";
        states: [
            State {
                name: "show";
                changes: [
                    PropertyChanges {
                        target: rect1;
                        opacity:opacity_bg;
                    }
                ]
            },
            State {
                name: "hide";
                changes: [
                    PropertyChanges {
                        target: rect1;
                        opacity:0;
                    }
                ]
            }
        ]

        transitions: [
            Transition {
                PropertyAnimation{
                    property: "opacity";
                    duration: timer_intervel;
                }
            }
        ]
    }

    Timer{
        id:timer_shuffing;
        repeat: true;
        interval: timer_intervel;
        triggeredOnStart: true;
        onTriggered: {
            changeState();
        }
    }


    function changeState()
    {
        if(is_top)
        {
            rect1.state = "show";
        }
        else
        {
            rect1.state = "hide";
        }
        is_top = !is_top;
        //console.log("xxxx");
    }

    Component.onCompleted: {
        timer_shuffing.start();
    }

    Component.onDestruction: {
        timer_shuffing.stop();
    }
}
