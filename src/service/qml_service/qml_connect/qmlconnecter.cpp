#include "qmlconnecter.h"
#include "global.h"

QMLCmdConnecter::QMLCmdConnecter(QObject *parent) :
    QObject(parent)
{
    init();
}

bool QMLCmdConnecter::init()
{
    m_app_run = true;
    return true;
}

void QMLCmdConnecter::handleCmd(const int &cmd,const QString& content)
{
    DEBUG_CONNECT("connect/stop app signal had recv %d",cmd);


}

