#include <QFile>
#include <QChar>
#include <QTextStream>
#include "commoninc/debugdefine.h"

#include "encryputil.h"


#define ENCRYP_MAX_SIZE     128
#include <string.h>


void EncrypUtil::encryptFile(const QString& filepath)
{
    QFile file(filepath);
    QTextStream in(&file);
    QString str;
    if(file.open(QIODevice::ReadWrite))
    {
        str = in.readAll();
        DEBUG_UTIL("read in file %s\n",str.toStdString().c_str());

        int len = str.length();
        for(int i=0;i<len;++i)
        {
            str[i] = QChar::fromLatin1(str[i].toLatin1() - 1);
        }
        DEBUG_UTIL("write in file %s\n",str.toStdString().c_str());
    }
    file.close();

    QTextStream out(&file);
    file.open(QIODevice::WriteOnly);
    out << str;
    file.close();
}



void EncrypUtil::decryptFile(const QString& filepath)
{
    QFile file(filepath);
    QTextStream fin(&file);
    QString str;
    if(file.open(QIODevice::ReadOnly))
    {
        str = fin.readAll();
        DEBUG_UTIL("%s",str.toStdString().c_str());
        int len = str.length();
        for(int i=0;i<len;++i)
        {
            str[i] = QChar::fromLatin1(str[i].toLatin1() + 1);
        }
    }
    file.close();
    QTextStream fout(&file);
    file.open(QIODevice::WriteOnly);
    fout << str;
    file.close();
}






