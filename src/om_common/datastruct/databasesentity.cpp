#include "databasesentity.h"

Entity::Entity(QVariantList data) : _data(data){

}

Entity::Entity(QStringList data)
{
    setData(data);
}
/**
* @brief: 拷贝构造  方便解引用的时候 赋值  一般默认调用
* @param：
* @return:
* @date: 2021-01-19
*/
Entity::Entity(const Entity &data)
{
    this->_data = data.getData();
}
/**
* @brief: 获取成员百年来
* @param：
* @return:
* @date: 2021-01-18
*/
QVariantList Entity::getData() const
{
    return _data;
}


Entity::Entity(){

}

void Entity::setData(const QVariantList data) {
    _data = data;
}

void Entity::setData(const QStringList data)
{
    foreach(QString str,data)
    {
        this->_data<<str;
    }
}
/**
* @brief: 获取无法修改的对象应用
* @param：
* @return:
* @date: 2021-01-18
*/
const QVariant Entity::at(int i) const {
    if (i < _data.size() && i >= 0)
    {
        return _data.at(i);
    }
    else
    {
        return QVariant();
    }
}

QVariant &Entity::operator[](int i) {
    return _data[i];
}


/**
* @brief: 清理数据区域
* @param：
* @return:
* @date: 2021-01-18
*/
void Entity::clear()
{
    this->_data.clear();
}
/**
* @brief: 将数据字符串序列化
* @param：
* @return:
* @date: 2021-01-18
*/
QByteArray Entity::toString()const
{
    int length = _data.length();
    QByteArray ret;
    for(int i = 0;i<length;++i)
    {
        ret.push_back( _data.at(i).toByteArray() );
    }
    return ret;
}
/**
* @brief: 判断数据是否为空
* @param：
* @return:
* @date: 2021-01-18
*/
bool Entity::empty() const
{
    return _data.empty();
}

/***************************************************************************************
*
* entitylist
****************************************************************************************/

EntityList::EntityList()
{

}

EntityList::EntityList(const QList<Entity> &data)
{
    setEntityList(data);
}

const QList<Entity> &EntityList::getEntityList() const
{
    return this->m_entityList;
}

void EntityList::setEntityList(const QList<Entity> &data)
{
    this->m_entityList = data;
}


