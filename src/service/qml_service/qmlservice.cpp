#include "qmlservice.h"
#include <QUrl>
#include <QQmlContext>
#include <QQmlEngine>

#include "global.h"
#include "publicenum.h"
#include "confighelperutil.h"
#include "qml_model/modelfactory.h"
#include "qml_model/servicer_model/servicerlistviewmodel.h"

QMLService::QMLService()
{
    initQMLUI();
}

QMLService::~QMLService()
{
    if(! m_model_list.empty())
    {
        foreach(QAbstractListModel* item,m_model_list)
        {
            delete item;
            m_model_list.removeAll(item);
        }
    }
    m_model_list.clear();
    if(nullptr != m_cmd_connect)
    {
        delete m_cmd_connect;
        m_cmd_connect = nullptr;
    }
    if(nullptr != m_qml_view)
    {
        m_qml_view->setSource(QUrl(""));
        delete m_qml_view;
        m_qml_view = nullptr;
    }
}



bool QMLService::initQMLUI()
{
    /*设置服务人员QML 所必须的 5个 listview model 的全局对象*/
    init5TypeData();
    /*注册对象必须放在初始化 QML 上下文环境之前 */
    m_cmd_connect = new QMLCmdConnecter();
    m_qml_view = new QQuickView();
    m_qml_view->engine()->rootContext()->setContextProperty("CmdConnecter",m_cmd_connect);

    //注册 数据对象到qml 全局环境
    QList<QString> str_list = ConfigHelperUtil::getInstance().getValue("QMLConfig","food_model").split(',');
    for(int i = 0;i<m_model_list.length();++i)
    {
        m_qml_view->engine()->rootContext()->setContextProperty(str_list[i],dynamic_cast<ServicerListviewModel*>(m_model_list.at(i)) );
    }

    return true;
}

bool QMLService::init5TypeData()
{
    QList<QString> str_list = ConfigHelperUtil::getInstance().getValue("QMLConfig","food_tar").split(',');
    /*将servicelistviewmodel  和其 基类全部注册到工厂模板中 */
    ModelRegistrar<QAbstractListModel,ServicerListviewModel> listmodel_register(ModelTypeSpace::SERVICE_LISTVIEW_MODEL);
    for(int i = 0;i<str_list.length();++i)
    {
        /*通过工厂模板生产该对象*/
        QAbstractListModel* tmp = ModelFactory<QAbstractListModel>::getInstance().createModelBean(ModelTypeSpace::SERVICE_LISTVIEW_MODEL);
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

bool QMLService::initServicerContext()
{
    /*不在事件循环中 必须通过view 加载*/
    m_qml_view->setResizeMode(QQuickView::SizeRootObjectToView);
    m_qml_view->setSource(QUrl("qrc:/src/ui/servicer/servicer.qml"));
    if(nullptr == m_qml_view->rootObject())
    {
        return false;
    }
    m_qml_view->show();
    return true;
}
