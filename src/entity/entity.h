#ifndef ENTITY_H
#define ENTITY_H



#include <QVariant>
#include <QVariantList>

class Entity
{
public:
    explicit Entity();
    Entity(QVariantList data);
    Entity(QStringList data);

    QVariantList data() const;
    void setData(const QVariantList data);
    void setData(const QStringList data);
    void clear();
    bool empty()const;
    //用于获取该数据 无法修改
    const QVariant at(int i) const;
    QByteArray toString()const;
    //用户修改该数据
    QVariant& operator[] (int i);
private:
    QVariantList _data;
};

#endif // ENTITY_H
