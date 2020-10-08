#ifndef ENTITY_H
#define ENTITY_H



#include <QVariant>
#include <QVariantList>

class Entity
{
public:
    Entity(QVariantList data);

    QVariantList data() const;
    void setData(const QVariantList &data);
    const QVariant at(int i) const;
    QVariant& operator[] (int i);
private:
    QVariantList _data;
};

#endif // ENTITY_H
