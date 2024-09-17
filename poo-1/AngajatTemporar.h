#ifndef ANGAJAT_TEMPORAR
#define ANGAJAT_TEMPORAR
#include <iostream>
#include <vector>
#include "Angajat.h"

struct LuniLucrate
{
    MonthType month;
    int ore;
};
class AngajatTemporar : public Angajat
{
    int numarOre, pretOra;
    std::string dataTerminare;
    std::vector<LuniLucrate> luniLucrate;

public:
    AngajatTemporar(int numarOre = 0, int pretOra = 0, std::string dataTerminare = "12 june",
                    std::string nume = "undefined", std::string prenume = "undefined", std::string CNP = "undefined", std::string dataAngajarii = "undefined", std::string functia = "undefined", AngajatType type = AngajatType::unknown)
        : Angajat(nume, prenume, CNP, dataAngajarii, functia, type), numarOre(numarOre), pretOra(pretOra), dataTerminare(dataTerminare){};
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, const AngajatTemporar &);
    friend std::istream &operator>>(std::istream &, AngajatTemporar &);
    void addOre(int &);
};
#endif