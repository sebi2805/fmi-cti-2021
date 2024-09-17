
#ifndef VACCINGRIPA
#define VACCINGRIPA
#include <vector>
#include "Vaccin.h"
class VaccinAntiGripa : virtual public Vaccin
{
          std::string tulpina;
          bool respecta;

public:
          VaccinAntiGripa(float pret = 0,
                          int temp = 0,
                          std::vector<std::string> substante = {},
                          bool respecta = false, std::string tulpina = "undefined", std::string numeProd = "undefined") : Vaccin(VaccinType::AntiGripal, pret, temp, substante, numeProd), respecta(respecta), tulpina(tulpina){};
          VaccinAntiGripa(VaccinAntiGripa &);
          void print(std::ostream &) const override;
          void read(std::istream &) override;
          friend std::ostream &operator<<(std::ostream &, const VaccinAntiGripa &);
          friend std::istream &operator>>(std::istream &, VaccinAntiGripa &);
};
#endif