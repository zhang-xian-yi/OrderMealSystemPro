QT    += network

TEMPLATE = lib
TARGET = om_network

DEFINES = OM_NETWORK_LIBARAY

include($$PWD/qmlconnect/qmlconnect.pri)

INCLUDEPATH += $$PWD/

ROOT_PATH = $$PWD/../../
#中间文件的生成路径
MOC_DIR = $$ROOT_PATH/generatedFile/temp/moc
RCC_DIR = $$ROOT_PATH/generatedFile/temp/rcc
OBJECTS_DIR = $$ROOT_PATH/generatedFile/temp/obj
DESTDIR = $$ROOT_PATH/generatedFile/destdir
#拷贝最后的dll 文件 到bin 文件夹
DLLDESTDIR = $$ROOT_PATH/generatedFile/bin


LIBS += -L$$ROOT_PATH/generatedFile/destdir -lom_common
LIBS += -L$$ROOT_PATH/generatedFile/destdir -lom_databases

