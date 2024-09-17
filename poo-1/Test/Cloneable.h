#ifndef CLONE
#define CLONE
class Cloneable
{
    static int idClass;
    int id;

public:
    Cloneable()
    {
        idClass++;
        id = idClass;
    }
    int getId() const;
};
#endif