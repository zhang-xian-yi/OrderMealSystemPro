import QtQuick 2.7

Item {
    id: container
    width: parent.width
    height: 50

    // public:
    property alias contentRectangleAcceptedButtons: contentMouseArea.acceptedButtons
    property color contentRectangleColor: "#FFFFFF"
    property alias contentRectangleContainsMouse: contentMouseArea.containsMouse
    property alias contentRectangleCursorShape: contentMouseArea.cursorShape
    property alias contentRectangleEnabled: contentRect.enabled
    property alias contentRectangleHoverEnabled: contentMouseArea.hoverEnabled
    property alias contentRectangleMouseX: contentMouseArea.mouseX
    property alias contentRectangleMouseY: contentMouseArea.mouseY
    property alias contentRectangleIsPressed: contentMouseArea.pressed
    property alias contentRectanglePressedButtons: contentMouseArea.pressedButtons
    property color contentRectanglePressedColor: "#CCCCCC"
    property alias contentRectanglePreventStealing: contentMouseArea.preventStealing
    property alias contentRectanglePropagateComposedEvents: contentMouseArea.propagateComposedEvents


    signal contentRectangleCanceled()
    signal contentRectangleClicked(var mouse)
    signal contentRectangleDoubleClicked(var mouse)
    signal contentRectangleEntered()
    signal contentRectangleExited()
    signal contentRectanglePositionChanged(var mouse)
    signal contentRectanglePressAndHold(var mouse)
    signal contentRectanglePressed(var mouse)
    signal contentRectangleReleased(var mouse)
    signal contentRectangleWheel(var wheel)

    function hideDeleteButton(withAnimation) {
        if (withAnimation)
        {
            contentRect.state = "hidden"
        }
        else
        {
            contentRect.x = 0
        }
    }
    // private:

    onContentRectangleClicked: {
        if (ListView.view !== null)
        {
            ListView.view.currentItem.hideDeleteButton(true)
            ListView.view.currentIndex = index
        }
    }

    Rectangle {
        id: contentRect
        width: parent.width
        height: parent.height
        color: contentMouseArea.pressed ? contentRectanglePressedColor
                                        : contentRectangleColor
        MouseArea {
            id: contentMouseArea
            anchors.fill: parent

            onCanceled: {
                contentRectangleCanceled()
            }
            onClicked: {
                contentRectangleClicked(mouse)
            }
            onDoubleClicked: {
                contentRectangleDoubleClicked(mouse)
            }
            onEntered: {
                contentRectangleEntered()
            }
            onExited: {
                contentRectangleExited()
            }
            onPositionChanged: {
                contentRectanglePositionChanged(mouse)
            }
            onPressAndHold: {
                contentRectanglePressAndHold(mouse)
            }
            onReleased: {
                contentRectangleReleased(mouse)
            }
            onWheel: {
                contentRectangleWheel(wheel)
            }
        }
    }
    // private:
    default property alias __content: contentMouseArea.data
}
