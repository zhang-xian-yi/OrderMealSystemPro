
#关于处理从QML 传递过来的 命令/数据 的处理模块 应该单独存在
include($$PWD/qml_data_handle/qml_data_handle.pri)

HEADERS += \
    $$PWD/qmlconnecter.h

SOURCES += \
    $$PWD/qmlconnecter.cpp
