#ifndef ENTITYENUMINDEX_H
#define ENTITYENUMINDEX_H


//作为从数据库中取出value 的时候用作下标标记 entity 的任何实体

namespace EntityIndex
{
enum EmployerIndex{
        id_index = 0,
        profess_index,
        name_index,
        password_index
};

enum FoodIndex{
    Name_index = 0,
    Price_index,
    Desc_index,
    ImgUrl_index,
    Type_index
};
}



namespace PublicType {
enum EMSgType
{
    LOGIN_SUCC = 0,
    LOGIN_FAILED,
    USER_ERROR,
    PASSWD_ERROR,
    LOAD_UI_ERROR,
    NORMAL_EXIT_APP
};

enum EEntityFlag{
    Employ_flag = 0,
    Food_flag ,
};

enum EProfessType{
    Visitor = 0,
    Sevicr,
    Cooker,
    Counter,
    Manager

};
}





#endif // ENTITYENUMINDEX_H
