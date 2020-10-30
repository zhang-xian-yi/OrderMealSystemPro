#关于数据库的其他服务
include($$PWD/sql_service/sql_service.pri)
#关于qml的其他服务
include($$PWD/qml_service/qml_service.pri)


INCLUDEPATH += $$PWD/

HEADERS += \
    $$PWD/sysservicecontrol.h

SOURCES += \
    $$PWD/sysservicecontrol.cpp






