#ifndef MODELFACTORY_H
#define MODELFACTORY_H

#include <QString>
#include "model.h"

class ModelFactory
{
public:
    QAbstractItemModel* getModelBean(const QString& name)const;
};

#endif // MODELFACTORY_H
