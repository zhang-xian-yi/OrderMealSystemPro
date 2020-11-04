#include "isystem.h"

ISystem::ISystem()
{
    initContext();
}

ISystem::~ISystem()
{
    if(nullptr != m_cmd_connect)
    {
        delete m_cmd_connect;
        m_cmd_connect = nullptr;
    }
    if(nullptr != m_qml_engine)
    {
        delete m_qml_engine;
        m_qml_engine = nullptr;
    }
}

QMLCmdConnecter *ISystem::getCmdConnect() const
{
    return this->m_cmd_connect;
}

bool ISystem::initContext()
{
    /*注册对象必须放在初始化 QML 上下文环境之前 */
    m_cmd_connect = new QMLCmdConnecter();
    m_qml_engine = new QQmlApplicationEngine();
    m_qml_engine->rootContext()->setContextProperty("CmdConnecter",m_cmd_connect);
    return true;
}
