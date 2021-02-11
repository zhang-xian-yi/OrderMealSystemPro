import QtQuick 2.7
import QtQuick.Controls 2.4
import "../component/"

Item{
    id:component_list_view
    visible: true;
    implicitWidth:  360;
    implicitHeight: 360;

    property alias model_name: listView.model;
    signal signal_add(string name,int price_value);
    signal signal_devide(string name,int price_value);
    ListView {
        id: listView
        anchors.fill: parent;
        model: dataModel;
        clip: true;
        highlightFollowsCurrentItem: true;

        delegate:  ZListViewDelegrate{
            id: itemContent
            width: listView.width;
            height: 80
            Rectangle {
                id:img_rect;
                width: 100;
                height: 70;
                color: testMouseArea.pressed ? "#E86688" : "#80E86688"
                anchors.verticalCenter: parent.verticalCenter
                anchors.left: parent.left
                anchors.leftMargin: 9

                Image {
                    id: img;
                    source: food_img;
                    anchors.fill: parent;
                    asynchronous: true;
                    fillMode: Image.PreserveAspectFit;
                }

                MouseArea {
                    id: testMouseArea
                    anchors.fill: parent
                }
            }

            Text {
                id:food_name_id;
                text: food_name_txt;
                anchors.top: parent.top;
                anchors.topMargin: 16;
                anchors.left:img_rect.right;
                anchors.leftMargin: 16;
            }

            Text {
                id:food_price;
                text: food_price_txt;
                anchors.left: img_rect.right;
                anchors.leftMargin: 16;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 16;
            }

            Text {
                text: food_detail_txt;
                anchors.verticalCenter:  parent.verticalCenter;
                anchors.left: food_name_id.right;
                anchors.leftMargin: 10;
                color: listView.currentIndex == index ? "red" : ""
            }

            Rectangle {
                width: parent.width
                height: 1
                color: "gray"
                anchors.bottom: parent.bottom
            }
            Button{
                text: "+";
                width: 50;
                height: 25;
                background: Rectangle{
                    anchors.fill: parent;
                    color: "lightblue";
                }

                anchors.right: parent.right;
                anchors.top: parent.top;
                anchors.topMargin:  10;
                onClicked: {
                    signal_add(food_name_id.text,food_price.text);
                }

            }
            Button{
                text: "-";
                width: 50;
                height: 25;
                background: Rectangle{
                    anchors.fill: parent;
                    color: "lightblue";
                }
                anchors.right: parent.right;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 10;
                onClicked: {
                    signal_devide(food_name_id.text,food_price.text);
                }
            }

            onContentRectangleClicked: {
                // TODO something
                console.log("loader the type name is : "+component_list_view.model_name)
            }
        }

    }

    ListModel{
        id:dataModel;
    }

    function initDataModel(model_name)
    {
        //预先data
        for (var i=0; i<5; ++i) {
            dataModel.append({"food_name_txt": "鱼香肉丝", "food_price_txt": i *10,"food_desc_txt":"利用。。。。。。","food_img":"http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg"})
        }
    }

    Component.onCompleted: {
        initDataModel(model_name);
    }


}
