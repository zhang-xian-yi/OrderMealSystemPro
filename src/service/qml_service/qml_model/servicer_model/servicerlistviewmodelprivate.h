#ifndef SERVICERlISTVIEWMODELPRIVATE_H
#define SERVICERlISTVIEWMODELPRIVATE_H

#include <QAbstractListModel>
#include <QList>
#include "entity.h"
#include "mysql/mysqloper.h"

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

class ServicerListviewModelPrivate
{
public:
    explicit ServicerListviewModelPrivate();
    ~ServicerListviewModelPrivate();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    int rowCount(const QModelIndex &parent) const;
    bool getDataFromMysql();

    QHash<int, QByteArray> roleNames() const;
public:
    QList<Entity> m_contexts;
};

#endif // SERVICERLISTVIEWMODELPRIVATE_H
