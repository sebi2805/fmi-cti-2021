#include "Carte.h"
#include "Articole.h"
Carte::Carte(Carte &obj) : Articol(obj)
{
    numeEditura = obj.numeEditura;
    numeOras = obj.numeOras;
};
std::ostream &operator<<(std::ostream &os, const Carte &obj)
{
    obj.print(os);
    return os;
};

std::istream &operator>>(std::istream &is, Carte &obj)
{
    obj.read(is);
    return is;
};

void Carte::printSubClass(std::ostream &os) const
{
    os << "Numele orasului si numele editurii sunt: " << numeOras << " " << numeEditura << std::endl;
};
bool Carte::searchByName(std::string &_name)
{
    if (Articol::searchByName(_name))
    {
        printSubClass(std::cout);
        return true;
    }
    return false;
};
bool Carte::searchByYear(int &year)
{
    if (Articol::searchByYear(year))
    {
        printSubClass(std::cout);
        return true;
    }
    return false;
};
;
void Carte::print(std::ostream &os) const
{
    Articol::print(os);
    printSubClass(os);
};
void Carte::read(std::istream &is)
{
    Articol::read(is);
    std::cout << "Care este numele orasului?" << std::endl;
    is >> numeOras;
    std::cout << "Care este numele editurii?" << std::endl;
    is >> numeEditura;
};