#ifndef OM_CCS_CCSPRIVATE_H
#define OM_CCS_CCSPRIVATE_H
#include "../om_common/datastruct/datastructs.h"

class IDao;
class BaseStruct;
class EntityList;
class CCSPrivate
{
public:
    explicit CCSPrivate();
    ~CCSPrivate();
    //处理登录的业务逻辑
    ParameterData handleLoginService(const BaseStruct* fromUi);
    BaseStruct* handleModelRequest(const ParameterData& request);
private:
    //获取配置文件的 mysql 配置信息
    ParameterData getMysqlConfigData();
private:
    IDao* m_pDao;
};

#endif // OM_CCS_CCSPRIVATE_H
