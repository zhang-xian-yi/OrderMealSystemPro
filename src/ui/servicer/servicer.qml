﻿import QtQuick 2.7
import QtQuick.Window 2.3
import QtQuick.Controls 2.4
import "./module/"
import "../qmlpublic/"

Rectangle{
    id:root;
    color: "gray";
    width: 640;
    height: 480;
    property var food_list: [];
    SlidesShow{
        id:seat_num_bg;
        height: parent.height*0.2;
        width: parent.width;
        onSignal_submit_clicked: {
            //console.log("table num:"+table_num);
        }
    }

    FoodTabView{
        id:food_tab;
        anchors.top:seat_num_bg.bottom;
        anchors.bottom: parent.bottom;
        anchors.left: parent.left;
        anchors.right: parent.right;
    }

    Component.onCompleted: {
        //CmdConnecter.handleCmd(normal_exit);
    }

}
