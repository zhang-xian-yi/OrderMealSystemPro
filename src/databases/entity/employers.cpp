#include "employers.h"

Employers::Employers()
{
    this->level = 0;
}
Employers::~Employers()
{

}

QString Employers::getId()const
{
    return this->id;
}
void Employers::setId(QString id)
{
    this->id = id;
}

QString Employers::getUsername()const
{
    return this->username;
}
void Employers::setUsername(QString username)
{
    this->username = username;
}

QString Employers::getPassword()const
{
    return this->password;
}
void Employers::setPassword(QString passwd)
{
    this->password = passwd;
}

int Employers::getIden()const
{
    return this->level;
}
void Employers::setIden(int level)
{
    this->level = level;
}
