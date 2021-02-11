#ifndef OM_DATAMODEL_COMMON_H
#define OM_DATAMODEL_COMMON_H


#include "beanfactory.h"


#define REGISTRY_DATA_LIST_MODEL(class_name)\
    class registry_##class_name{\
    public: \
    registry_##class_name(){\
    new BeanRegistrar<QAbstractListModel,class_name>(#class_name);\
    }\
    }; registry_##class_name registry_##class_name##_instance;


#endif //OM_DATAMODEL_COMMON_H
