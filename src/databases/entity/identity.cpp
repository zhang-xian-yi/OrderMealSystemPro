#include "identity.h"

Identity::Identity()
{

}

Identity::~Identity()
{

}

int Identity::getLevel()
{
    return this->level;
}

void Identity::setLevel(int level_)
{
    this->level = level_;
}

int Identity::getPrilvege()
{
    return this->prilvege;
}

void Identity::setPrilvege(int prilvege_)
{
    this->prilvege = prilvege_;
}


QString Identity::getRole()
{
    return this->role;
}

void Identity::setRole(QString role_)
{
    this->role = role_;
}
