#ifndef SERVICERLISTVIEWMODEL_H
#define SERVICERLISTVIEWMODEL_H
#include <QModelIndex>
#include <QAbstractListModel>
class ServicerListviewModelPrivate;

class ServicerListviewModel:public QAbstractListModel
{
public:
    explicit ServicerListviewModel(QObject *parent = nullptr);
    ~ServicerListviewModel()override;
    void setNameId(const QString& name);
    void initByNameId();
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

#endif // SERVICERLISTVIEWMODEL_H
