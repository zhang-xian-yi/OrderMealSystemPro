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
* @brief: 设置 nameId
* @param：
* @return:
* @date: 2021-02-08
*/
void ServicerListviewModel::setNameId(const QString &name)
{
    this->type_id = name;
}

void ServicerListviewModel::setDataSource(const EntityList &dataSource)
{
    const QList<Entity> ret = dataSource.getEntityList();
    m_service->setDataSource(ret);
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


