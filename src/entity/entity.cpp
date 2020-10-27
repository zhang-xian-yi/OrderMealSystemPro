#include "entity.h"

Entity::Entity(QVariantList data) : _data(data){

}


Entity::Entity(){

}



QVariantList Entity::data() const {
    return _data;
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



void Entity::clear()
{
    this->_data.clear();
}

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

bool Entity::empty() const
{
    return _data.empty();
}
