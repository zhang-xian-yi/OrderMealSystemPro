#include "qmlconnecter.h"
#include "../om_common/commoninc/debugdefine.h"

QMLCmdConnecter::QMLCmdConnecter(QObject *parent) :
    QObject(parent)
{

}



void QMLCmdConnecter::handleCmd(const int &cmd,const QString& content)
{
    DEBUG_CONNECT("connecter recv %d,content: %s",cmd,content.toStdString().c_str());
    switch (cmd)
    {
        case CmdTypeSpace::Servicer_Submit_FoodList:
        {
            QString table_num = content.section('`',0,0);
            emit signalSubmitFoodList(content);
            DEBUG_CONNECT("table_num  %d",table_num.toInt());
            break;
        }
    }
}

