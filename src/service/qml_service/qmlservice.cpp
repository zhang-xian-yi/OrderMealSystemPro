#include "qmlservice.h"

#include "beanfactory.h"
#include "qml_system/servicer_system/servicersystem.h"

QMLService::QMLService()
{

}

QMLService::~QMLService()
{
    stopChildSystem();
    if(nullptr != m_child_system)
    {
        delete  m_child_system;
        m_child_system = nullptr;
    }
}

bool QMLService::startChildSystem()
{
    if(nullptr == m_child_system)
    {
        initContext();
    }
    return m_child_system->start();
}

bool QMLService::stopChildSystem()
{
    if(nullptr != m_child_system)
    {
        return m_child_system->stop();
    }
    return true;
}

void QMLService::setSystemType(const int& type)
{
    this->m_system_type = type;
    if(nullptr != m_child_system)
    {
        delete m_child_system;
        m_child_system = nullptr;
    }
    initContext();
}

bool QMLService::initContext()
{
    /*设置该类型的 模板工厂注册  防止创建对象的时候找不到*/
    BeanRegistrar<ISystem,ServicerSystem> servicer_register(SystemTypeSpace::Service_System);

    /*通过工厂生产对象*/
    m_child_system = BeanFactory<ISystem>::getInstance().createBean(this->m_system_type);
    return nullptr != m_child_system;
}

