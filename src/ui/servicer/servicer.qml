import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import "../qmlpublic/component/"
import "./module/"


ApplicationWindow{
    id: frmWindow;
    visible: true;
    width: 800;
    height: 400;
    //以当前路径 为图片相对路径的起始点
    property var icons:[":../../../../../../appfile/images/qmlicons/drink.png",
                        ":../../../../../../appfile/images/qmlicons/meat.png",
                        ":../../../../../../appfile/images/qmlicons/noodles.png",
                        ":../../../../../../appfile/images/qmlicons/soup.png",
                        ":../../../../../../appfile/images/qmlicons/vegetable.png"];
    property var food_list: [];

    header: ZBaseTabBar{
        id: bar;
        height: 48;
        width: parent.width;
        Component.onCompleted: {
            tabBarModel.append({ "modelText": "酒水", "modelColor": "#000000", "modelColorG": "#148014", "modelSrc": icons[0], "modelSrcG": icons[0]})
            tabBarModel.append({ "modelText": "肉食", "modelColor": "#000000", "modelColorG": "#148014", "modelSrc": icons[1], "modelSrcG": icons[1]})
            tabBarModel.append({ "modelText": "面食", "modelColor": "#000000", "modelColorG": "#148014", "modelSrc": icons[2], "modelSrcG": icons[2]})
            tabBarModel.append({ "modelText": "汤类", "modelColor": "#000000", "modelColorG": "#148014", "modelSrc": icons[3], "modelSrcG": icons[3]})
            tabBarModel.append({ "modelText": "蔬菜", "modelColor": "#000000", "modelColorG": "#148014", "modelSrc": icons[4], "modelSrcG": icons[4]})
        }
    }

    SwipeView {
        id: swipe_view;
        height: frmWindow.height - bar.height - seat_num_bg.height;
        width: parent.width;
        currentIndex: bar.currentIndex;
        FoodListView{
            id:drink_list_view;
            model_name: drink_model;
        }

        FoodListView{
            id:meat_list_view;
            model_name: meat_model;
        }

        FoodListView{
            id:noodles_list_view;
            model_name: noodles_model;
        }


        FoodListView{
            id:soup_list_view;
            model_name: soup_model;
        }


        FoodListView{
            id:vagetable_list_view;
            model_name: vegetable_model;
        }
    }

    footer:SlidesShow{
        id:seat_num_bg;
        height: frmWindow.height*0.2;
        width: frmWindow.width;
        Text {
            id: food_list;
            text: qsTr("鱼香肉丝");
        }
        onSignal_submit_clicked: {
            console.log("choose table num:"+table_num);
        }
    }
}
