#include "datastructs.h"
/***************************************************************************************
*
*数据库配置文件信息存储结构
****************************************************************************************/
ParameterData::ParameterData()
{
    m_parameterDataMap.clear();
}
/**
* @brief: 创建map 的时候 构建一对键值对
* @param：
* @return:
* @date: 2021-02-15
*/
ParameterData::ParameterData(const QString &key, const QString &value)
{
    appendItem(key,value);
}
/**
* @brief: 增加一个 键值对
* @param：key 键
*         value  值
* @return: void
* @date: 2021-02-03
*/
void ParameterData::appendItem(const QString &key, const QString &value)
{
    m_parameterDataMap.insert(key,value);
}

QString ParameterData::getValue(const QString &key) const
{
    if(m_parameterDataMap.contains(key))
    {
        return m_parameterDataMap[key];
    }
    return "";
}
/**
* @brief: 判断该数据是否合法
* @param：
* @return:
* @date: 2021-01-18
*/
bool ParameterData::isVaild()
{
    return !m_parameterDataMap.isEmpty();
}

void ParameterData::clear()
{
    this->m_parameterDataMap.clear();
}

/***************************************************************************************
*
*ParameterDataList
****************************************************************************************/

ParameterDataList::ParameterDataList()
{
    m_paraDataList.clear();
}

ParameterDataList::~ParameterDataList()
{
    m_paraDataList.clear();
}

void ParameterDataList::addItem(const ParameterData &item)
{
    m_paraDataList.append(item);
}

const QList<ParameterData> &ParameterDataList::getDataList() const
{
    return m_paraDataList;
}
