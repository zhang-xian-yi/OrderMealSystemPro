import QtQuick 2.0

Item {
    id:shuffing;

    property double opacity_bg: 0.9;
    property int timer_intervel: 6000;
    property bool is_top: false;

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
