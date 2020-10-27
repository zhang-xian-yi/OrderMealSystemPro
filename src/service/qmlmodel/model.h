#ifndef MODEL_H
#define MODEL_H
#include <QVariant>
#include <QModelIndex>


class Model
{
public:
    explicit Model(){}
    virtual ~Model() = 0;
    // Basic functionality:
    virtual int rowCount(const QModelIndex &parent = QModelIndex()) = 0 ;
    virtual QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) =0;

    // Editable:
    virtual bool setData(const QModelIndex &index, const QVariant &value,int role = Qt::EditRole) = 0 ;
    virtual Qt::ItemFlags flags(const QModelIndex& index) = 0;

};

#endif // MODEL_H
