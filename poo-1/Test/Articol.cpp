#include "Articole.h"
Articol::Articol(Articol &obj)
{
    nume = obj.nume;
    prenume = obj.prenume;
    titlu = obj.titlu;
    anPublicare = obj.anPublicare;
};
std::ostream &operator<<(std::ostream &os, const Articol &obj)
{
    os << obj.getId() << "Numele si prenumele autorului este " << obj.nume << " " << obj.prenume << ". Titlul este "
       << obj.titlu << " si anul publiclarii este " << obj.anPublicare << std::endl;
    return os;
};
std::istream &operator>>(std::istream &is, Articol &obj)
{
    std::cout << "Care este numele autorului" << std::endl;
    is >> obj.nume;
    std::cout << "Care este prenumele autorului" << std::endl;
    is >> obj.prenume;
    std::cout << "Care este titlul " << std::endl;
    is >> obj.titlu;
    std::cout << "Care este anul publicarii" << std::endl;
    is >> obj.anPublicare;
    return is;
};
void Articol ::print(std::ostream &os) const
{
    os << *this;
};
void Articol::read(std::istream &is)
{
    is >> *this;
};
bool Articol::searchByYear(int &_an)
{
    print(std::cout);
    if (anPublicare == _an)
        return true;
    return false;
};
bool Articol::searchByName(std::string &_nume)
{
    print(std::cout);
    return nume == _nume;
};