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
    DEBUG_CONNECT("connecter recv %d,content: $s",cmd,content.toStdString().c_str());
    switch (cmd)
    {
        case CmdTypeSpace::Servicer_Submit_FoodList:
        {
            QList<QString> list = content.split('`');

            break;
        }
    }

}

