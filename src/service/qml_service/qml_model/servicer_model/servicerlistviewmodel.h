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
    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;
signals:
    void writeData(const QString& data);
private slots:
    void updateData();
private:
    ServicerListviewModelPrivate* m_service;
    QString name_id;
};

#endif // SERVICERLISTVIEWMODEL_H
