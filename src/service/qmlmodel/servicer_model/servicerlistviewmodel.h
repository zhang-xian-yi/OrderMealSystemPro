#ifndef SERVICERLISTVIEWMODEL_H
#define SERVICERLISTVIEWMODEL_H
#include "model.h"
#include <QModelIndex>

class ServicerListviewModelPrivate;

class ServicerListviewModel:public QAbstractListModel
{
public:
    explicit ServicerListviewModel(QObject *parent = nullptr);
    ~ServicerListviewModel()override;

    // Basic functionality:
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // Editable:
    bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) override;
    Qt::ItemFlags flags(const QModelIndex& index) const override;

    Q_INVOKABLE void doLog(const QString& msg)const;
signals:
    void writeData(const QString& data);
private slots:
    void updateData();
private:
    ServicerListviewModelPrivate* m_service;
};

#endif // SERVICERLISTVIEWMODEL_H
