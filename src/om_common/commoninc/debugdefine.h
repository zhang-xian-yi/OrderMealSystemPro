#ifndef GLOBAL_H
#define GLOBAL_H

//文件编码
#include <QTextCodec>
#include <QString>

#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif
/*
#define DEBUG_UTIL_TRACE
#define DEBUG_DATABASE_TRACE
#define DEBUG_UI_TRACE
#define DEBUG_SERVICE_TRACE
*/
#define LOG

#define DEBUG_CONNECT_TRACE
#ifdef DEBUG_CONNECT_TRACE
#include <stdio.h>
#define DEBUG_CONNECT(format,...)  printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_CONNECT(format,...)
#endif


#ifdef DEBUG_DATABASE_TRACE
#include <stdio.h>
#define DEBUG_MYSQL(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#define DEBUG_SQLITE(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_MYSQL(format,...)
#define DEBUG_SQLITE(format,...)
#endif

#ifdef DEBUG_UI_TRACE
#include <stdio.h>
#define DEBUG_UI(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_UI(format,...)
#endif


#ifdef DEBUG_UTIL_TRACE
#include <stdio.h>
#define DEBUG_UTIL(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_UTIL(format,...)
#endif

#ifdef DEBUG_SERVICE_TRACE
#include <stdio.h>
#define DEBUG_SERVICE(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define DEBUG_SERVICE(format,...)
#endif



#ifdef LOG
#include <stdio.h>
#define LOG_INFO(format,...) printf("[File: " __FILE__ ", Line: %d]:" format "\n", __LINE__, ##__VA_ARGS__)
#else
#define LOG_INFO(format,...)
#endif

//文件编码
#if defined(_MSC_VER) && (_MSC_VER >= 1600)
#pragma execution_character_set("utf-8")
#endif


#define FromQString(x) QTextCodec::codecForLocale()->fromUnicode(x).toStdString()
#define ToQString(x) QTextCodec::codecForLocale()->toUnicode((x).c_str())

#endif // GLOBAL_H
