#include <QApplication>
#include "../om_ui/loginui/logingui.h"
#include "../om_ui/igui.h"

#include "../om_databases/idao.h"
#include "../om_databases/mysql/mysqldaoimpl.h"

#include "../om_common/datastruct/databasesentity.h"
#include "../om_common/datastruct/datastructs.h"
#include "application/application.h"
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    OrderMealApplication* pApp =  OrderMealApplication::getInstance();
    pApp->startApplication();

//    IGui* login = new LoginGUI;
//    login->startGui();

//    ParameterData* pcfgData = new ParameterData;
//    pcfgData->appendItem("database_name","orderSys");
//    pcfgData->appendItem("hostname","www.zhangxianyi4work.work");
//    pcfgData->appendItem("port","3306");
//    pcfgData->appendItem("username","root");
//    pcfgData->appendItem("password","123456");

//    IDao* mysqlDao = new MysqlDaoImpl(pcfgData);

//    ParameterData paraData;
//    paraData.appendItem("type","meat");

//    BaseStruct* retData = mysqlDao->getData(&paraData,IDao::E_FOOD_LIST_INFO);
//    EntityList* pList = dynamic_cast<EntityList*>(retData);
//    delete pcfgData;
//    delete  pList;
//    delete mysqlDao;
    return app.exec();
}
