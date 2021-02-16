#ifndef OM_DATAMODEL_SERVICERlISTVIEWMODELPRIVATE_H
#define OM_DATAMODEL_SERVICERlISTVIEWMODELPRIVATE_H

#include <QAbstractListModel>
#include <QList>
#include "../om_common/datastruct/databasesentity.h"
//#include "mysql/mysqloper.h"

namespace  ServicerModelSpace{
enum ModelRoles {
    FoodName = Qt::UserRole + 1,
    FoodPrice,
    FoodDetail,
    FoodImgUrl
};

enum EntityIndex{
    Name_index = 0,
    Price_index,
    Desc_index,
    ImgUrl_index,
    Type_index
};
}
//预先声明 参数data
class ParameterDataList;

class ServicerListviewModelPrivate
{
public:
    explicit ServicerListviewModelPrivate();
    ~ServicerListviewModelPrivate();
    QString getNameId()const;
    void setNameId(const QString& name);
    void setDataSource(const QList<Entity>& data);
public:
    //base func
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
private:
    //源数据
    QList<Entity> m_contexts;
    //数据的类型
    QString       m_type;
};

#endif // OM_DATAMODEL_SERVICERlISTVIEWMODELPRIVATE_H
