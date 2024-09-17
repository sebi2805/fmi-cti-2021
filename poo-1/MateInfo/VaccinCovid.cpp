#include "VaccinCovid.h"

VaccinCovid::VaccinCovid(VaccinCovid &obj) : Vaccin(obj)
{
          reactii = obj.reactii;
          medicamente = obj.medicamente;
          rata = obj.rata;
};
void VaccinCovid::print(std::ostream &os) const
{
          Vaccin::print(os);
          os << "Medicamentele sunt: ";
          for (auto med : medicamente)
                    os << med << " ";
          os << std::endl;
          os << "Reactiile adverse sunt: ";
          for (auto rea : reactii)
                    os << rea << " ";
          os << std::endl;
          os << " si rata este " << rata << std::endl;
};
void VaccinCovid::read(std::istream &is)
{
          int i;
          std::string aux;
          Vaccin::read(is);
          std::cout << "Cate medicamente contraindicate vreti sa adaugati?" << std::endl;
          is >> i;
          for (int j = 0; j < i; j++)
          {
                    std::cout << "Cum se numeste medicamentul" << std::endl;
                    is >> aux;

                    medicamente.push_back(aux);
          }
          std::cout << "Ce reaactii adverse sunt?" << std::endl;
          is >> i;
          for (int j = 0; j < i; j++)
          {
                    std::cout << "Cum se numeste reactia" << std::endl;
                    is >> aux;

                    reactii.push_back(aux);
          }
          std::cout << "Care este rata?" << std::endl;
          is >> rata;
};
std::ostream &operator<<(std::ostream &os, const VaccinCovid &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, VaccinCovid &obj)
{
          obj.read(is);
          return is;
};