#include "Vaccin.h"
#include <iostream>
void Vaccin::print(std::ostream &os) const
{
   os << "Pretul acestui vaccin este " << pret << " se depoziteaza la temp " << temp << std::endl;
   os << "Substante;e sunt"
      << " ";
   for (auto subs : substante)
      os << subs << " ";
   os << std::endl;
};
Vaccin::Vaccin(Vaccin &obj)
{
   pret = obj.pret;

   temp = obj.temp;

   substante = obj.substante;
};
void Vaccin::read(std::istream &is)
{
   std::cout << "Care este pretul?" << std::endl;
   is >> pret;
   std::cout << "Care este numele producatorului?" << std::endl;
   is >> numeProd;
   std::cout << "Care este temp?" << std::endl;
   is >> temp;
   int i;
   std::cout << "Cate substante contine?" << std::endl;
   is >> i;
   std::string aux;
   for (int j = 0; j < i; j++)
   {
      std::cout << "Care este numele subst?" << std::endl;
      is >> aux;
      substante.push_back(aux);
   }
};

std::ostream &operator<<(std::ostream &os, const Vaccin &obj)
{
   obj.print(os);
   return os;
};
std::istream &operator>>(std::istream &is, Vaccin &obj)
{
   obj.read(is);
   return is;
};
std::string Vaccin::getType() const
{
   if (type == VaccinType::AntiCovid)
   {
      return "AntiCovid";
   }
   if (type == VaccinType::AntiGripal)
   {
      return "AntiCovid";
   }
   if (type == VaccinType::AntiHepatita)
   {
      return "AntiCovid";
   }
   return "";
};
std::string Vaccin::getNume()
{
   return numeProd;
};