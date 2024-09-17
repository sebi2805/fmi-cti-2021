#include "Cloneable.h"
int Cloneable::idClass = 0;
int Cloneable::getId() const
{
    return idClass;
}