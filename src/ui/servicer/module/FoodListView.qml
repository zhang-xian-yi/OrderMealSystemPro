import QtQuick 2.0
import "../../qmlpublic/component/"
//import cn.qt.model 1.0

Item{
    id:component_list_view
    visible: true;
    implicitWidth:  360;
    implicitHeight: 360;

    property string type_name: null;

    function initListView()
    {

    }


    ListView {
        id: listView
        anchors.fill: parent;
        //model: ServicerListviewModel;
        model: testModel;
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
                text: food_price_txt;
                anchors.left: img_rect.right;
                anchors.leftMargin: 16;
                anchors.bottom: parent.bottom;
                anchors.bottomMargin: 16;
            }

            Text {
                text: food_desc_txt;
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
            onContentRectangleClicked: {
                // TODO something
                console.log("loader the type name is : "+component_list_view.type_name)
            }
        }

    }



    ListModel{
        id:testModel;
    }

    Component.onCompleted: {
        // test data
        for (var i=0; i<5; ++i) {
            testModel.append({"food_name_txt": "鱼香肉丝", "food_price_txt": i *10,"food_desc_txt":"利用。。。。。。","food_img":"http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg"})
        }
    }


}
