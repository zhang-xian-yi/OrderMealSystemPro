#include "modelfactory.h"
#include "confighelperutil.h"
#include <QString>
#include "servicer_model/servicerlistviewmodel.h"
QAbstractItemModel* ModelFactory::getModelBean(const QString& name)const
{
    //获取配置文件中 关于model 的配置信息
    if("servicer" == name)
    {
        return new ServicerListviewModel;
    }
    return nullptr;
}
