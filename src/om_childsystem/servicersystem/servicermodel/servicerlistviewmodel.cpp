#include "servicerlistviewmodel.h"
#include "servicerlistviewmodelprivate.h"
#include "common/commondefines.h"
#include "../om_common/commoninc/debugdefine.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_common/datastruct/databasesentity.h"



ServicerListviewModel::ServicerListviewModel(QObject *parent):
    QAbstractListModel(parent),
    m_service(new ServicerListviewModelPrivate())
{

}

ServicerListviewModel::~ServicerListviewModel()
{
    if(nullptr != m_service)
    {
        delete m_service;
    }
}
/**
* @brief: 获取数据的  类型 type
* @param：
* @return:
* @date: 2021-02-15
*/
QString ServicerListviewModel::getNameId() const
{
    return m_service->getNameId();
}
/**
* @brief: 设置 nameId
* @param：
* @return:
* @date: 2021-02-08
*/
void ServicerListviewModel::setNameId(const QString &name)
{
    m_service->setNameId(name);
}
/**
* @brief: 设置数据源
* @param：
* @return:
* @date: 2021-02-15
*/
void ServicerListviewModel::setDataSource(const EntityList &data)
{
    m_service->setDataSource(data.getEntityList());
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

REGISTRY_DATA_LIST_MODEL(ServicerListviewModel)


