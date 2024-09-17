
#ifndef VACCINcovid
#define VACCINcovid
#include <vector>
#include "Vaccin.h"
class VaccinCovid : virtual public Vaccin
{
          std::vector<std::string> reactii, medicamente;
          float rata;

public:
          VaccinCovid(float pret = 0,
                      int temp = 0,
                      std::vector<std::string> substante = {},
                      std::vector<std::string> reactii = {}, std::vector<std::string> medicamente = {},
                      float rata = 0, std::string numeProd = "undefined") : Vaccin(VaccinType::AntiCovid, pret, temp, substante, numeProd), reactii(reactii), medicamente(medicamente), rata(rata){};
          VaccinCovid(VaccinCovid &);
          void print(std::ostream &) const override;
          void read(std::istream &) override;
          friend std::ostream &operator<<(std::ostream &, const VaccinCovid &);
          friend std::istream &operator>>(std::istream &, VaccinCovid &);
};
#endif