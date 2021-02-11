/*!
 *@file BaseTabBar.qml
 *@brief 自定义TabBar
 *@version 1.0
 *@author zhangxianyi
*/
import QtQuick 2.7
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0

TabBar {
    property alias tabBarModel: bar_model;
    property int lastIndex: 0;
    id: bar;
    currentIndex: 0;
    ListModel {
        id: bar_model;
    }

    Repeater {
        id: repeater;
        model: bar_model;

        TabButton {
            property alias imageSource: image.source;
            property alias textColor: text.color;
            height: bar.height
            contentItem:Text{
                id: text
                text: modelText
                horizontalAlignment: Text.AlignHCenter
                verticalAlignment: Text.AlignBottom
                color: (model.index === bar.currentIndex) ? modelColorG : modelColor
            }
            background:Image{
                id: image;
                width: 48;
                height: 48;
                anchors.horizontalCenter: parent.horizontalCenter;
                source: (model.index === bar.currentIndex) ? modelSrcG : modelSrc;
            }

            onHoveredChanged: {
                if (model.index !== bar.currentIndex){
                    hovered ? text.color = modelColorG : text.color = modelColor;
                    hovered ? image.source = modelSrcG : image.source = modelSrc;
                }
            }
            onClicked: {
                repeater.itemAt(bar.lastIndex).imageSource = bar_model.get(bar.lastIndex).modelSrc;
                repeater.itemAt(bar.lastIndex).textColor = modelColor;

                image.source = modelSrcG;
                text.color = modelColorG;
                bar.lastIndex = model.index;
            }
        }
    }
}
