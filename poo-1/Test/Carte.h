#ifndef CARTE_H
#define CARTE_H
#include <iostream>
#include "Articole.h"
class Carte : public Articol
{
    std::string numeOras, numeEditura;

public:
    Carte(std::string nume = "undeifined", std::string numeOras = "undefined", std::string numeEditura = "undefined", std::string prenume = "undefined", std::string titlu = "undefined", int anPublicare = 0)
        : Articol(nume, prenume, titlu, anPublicare), numeOras(numeOras), numeEditura(numeEditura){};
    Carte(Carte &);
    friend std::ostream &operator<<(std::ostream &, const Carte &);
    friend std::istream &operator>>(std::istream &, Carte &);
    void printSubClass(std::ostream &os) const;
    bool searchByName(std::string &) override;
    bool searchByYear(int &) override;
    void print(std::ostream &os) const override;
    void read(std::istream &) override;
};
#endif