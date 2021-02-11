TEMPLATE = lib
TARGET = om_centralcontrol
#中央控制系统的lib
DEFINES = OM_CCS_LIBARAY

include($$PWD/ccsprivate/ccsprivate.pri)

INCLUDEPATH += $$PWD/
#依赖关系定义
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_databases
LIBS += -L$$PWD/../../generatedFile/destdir/ -lom_common

HEADERS += \
    centralcontrolsys.h

SOURCES += \
    centralcontrolsys.cpp

# generate file path
MOC_DIR = $$PWD/../../generatedFile/temp/moc
RCC_DIR = $$PWD/../../generatedFile/temp/rcc
OBJECTS_DIR = $$PWD/../../generatedFile/temp/obj
DESTDIR = $$PWD/../../generatedFile/destdir
DLLDESTDIR = $$PWD/../../generatedFile/bin
