#ifndef VACCIN
#define VACCIN
#include <vector>
#include "PrintRead.h"
enum VaccinType
{
       necunoscut,
       AntiGripal,
       AntiCovid,
       AntiHepatita
};
class Vaccin : virtual public PrintRead
{
       float pret;
       int temp;
       std::vector<std::string> substante;
       VaccinType type;
       std::string numeProd;

public:
       Vaccin(VaccinType type = VaccinType::necunoscut, float pret = 0,
              int temp = 0,
              std::vector<std::string> substante = {}, std::string numeProd = "undefined") : type(type), pret(pret), temp(temp), numeProd(numeProd), substante(substante){};
       void print(std::ostream &) const override;
       void read(std::istream &) override;
       std::string getType() const;
       friend std::ostream &
       operator<<(std::ostream &, const Vaccin &);
       friend std::istream &operator>>(std::istream &, Vaccin &);
       Vaccin(Vaccin &);
       std::string getNume();
       virtual ~Vaccin() {}
};
#endif