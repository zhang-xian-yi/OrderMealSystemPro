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
    m_handle_qml_data = new HandleQMLDataContext;
    return true;
}

void QMLCmdConnecter::handleCmd(const int &cmd,const QString& content)
{
    DEBUG_CONNECT("connecter recv %d,content: %s",cmd,content.toStdString().c_str());
    switch (cmd)
    {
        case CmdTypeSpace::Servicer_Submit_FoodList:
        {
            QString table_num = content.section('`',0,0);
            DEBUG_CONNECT("table_num  %d",table_num.toInt());
            m_handle_qml_data->handleQMLServicerOrder(table_num,content.section('`',1));
            break;
        }
    }

}

