#ifndef GLOBAL_H
#define GLOBAL_H

#define DEBUG 1

#ifdef DEBUG
#include <QDebug>
#define TRACE qDebug
#define UNILOGW //
#else
#define TRACE    //
#define UNILOGW  //
#endif


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

#endif // GLOBAL_H
