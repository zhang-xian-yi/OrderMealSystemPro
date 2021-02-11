#ifndef OM_DATABASES_ENTITY_H
#define OM_DATABASES_ENTITY_H

#include <QVariant>
#include <QVariantList>
#include "../commoninc/commoninterface.h"

#include <QtCore/qglobal.h>
#if defined(OM_COMMON_LIBARAY)
#  define OM_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define OM_COMMON_EXPORT Q_DECL_IMPORT
#endif

//存储 所有的返回类型数据
class OM_COMMON_EXPORT Entity:public BaseStruct
{
public:
    explicit Entity();
    Entity(QVariantList data);
    Entity(QStringList data);
    Entity(const Entity& data);
    QVariantList getData() const;
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

class OM_COMMON_EXPORT EntityList:public BaseStruct
{
public:
    explicit EntityList();
    explicit EntityList(const QList<Entity>& data);
    const QList<Entity>& getEntityList()const;
    void setEntityList(const QList<Entity>& data);
private:
    QList<Entity> m_entityList;
};



#endif // OM_DATABASES_ENTITY_H
