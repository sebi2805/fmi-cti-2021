#include <iostream>
#include <ostream>
#include "Angajat.h"
Angajat::Angajat(Angajat &obj)
{
    nume = obj.nume;
    prenume = obj.prenume;
    dataAngajarii = obj.dataAngajarii;
    functia = obj.functia;
    CNP = obj.CNP;
    functia = obj.functia;
};
int Angajat::idAngajat = 0;
void Angajat::print(std::ostream &out) const
{
    out << "Nume este " << nume << "prenume este" << prenume << " cnp este " << CNP << " data angajarii este " << dataAngajarii << " functia este " << functia << std::endl;
};
void Angajat::read(std::istream &is)
{
    std::cout << "Introduceti numele " << std::endl;
    is >> nume;
    std::cout << "Introduceti prenumele " << std::endl;
    is >> prenume;
    std::cout << "Introduceti dataAngajarii " << std::endl;
    is >> dataAngajarii;
    std::cout << "Introduceti functia " << std::endl;
    is >> functia;
    std::cout << "Introduceti cnp " << std::endl;
    is >> CNP;
    int i;
    std::cout << "Introduceti tipul\n1.Temporar\n2.Permanent " << std::endl;
    is >> i;
    switch (i)
    {
    case 1:
    {
        type = AngajatType::temporar;
        break;
    }
    case 2:
    {
        type = AngajatType::temporar;
        break;
    }
    default:
    {
        throw "Nu exista tipul acesta";
        break;
    }
    }
};
std::ostream &operator<<(std::ostream &out, const Angajat &obj)
{
    obj.print(out);
    return out;
};
std::istream &operator>>(std::istream &is, Angajat &obj)
{
    obj.read(is);
    return is;
};
const std::string Angajat::getNume() const
{
    return nume;
};
const std::string Angajat::getPreume() const
{
    return prenume;
};
const std::string Angajat::getCNP() const
{
    return CNP;
};
const std::string Angajat::getFunctia() const
{
    return functia;
};
const AngajatType Angajat::getType() const
{
    return type;
};
const std::string Angajat::getDataAngajarii() const
{
    return dataAngajarii;
};
void Angajat::setNume(std::string _nume)
{
    nume = _nume;
};
void Angajat::setPrenume(std::string _prenume)
{
    prenume = _prenume;
};
void Angajat::setType(AngajatType _type)
{
    type = _type;
};
void Angajat::setDataAngajarii(std::string _dataAngajarii)
{
    dataAngajarii = _dataAngajarii;
};
void Angajat::setFunctia(std::string _functia)
{
    functia = _functia;
};
void Angajat::setCNP(std::string _CNP)
{
    CNP = _CNP;
};
void Angajat::addMoney(MoneyGain &mon)
{
    money.push_back(mon);
};