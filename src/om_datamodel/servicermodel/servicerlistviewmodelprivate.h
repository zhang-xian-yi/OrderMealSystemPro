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
    bool setDataSource(const QList<Entity>& dataSource );
public:
    //base func
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    int rowCount(const QModelIndex &parent) const;
    QHash<int, QByteArray> roleNames() const;
public:
    QList<Entity> m_contexts;
};

#endif // OM_DATAMODEL_SERVICERlISTVIEWMODELPRIVATE_H
