#include "encryputil.h"
#include "global.h"
#include <QFile>
#include <QChar>


#if _MSC_VER >= 1600
#pragma execution_character_set("utf-8")
#endif

void EncrypUtil::encryptFile(const QString& filepath)
{
    QFile file(filepath);
    QTextStream in(&file);
    QString str;
    if(file.open(QIODevice::ReadWrite))
    {
        str = in.readAll();
        TRACE("read in file %s\n",str.toStdString().c_str());

        int len = str.length();
        for(int i=0;i<len;++i)
        {
            str[i] = QChar::fromLatin1(str[i].toLatin1() - 1);
        }
        TRACE("write in file %s\n",str.toStdString().c_str());
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
        qDebug() << str;
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






