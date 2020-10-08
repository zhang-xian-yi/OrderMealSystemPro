#include "entity.h"

Entity::Entity(QVariantList data) : _data(data){

}

QVariantList Entity::data() const {
    return _data;
}

void Entity::setData(const QVariantList &data) {
    _data = data;
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
