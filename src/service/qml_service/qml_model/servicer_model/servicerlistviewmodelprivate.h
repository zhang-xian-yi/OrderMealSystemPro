#ifndef SERVICERlISTVIEWMODELPRIVATE_H
#define SERVICERlISTVIEWMODELPRIVATE_H

#include <QAbstractListModel>
#include <QList>
#include "entity.h"

class ServicerListviewModelPrivate
{
public:
    enum ModelRoles {
        FoodName = Qt::UserRole + 1,
        FoodPrice,
        FoodDesc,
        FoodImgUrl
    };

    enum EntityIndex{
        Name_index = 0,
        Price_index,
        Desc_index,
        ImgUrl_index,
        Type_index
    };

    explicit ServicerListviewModelPrivate();
    ~ServicerListviewModelPrivate();
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const ;
    int rowCount(const QModelIndex &parent) const;
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole);
    // Editable:
    QHash<int, QByteArray> roleNames() const;
    Qt::ItemFlags flags(const QModelIndex& index) const;
    bool getDataFromMysql();
public:
    QList<Entity> m_contexts;
};

#endif // SERVICERLISTVIEWMODELPRIVATE_H
