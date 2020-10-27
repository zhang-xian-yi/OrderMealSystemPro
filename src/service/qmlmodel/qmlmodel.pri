#private 处理model 私有的类
include($$PWD/servicer_model/servicer_model.pri)
INCLUDEPATH += $$PWD/

HEADERS += \
    $$PWD/modelfactory.h

SOURCES += \
    $$PWD/modelfactory.cpp




