#include "servicerlistviewmodel.h"
#include "servicerlistviewmodelprivate.h"
#include "global.h"
#include <QThread>

ServicerListviewModel::ServicerListviewModel(QObject *parent):
    QAbstractListModel(parent),
    m_service(new ServicerListviewModelPrivate)
{

    //初始化数据
    m_service->getDataFromMysql();
}

ServicerListviewModel::~ServicerListviewModel()
{
    if(nullptr != m_service)
    {
        delete m_service;
    }
}

void ServicerListviewModel::setNameId(const QString &name)
{
    this->name_id = name;
}

void ServicerListviewModel::initByNameId()
{
    m_service->getDataFromMysql();
}

int ServicerListviewModel::rowCount(const QModelIndex &parent) const
{
    return m_service->rowCount(parent);
}

QVariant ServicerListviewModel::data(const QModelIndex &index, int role) const
{
    return m_service->data(index,role);
}

QHash<int, QByteArray> ServicerListviewModel::roleNames() const
{
    return m_service->roleNames();
}




