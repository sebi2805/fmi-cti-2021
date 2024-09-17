#include "VaccinAntiGripa.h"
VaccinAntiGripa::VaccinAntiGripa(VaccinAntiGripa &obj) : Vaccin(obj)
{
          tulpina = obj.tulpina;
          respecta = obj.respecta;
};
void VaccinAntiGripa::print(std::ostream &os) const
{
          Vaccin::print(os);
          os << "Tulpina este " << tulpina;
          if (respecta)
                    os << " si respecta ..";
          else
                    os << " si nu respecta ";
          os << std::endl;
};
void VaccinAntiGripa ::read(std::istream &is)
{
          Vaccin::read(is);
          std::cout << "Care este tuplina?" << std::endl;
          is >> tulpina;
          int i;
          std::cout << "Respecta?\n1.Da\n2.Nu" << std::endl;
          is >> i;
          if (i == 1)
                    respecta = true;
          else
                    respecta = false;
};
std::ostream &operator<<(std::ostream &os, const VaccinAntiGripa &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, VaccinAntiGripa &obj)
{
          obj.read(is);
          return is;
};