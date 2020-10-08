import QtQuick 2.7//不同Qt版本使用的QtQuick版本可能不同，需修改

Rectangle {
    //自定义属性
    property string btMesg: ""//按钮按下时发出的字符串
    property string btText: ""//按钮文字

    property color  textColor: "#ff000000"
    property string pressedTextColor: textColor
    property string releaseTextColor: textColor

    property real   fontSize: 20

    property string buttonColor: "#00000000"
    property string pressedColor: buttonColor
    property string releaseColor: buttonColor

    property string btIcon: ""
    property string pressedIcon: btIcon
    property string releaseIcon: btIcon

    property string borderColor: textColor
    property string pressdBorderColor: pressedTextColor

    property alias wrapMode: textId.wrapMode
    property alias elide: textId.elide

    width: 80; height: 60
    color: mouseArea.pressed?pressedColor:releaseColor
    border.width: 0
    border.color: mouseArea.pressed?pressdBorderColor:borderColor
    focus : true
    signal clicked()
    signal clickedWithMesg(string mesg)
    signal pressed()
    signal release()

    Image {
        id: image
        anchors.horizontalCenter: parent.horizontalCenter
        anchors.top: parent.top
        anchors.topMargin: (parent.height - height - textId.height - 5) / 2
        source: mouseArea.pressed?pressedIcon:releaseIcon
    }
    Text {
        id: textId
        anchors.top: image.bottom
        anchors.horizontalCenter: parent.horizontalCenter
        horizontalAlignment: Text.AlignHCenter
        wrapMode: Text.WordWrap
        width: parent.width
        text: btText
        color: mouseArea.pressed?pressedTextColor:releaseTextColor
        font.pixelSize: fontSize
    }

    MouseArea{
        id : mouseArea
        hoverEnabled: true
        anchors.fill: parent
        onClicked: {
            parent.clicked()
            parent.clickedWithMesg(btMesg)
        }
        onPressed: {
            parent.pressed(btMesg)
        }
        onReleased: {
            parent.release()
        }
    }
}