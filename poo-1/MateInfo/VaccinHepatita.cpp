#include "VaccinHepatita.h"
VaccinHepatita::VaccinHepatita(VaccinHepatita &obj) : Vaccin(obj)
{

          tip = obj.tip;
          mod = obj.mod;
};
void VaccinHepatita::print(std::ostream &os) const
{
          Vaccin::print(os);
          os << "Modul de administrare este ";
          if (mod == Mod::intradermic)
                    os << "intrademic";
          else if (mod == Mod::intramuscular)
                    os << "intramuscular";
          else if (mod == Mod::subcutanat)
                    os << "subcutanat";
          os << std::endl
             << " si este de tipul ";
          if (tip == HepatitaEnum::A)
                    os << " A";
          else if (tip == HepatitaEnum::B)
                    os
                        << " B";
          else if (tip == HepatitaEnum::C)
                    os << " C";
          os << std::endl;
};
void VaccinHepatita::read(std::istream &is)
{
          Vaccin::read(is);
          std::cout << "Care este modul de administrare?\n  1.intramuscular\n 2.subcutanat\n 3.intradermic\n";
          int i;
          is >> i;
          if (i == 1)
                    mod = Mod::intramuscular;
          else if (i == 2)
                    mod = Mod::intradermic;
          else if (i == 3)
                    mod = Mod::subcutanat;
          else
                    throw "nu exista";
          std::cout << "Care este tipul de hepatita?\n  1.A\n 2.B\n 3.C\n";

          is >> i;
          if (i == 1)
                    tip == HepatitaEnum::A;
          else if (i == 2)
                    tip == HepatitaEnum::B;
          else if (i == 3)
                    tip == HepatitaEnum::C;
          else
                    throw "nu exista";
};

std::ostream &operator<<(std::ostream &os, const VaccinHepatita &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, VaccinHepatita &obj)
{
          obj.read(is);
          return is;
};