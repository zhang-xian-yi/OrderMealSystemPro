#数据模块 qml 的model 类
include($$PWD/qml_model/qml_model.pri)
#关于qml 与c++ 进行命令式数据交互的 注册类
include($$PWD/qml_connect/qml_connect.pri)

HEADERS += \
    $$PWD/qmlservice.h

SOURCES += \
    $$PWD/qmlservice.cpp

INCLUDEPATH += $$PWD/
