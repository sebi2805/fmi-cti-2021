#ifndef BIBLIOGRAFIE_H
#define BIBLIOGRAFIE_H
#include <iostream>
class Bibliografie
{
public:
    Bibliografie(){};
    virtual void print(std::ostream &) const = 0;
    virtual void read(std::istream &) = 0;
};
#endif