#ifndef EMPLOYERS_H
#define EMPLOYERS_H
#include <QString>

class Identity;

class Employers
{
public:
    Employers();
    ~Employers();
    //get and set func
    QString getId()const;
    void setId(QString id);

    QString getUsername()const;
    void setUsername(QString username);

    QString getPassword()const;
    void setPassword(QString passwd);

    int getIden()const;
    void setIden(int iden);
private:
    QString id;
    QString username;
    QString password;
    int     level;             //身份用于识别各个角色
};

#endif // EMPLOYERS_H
