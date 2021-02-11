#ifndef OM_DATAMODEL_SERVICERLISTVIEWMODEL_H
#define OM_DATAMODEL_SERVICERLISTVIEWMODEL_H
#include <QModelIndex>
#include <QAbstractListModel>
#include <QtCore/qglobal.h>
#if defined(OM_DATAMODEL_LIBARAY)
#  define OM_DATAMODEL_EXPORT Q_DECL_EXPORT
#else
#  define OM_DATAMODEL_EXPORT Q_DECL_IMPORT
#endif

class EntityList;
class ServicerListviewModelPrivate;

class OM_DATAMODEL_EXPORT ServicerListviewModel:public QAbstractListModel
{
public:
    explicit ServicerListviewModel(QObject *parent = nullptr);
    ~ServicerListviewModel()override;
    void setNameId(const QString& name);
    void setDataSource(const EntityList& dataSOurce);
    /* Basic functionality:*/
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    /*获取所对应的txt 的数据*/
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

protected:
    QHash<int, QByteArray> roleNames() const override;
private:
    ServicerListviewModelPrivate* m_service;
    QString type_id;
};

#endif // OM_DATAMODEL_SERVICERLISTVIEWMODEL_H
