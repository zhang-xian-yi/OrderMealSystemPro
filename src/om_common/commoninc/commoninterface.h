#ifndef OM_COMMON_COMMONINTERFACE_H
#define OM_COMMON_COMMONINTERFACE_H

#include <QtCore/qglobal.h>
#if defined(OM_COMMON_LIBARAY)
#  define OM_COMMON_EXPORT Q_DECL_EXPORT
#else
#  define OM_COMMON_EXPORT Q_DECL_IMPORT
#endif

//用作本工程所有数据结构的最上级方便get and set
class OM_COMMON_EXPORT BaseStruct
{
public:
    virtual ~BaseStruct() = 0;
};

#endif // OM_COMMON_COMMONINTERFACE_H



