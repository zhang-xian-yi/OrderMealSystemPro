#include "servicerchildsystem.h"
//配置文件解析工具
#include "../om_common/utils/confighelperutil/confighelperutil.h"
//模板工厂
#include "../common/beanfactory.h"
//model 的详细信息
#include "servicermodel/servicerlistviewmodel.h"
#include "../om_common/commoninc/debugdefine.h"
#include "../om_common/datastruct/datastructs.h"
#include "../om_ui/servicerui/servicergui.h"

ServicerChildSystem::ServicerChildSystem()
{
    m_qmlEngine = new QQmlApplicationEngine;
    //此处初始化 发出的信号很可能还无法连接到具体槽函数  所以需要外部初始化
    //initModelData();
}

ServicerChildSystem::~ServicerChildSystem()
{
    stopSystem();
    foreach(QAbstractListModel* tmp,m_modelList)
    {
        delete tmp;
    }
    m_modelList.clear();
}
/**
* @brief: 启动 子系统
* @param：
* @return:
* @date: 2021-02-16
*/
bool ServicerChildSystem::startSystem()
{
    m_qmlEngine->load(QStringLiteral("qrc:/src/om_ui/servicerui/servicer.qml"));
    if(! m_qmlEngine->rootObjects().empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
* @brief: 停止子系统运行
* @param：
* @return:
* @date: 2021-02-16
*/
bool ServicerChildSystem::stopSystem()
{
    m_qmlEngine->load(QStringLiteral(""));
    if(! m_qmlEngine->rootObjects().empty())
    {
        return true;
    }
    else
    {
        return false;
    }
}
/**
* @brief: 将数据 设置进入model 中
* @param：
* @return:
* @date: 2021-02-16
*/
void ServicerChildSystem::slotFromDatabaseFood(const QString &type, const EntityList &list)
{
    //遍历 数据源 提取与 type 一样的数据source
    foreach(QAbstractListModel* tmp,m_modelList)
    {
        ServicerListviewModel* list_view_model = dynamic_cast<ServicerListviewModel*>(tmp);
        if(nullptr != list_view_model)
        {
            //初始化数据源
            if(type == list_view_model->getNameId())
            {
                list_view_model->setDataSource(list);
                //设置 数据进入元对象系统中  数据与 qml 数据文件匹配 由qml引擎对应
                m_qmlEngine->rootContext()->setContextProperty(type+"_model",dynamic_cast<ServicerListviewModel*>(tmp) );
            }
        }
    }
}
/**
* @brief: 初始化 model 的数据
* @param：
* @return:
* @date: 2021-02-16
*/
void ServicerChildSystem::initModelData()
{
    //配置文件中的某个具体信息
    QList<QString> str_list = ConfigHelperUtil::getInstance()->getValue("QMLConfig","food_tar").split(',');
    /*循环注册 service 对象进入 元对象系统*/
    for(int i = 0;i<str_list.length();++i)
    {
        /*通过工厂模板生产该对象*/
        QAbstractListModel* tmp = BeanFactory<QAbstractListModel>::getInstance().createBean("ServicerListviewModel");
        /*保存指针*/
        m_modelList.append(tmp);
        ServicerListviewModel* list_view_model = dynamic_cast<ServicerListviewModel*>(tmp);
        //设置数据源  数据库返回的是 EntityList   通过信号与槽 与 application 进行 数据源的交互
        list_view_model->setNameId(str_list[i]);
        //发送信号
        emit signalGetFoodDataByType(ParameterData("type",str_list[i]));
    }
    DEBUG_SERVICE("name:%s",str_list[0].toStdString().c_str());
}
