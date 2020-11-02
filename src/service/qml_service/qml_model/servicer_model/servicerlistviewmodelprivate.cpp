#include "servicerlistviewmodelprivate.h"

ServicerListviewModelPrivate::ServicerListviewModelPrivate()
{

}

/*
 析构函数 释放保存的字符串记录
 */
ServicerListviewModelPrivate::~ServicerListviewModelPrivate()
{
    if(m_contexts.size() > 0 )
    {
        m_contexts.clear();
    }
}


/*
input: model index   标记需要获取Listview的数据 的 index
input： role 标记需要获取的键值对中的 role 所对应的role

返回一个 联合内存 空间 所保存的具体字符串
注意 这里QVariant 所标记的联合体 可以存放任何类型的数据  但在这里其实是字符串
role 所对应的值 被直接存储在userrole之后
字符串存储是  二维数组  一位表示listview 所存放的记录数
二维所存放的就是 每一行记录中 按照所对应枚举  0 1 2 3 按照该顺序 所存放的字符串
 */
QVariant ServicerListviewModelPrivate::data(const QModelIndex &index, int role ) const
{
    if (! index.isValid())
    {
        return QVariant();
    }
    QVariant ret;
    switch (role)
    {
        case ServicerModelSpace::FoodName:
            ret = m_contexts.at(index.row()).at(ServicerModelSpace::Name_index);
            break;
        case ServicerModelSpace::FoodPrice:
            ret = m_contexts.at(index.row()).at(ServicerModelSpace::Price_index);
            break;
        case ServicerModelSpace::FoodDetail:
            ret = m_contexts.at(index.row()).at(ServicerModelSpace::Desc_index);
            break;
        case ServicerModelSpace::FoodImgUrl:
            ret = m_contexts.at(index.row()).at(ServicerModelSpace::ImgUrl_index);
            break;
        default:
            break;
    }
    return ret;
}


/*
    返回hash 数组
    保存的是  qml ui 需要显示的唯一text 标记  和这里c++类中 所对应的role 相关
*/
QHash<int, QByteArray> ServicerListviewModelPrivate::roleNames() const
{
    static bool flag = false;

    static QHash<int, QByteArray> roles;
    if(! flag)
    {
        roles.insert(ServicerModelSpace::FoodName, "food_name_txt");
        roles.insert(ServicerModelSpace::FoodPrice, "food_price_txt");
        roles.insert(ServicerModelSpace::FoodDetail, "food_detail_txt");
        roles.insert(ServicerModelSpace::FoodImgUrl,"food_img");
        flag = true;
    }
    return roles;
}


int ServicerListviewModelPrivate::rowCount(const QModelIndex &parent) const
{
    return m_contexts.size();
}

bool ServicerListviewModelPrivate::getDataFromMysql()
{
    //清空数据 保证每个界面的数据都会实时更新
    m_contexts.clear();

    Entity item(QVariantList() << QVariant("鱼香肉丝") << QVariant("15")<<QVariant("利用xxxxxx")<< QVariant("http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg")<<1 );
    Entity item1(QVariantList() << "心痛水" << "88"<<"喝下必定心痛"<<"http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg"<<2);
    Entity item2(QVariantList() << "甜皮鸭" << "15"<<"一直骑着皮皮虾的甜皮鸭"<<"http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg"<<3);
    Entity item3(QVariantList() << "最后的火焰神迹" << "9"<<"让人体会到什么是火焰神迹"<<"http://www.zhangxianyi4work.work:8088/orderSys/food/hgr.jpg"<<4);
    m_contexts.push_back(item);
    m_contexts.push_back(item1);
    m_contexts.push_back(item2);
    m_contexts.push_back(item3);
    return true;
}
