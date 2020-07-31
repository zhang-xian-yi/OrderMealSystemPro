
QT  += sql

HEADERS += \
    $$PWD/sqlglobal.h \
    $$PWD/sqloper.h

include($$PWD/sqlite/sqlite.pri)
include($$PWD/entity/entity.pri)
include($$PWD/mysql/mysql.pri)

INCLUDEPATH += $$PWD/sqlite/
INCLUDEPATH += $$PWD/entity/
INCLUDEPATH += $$PWD/

SOURCES += \
    $$PWD/sqloper.cpp
