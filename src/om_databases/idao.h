#ifndef OM_DATABASES_IDAO_H
#define OM_DATABASES_IDAO_H
#include "../om_common/commoninc/commoninterface.h"

class IDao
{
public:
    enum DatabaseFlag
    {
        E_EMPLOYER_INFO = 0,
        E_FOOD_LIST_INFO
    };
    virtual ~IDao() = 0;
    //一般是 parameterData 数据结构类
    virtual BaseStruct* getData(const BaseStruct* iPara,int flag) = 0;
};
#endif // OM_DATABASES_IDAO_H
