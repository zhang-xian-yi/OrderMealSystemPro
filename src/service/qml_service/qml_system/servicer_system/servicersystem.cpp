#include "servicersystem.h"


#include <QUrl>

#include "global.h"
#include "publicenum.h"
#include "confighelperutil/confighelperutil.h"
#include "qml_service/beanfactory.h"
#include "qml_service/qml_model/servicer_model/servicerlistviewmodel.h"

ServicerSystem::ServicerSystem()
{
    initServicerContext();
}

ServicerSystem::~ServicerSystem()
{
    stop();
}

/**
* @brief:  启动servicer 的子系统
* @param：
* @return:
* @date: 2020-11-02
*/
bool ServicerSystem::start()
{
    m_qml_engine->load(QStringLiteral("qrc:/src/ui/servicer/servicer.qml"));
    if(! m_qml_engine->rootObjects().empty())
    {
        return true;
    }
    else
    {
         return false;
    }
}

/**
* @brief:  停止servicer子系统
* @param：
* @return:
* @date: 2020-11-02
*/
bool ServicerSystem::stop()
{
    //先设置加载对象为空  之后释放c++ 数据内存
    bool ret = false;
    if(! m_qml_engine->rootObjects().empty())
    {
        ret = true;
    }
    else
    {
        ret = false;
    }

    if(! m_model_list.empty())
    {
        foreach(QAbstractListModel* item,m_model_list)
        {
            delete item;
            m_model_list.removeAll(item);
        }
    }
    m_model_list.clear();
    return ret;
}
/**
* @brief: 私有/ 初始化servicer 所有的上下文
* @param：
* @return:
* @date: 2020-11-02
*/
bool ServicerSystem::initServicerContext()
{
    /*设置服务人员QML 所必须的 5个 listview model 的全局对象*/
    inittypeData();
    //注册 数据对象到qml 全局环境
    QList<QString> str_list = ConfigHelperUtil::getInstance().getValue("QMLConfig","food_model").split(',');
    for(int i = 0;i<m_model_list.length();++i)
    {
        m_qml_engine->rootContext()->setContextProperty(str_list[i],dynamic_cast<ServicerListviewModel*>(m_model_list.at(i)) );
    }

    return true;
}


/**
* @brief:  初始化 服务员所需要的 5 个 C class 的数据原对象
* @param：
* @return:
* @date: 2020-11-02
*/
bool ServicerSystem::inittypeData()
{
    QList<QString> str_list = ConfigHelperUtil::getInstance().getValue("QMLConfig","food_tar").split(',');
    /*将servicelistviewmodel  和其 基类全部注册到工厂模板中 */
    BeanRegistrar<QAbstractListModel,ServicerListviewModel> listmodel_register(BeanTypeSpace::Servicer_Lisstview_Model);
    for(int i = 0;i<str_list.length();++i)
    {
        /*通过工厂模板生产该对象*/
        QAbstractListModel* tmp = BeanFactory<QAbstractListModel>::getInstance().createBean(BeanTypeSpace::Servicer_Lisstview_Model);
        /*保存指针*/
        m_model_list.append(tmp);
        ServicerListviewModel* list_view_model = dynamic_cast<ServicerListviewModel*>(tmp);
        list_view_model->setNameId(str_list[i]);
        list_view_model->initByNameId();
    }
    /*循环注册 service 对象进入 元对象系统*/
    DEBUG_SERVICE("name:%s",str_list[0].toStdString().c_str());
    return true;
}

