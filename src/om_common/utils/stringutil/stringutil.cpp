#include "stringutil.h"
#include "commoninc/debugdefine.h"
#include <QSet>

StringUtil::StringUtil()
{

}
StringUtil::~StringUtil()
{

}
StringUtil* StringUtil::getInstance()
{
    static StringUtil instance;
    return &instance;
}

int StringUtil::getMathNum(const QString& str1,const QString& str2)const
{
    DEBUG_UTIL("in str1:%s\tstr2 %s ",str1.data(),str2.data());

    QString short_str = str1.length() < str2.length()?str1:str2;
    QString large_str = str1.length() > str2.length()?str1:str2;

    int short_str_index = 0;
    int large_str_index = 0;
    int level = 0;
    /**
    * @brief: is_continue 是用来检验是否是连续字符串的增加
    * @date: 2020-10-15
    */
    bool is_continuos = true;
    while(true)
    {
        //比较完毕之后 也需要退出
        if(large_str_index >= large_str.length() - 1)
        {
            break;
        }
        //对short_index 的取值不可预估 有可能一直不变  这将导致large_index 的下标访问越界  所以不能作为while 判断条件
        //下标与长度 相差1
        if(short_str_index >= short_str.length() - 1)
        {
            break;
        }
        //找到连续相同的字符串个数
        if(short_str.at(short_str_index) == large_str.at(large_str_index))
        {
            ++ short_str_index;
            ++level;
            //第一个字符相等 当第二个字符不相等  说明只是单个字符相等
            //此时的short_index 已经+1  所以 需要比较的是长串的下一个 和短串的这一个字符
            if(is_continuos && (large_str[large_str_index  + 1 ] != short_str[short_str_index] ) )
            {
                 // 将坐标清0
                 short_str_index = 0;
                 level = 0;
            }
            else
            {
                //一旦连续两个字符相等 认定为有大概率匹配到目标  不在进行坐标重置
                is_continuos = false;
            }
        }
        ++large_str_index;
    }
    return level;
}


QString StringUtil::getMaxMatchStr(const QStringList list, const QString &str)const
{
    QString ret;
    //遍历列表  找到最大相似度 的路径
    int max = 0;
    foreach(QString item,list)
    {
        int tmp = getMathNum(item,str);
        if(tmp > max)
        {
            max = tmp;
            ret = item;
        }
    }
    return ret;
}

QString StringUtil::getLastNameofFilePath(const QString& path)const
{
    int first = path.lastIndexOf ("/"); //从后面查找"/"位置
    if(first == -1)
    {
        first = path.lastIndexOf ("\\");
    }
    QString title = path.right(path.length()-first-1); //从右边截取
    return title;
}


QString StringUtil::getFirstName(const QString &path)
{
    int first = path.indexOf("/"); //从后面查找"/"位置
    QString parentpath = path.left(first - 1); //从左边截取
    return parentpath;
}
