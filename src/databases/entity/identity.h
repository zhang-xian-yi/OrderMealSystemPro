#ifndef IDENTITY_H
#define IDENTITY_H
#include <QString>

/*
1 游客
2 会员
3 服务员
4 后厨人员
5 柜台人员
6 餐厅经理
*/


class Identity
{
public:
    Identity();
    ~Identity();
    int     getLevel( );
    void    setLevel(int level_);
    int     getPrilvege( );
    void    setPrilvege(int level_);
    QString getRole();
    void    setRole(QString role_);
private:
    int     level;    //等级
    int     prilvege; //权限
    QString role;     //角色
};

#endif // IDENTITY_H
