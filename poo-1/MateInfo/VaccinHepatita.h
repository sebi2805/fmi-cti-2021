
#ifndef VACCINhepatita
#define VACCINhepatita
#include <vector>
#include "Vaccin.h"
enum HepatitaEnum
{
    O1,
    A,
    B,
    C
};
enum Mod
{
    O,
    intramuscular,
    subcutanat,
    intradermic
};
class VaccinHepatita : virtual public Vaccin
{
    Mod mod;
    HepatitaEnum tip;

public:
    VaccinHepatita(float pret = 0,
                   int temp = 0,
                   std::vector<std::string> substante = {},
                   bool respecta = false, std::string tulpina = "undefined", Mod mod = Mod::O,
                   HepatitaEnum tip = HepatitaEnum::O1, std::string numeProd = "undefined")
        : Vaccin(VaccinType::AntiHepatita, pret, temp, substante, numeProd), mod(mod), tip(tip){};
    VaccinHepatita(VaccinHepatita &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, const VaccinHepatita &);
    friend std::istream &operator>>(std::istream &, VaccinHepatita &);
};
#endif