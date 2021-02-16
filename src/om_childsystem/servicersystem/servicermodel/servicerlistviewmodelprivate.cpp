#include "servicerlistviewmodelprivate.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_common/datastruct/databasesentity.h"


ServicerListviewModelPrivate::ServicerListviewModelPrivate()
{
    m_contexts.clear();
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
/**
* @brief: 获取数据 的 type
* @param：
* @return:
* @date: 2021-02-15
*/
QString ServicerListviewModelPrivate::getNameId() const
{
    return this->m_type;
}
/**
* @brief: 设置  数据 Type
* @param：
* @return:
* @date: 2021-02-14
*/
void ServicerListviewModelPrivate::setNameId(const QString &name)
{
    m_type = name;
}
/**
* @brief: 设置数据源  为 qml 界面访问的时候 的数据
* @param：
* @return:
* @date: 2021-02-15
*/
void ServicerListviewModelPrivate::setDataSource(const QList<Entity> &data)
{
    m_contexts = data;
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
