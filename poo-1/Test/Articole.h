#ifndef ARTICOLE_H
#define ARTICOLE_H
#include <iostream>
#include "Cloneable.h"
class Articol : public Cloneable
{
    std::string nume, prenume, titlu;
    int anPublicare;

public:
    Articol(std::string nume = "undeifined", std::string prenume = "undefined", std::string titlu = "undefined",
            int anPublicare = 0) : nume(nume), prenume(prenume), titlu(titlu), anPublicare(anPublicare){};
    Articol(Articol &);
    virtual void print(std::ostream &) const;
    virtual void read(std::istream &);
    friend std::ostream &operator<<(std::ostream &, const Articol &);
    friend std::istream &operator>>(std::istream &, Articol &);
    virtual bool searchByYear(int &);
    virtual bool searchByName(std::string &);
};
#endif