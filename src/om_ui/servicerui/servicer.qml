import QtQuick 2.7
import QtQuick.Controls 1.4
import QtQuick.Controls.Styles 1.4
import QtQuick.Controls 2.0
import QtQuick.Layouts 1.0
import QtQuick.Window 2.2
import "./component/"
import "./module/"


ApplicationWindow{
    id: frmWindow;
    visible: true;
    width: 800;
    height: 400;

    property var food_list: {"茶水":1}
    readonly property int submit_foods: 1;
    signal signal_update_food_list();

    header: ZBaseTabBar{
        id: bar;
        height: 48;
        width: parent.width;
        //以当前路径 为图片相对路径的起始点
        property var icons:[":../../../../../../appfile/images/qmlicons/drink.png",
                            ":../../../../../../appfile/images/qmlicons/meat.png",
                            ":../../../../../../appfile/images/qmlicons/noodles.png",
                            ":../../../../../../appfile/images/qmlicons/soup.png",
                            ":../../../../../../appfile/images/qmlicons/vegetable.png"];

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
            onSignal_add: {
                handleAddFood(name,price_value);
            }
            onSignal_devide: {
                handleDelFood(name,price_value);
            }
        }

        FoodListView{
            id:meat_list_view;
            model_name: meat_model;
            onSignal_add: {
                handleAddFood(name,price_value);
            }
            onSignal_devide: {
                handleDelFood(name,price_value);
            }
        }

        FoodListView{
            id:noodles_list_view;
            model_name: noodles_model;
            onSignal_add: {
                handleAddFood(name,price_value);
            }
            onSignal_devide: {
                handleDelFood(name,price_value);
            }
        }

        FoodListView{
            id:soup_list_view;
            model_name: soup_model;
            onSignal_add: {
                handleAddFood(name,price_value);
            }
            onSignal_devide: {
                handleDelFood(name,price_value);
            }
        }

        FoodListView{
            id:vagetable_list_view;
            model_name: vegetable_model;
            onSignal_add: {
                handleAddFood(name,price_value);
            }
            onSignal_devide: {
                handleDelFood(name,price_value);
            }
        }
    }

    footer:SlidesShow{
        id:seat_num_bg;
        height: frmWindow.height*0.2;
        width: frmWindow.width;
        property int total_price_value: 0;
        Rectangle{
            Text {
                id: list_lable;
                text: "餐品列表";
                anchors.left: parent.left;
                anchors.top: parent.top;
            }
            Text {
                id: food_list_id;
                anchors.left: list_lable.right;
                anchors.top: list_lable.top;
            }
        }
        Rectangle{
            anchors.centerIn: parent;
            anchors.leftMargin:  - total_price_lab.width;
            anchors.topMargin: - total_price_lab.height;
            Text {
                id: total_price_lab;
                text: "总计: ";
                color: "black";
                font.pointSize: 24;
            }
            Text {
                id: total_price;
                anchors.left: total_price_lab.right;
                anchors.leftMargin: 4;
                color: "black";
                font.pointSize: 24;
                text: seat_num_bg.total_price_value;
            }
        }

        onSignal_submit_clicked: {
            CmdConnecter.handleCmd(submit_foods,table_num+'`'+displayFoodList());
        }
    }


    function displayFoodList()
    {
        var food_str;
        for(var key in food_list)
        {
            food_str += key;
            food_str += ":"
            food_str += food_list[key];
            food_str += ',';
        }
        return food_str.replace("undefined","");
    }

    function handleAddFood(name,price_value)
    {
        //判断对象是否未定义
        if( typeof food_list[name] === "undefined")
        {
            food_list[name] = 1;
        }
        else
        {
            food_list[name] = food_list[name] + 1;
        }

        //console.log("foodlist["+name+"]:"+food_list[name]);
        seat_num_bg.total_price_value += Number(price_value);
        signal_update_food_list();
    }

    function handleDelFood(name,price_value)
    {
        //判断对象是否未定义
        if( typeof food_list[name] === "undefined")
        {
            food_list[name] = 0;
            delete food_list[name];
        }
        else
        {
            food_list[name] = food_list[name] - 1;
        }
        //console.log("foodlist["+name+"]:"+food_list[name]);
        seat_num_bg.total_price_value -= Number(price_value);
        signal_update_food_list();
    }

    onSignal_update_food_list: {
        food_list_id.text = displayFoodList();
    }
}
