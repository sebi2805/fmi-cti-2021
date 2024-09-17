#ifndef ANGAJAT_PERMA
#define ANGAJAT_PERMA
#include <iostream>
#include "Angajat.h"
#include <vector>

class AngajatPermanent : public Angajat
{
    int salary;
    float procent, maxBonus;
    std::vector<MoneyGain> bonus;

public:
    AngajatPermanent(std::string nume = "undefined", std::string prenume = "undefined", std::string CNP = "undefined", std::string dataAngajarii = "undefined", std::string functia = "undefined", AngajatType type = AngajatType::unknown, int salary = 0, float procent = 0, float maxBonus = 0, std::vector<MoneyGain> bonus = {})
        : Angajat(nume, prenume, CNP, dataAngajarii, functia, type), salary(salary), maxBonus(maxBonus), procent(procent),
          bonus(bonus){};
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, const AngajatPermanent &);
    friend std::istream &operator>>(std::istream &, AngajatPermanent &);
    void addBonusMonth(MoneyGain &);
};
#endif