import QtQuick 2.7
import QtQuick.Window 2.3
import "./module/"

Rectangle{
    id:root;
    color: "gray";
    width: 640;
    height: 480;

    SlidesShow{
        id:seat_num_bg;
        height: parent.height*0.2;
        width: parent.width;
    }

    FoodTabView{
        id:food_tab;
        anchors.top:seat_num_bg.bottom;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }
}
