#ifndef OM_COMMON_DATABASES_H
#define OM_COMMON_DATABASES_H

#include <QVariant>
#include <QVariantList>
#include "../commoninc/commoninterface.h"

#include <QtCore/qglobal.h>
#if defined(OM_COMMON_LIBARAY)
#  define OM_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define OM_COMMON_EXPORT Q_DECL_IMPORT
#endif

#include <QMap>
//保存数据库必要信息的数据结构
class OM_COMMON_EXPORT ParameterData:public BaseStruct
{
public:
    explicit ParameterData();
    explicit ParameterData(const QString& key,const QString& value);
    //插入一个键值对
    void appendItem(const QString& key,const QString& value);
    //通过键名 获取值
    QString getValue(const QString& key)const;
    bool isVaild();
    void clear();
private:
    QMap<QString,QString> m_parameterDataMap;
};

//参数化容器列表
class OM_COMMON_EXPORT ParameterDataList:public BaseStruct
{
public:
    explicit ParameterDataList();
    ~ParameterDataList();
    //增加一个 ParameterData 对象
    void addItem(const ParameterData& item);
    //根据下标回去一个引用对象
    const QList<ParameterData>& getDataList()const;
private:
    QList<ParameterData> m_paraDataList;
};

#endif // OM_COMMON_DATABASES_H
