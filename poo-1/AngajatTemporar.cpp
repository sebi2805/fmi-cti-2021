#include "AngajatTemporar.h"
void AngajatTemporar::print(std::ostream &os) const
{
    Angajat::print(os);
    os << "Numarul de ore lucrate este: " << numarOre << " pretul pentru o ora este " << pretOra << std::endl;
};
void AngajatTemporar::read(std::istream &is)
{
    Angajat::read(is);
    std::cout << "Care este numarul de ore " << std::endl;
    is >> numarOre;
    std::cout << "Care este pretul pentru o ora" << std::endl;
    is >> pretOra;
};
std::ostream &operator<<(std::ostream &os, const AngajatTemporar &obj)
{
    obj.print(os);
    return os;
};
std::istream &operator>>(std::istream &is, AngajatTemporar &obj)
{
    obj.read(is);
    return is;
};
void AngajatTemporar::addOre(int &i)
{
    numarOre = numarOre + i;
};