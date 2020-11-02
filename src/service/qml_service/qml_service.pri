#数据模块 qml 的model 类
include($$PWD/qml_model/qml_model.pri)
#关于qml 与c++ 进行命令式数据交互的 注册类
include($$PWD/qml_connect/qml_connect.pri)
#关于qml 子系统 的服务
include($$PWD/qml_system/qml_system.pri)

HEADERS += \
    $$PWD/qmlservice.h \
    $$PWD/beanfactory.h

SOURCES += \
    $$PWD/qmlservice.cpp

