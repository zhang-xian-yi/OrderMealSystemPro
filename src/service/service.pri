
#数据模块 qml 的model 类
include($$PWD/qmlmodel/qmlmodel.pri)
#关于数据库的其他服务
include($$PWD/sql_service/sql_service.pri)


INCLUDEPATH += $$PWD/

HEADERS += \
    $$PWD/sysservicecontrol.h

SOURCES += \
    $$PWD/sysservicecontrol.cpp






