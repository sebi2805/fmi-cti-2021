#include "Comanda.h"
#include "VaccinAntiGripa.h"
#include "VaccinCovid.h"
#include "VaccinHepatita.h"
Comanda::Comanda(Comanda &obj) : AutoId(obj)
{
          vaccinuri = obj.vaccinuri;
          nume = obj.nume;
          zi = obj.zi;
          luna = obj.luna;
          an = obj.luna;
          cantitate = obj.cantitate;
};
void Comanda::print(std::ostream &os) const
{
          os << "Clientul se numeste:" << nume << " .Comanda trebuie livrata in (" << zi << "," << luna << "." << an << ") .Si contine urmatoarele vaccinuri:\n";
          for (int i = 0; i < vaccinuri.size(); i++)
          {
                    os << cantitate[i] << " doze de " << vaccinuri[i]->getType() << *vaccinuri[i];
          }
          os << std::endl;
};
void Comanda::read(std::istream &is)
{
          std::cout << "Cum se numeste clientul?" << std::endl;
          is >> nume;
          std::cout << "Care este ziua?" << std::endl;
          is >> zi;
          std::cout << "Care este luna?" << std::endl;
          is >> luna;
          std::cout << "Care este an?" << std::endl;
          is >> an;
          int i, k;
          // std::cout << "Cate vaccinuri vreti sa adaugati?" << std::endl;
          // is >> i;
          // std::shared_ptr<Vaccin> aux;
          // for (int j = 0; j < i; i++)
          // {
          //           std::cout << "Ce tip de vaccin este?\n1.AntiCovid\n2.AntiGripal\n3.AntiHepatita" << std::endl;
          //           is >> k;
          //           if (k == 1)
          //                     aux = std::make_shared<VaccinCovid>();
          //           else if (k == 2)
          //                     aux = std::make_shared<VaccinAntiGripa>();
          //           else if (k == 3)
          //                     aux = std::make_shared<VaccinHepatita>();
          //           else
          //                     throw "Acest tip nu exista";
          //           aux->read(is);
          //           vaccinuri.push_back(aux);
          //           std::cout << "Si in ca cantitate se afla?" << std::endl;
          //           is >> k;
          //           cantitate.push_back(k);
          // }
};
void Comanda::addVaccin(std::shared_ptr<Vaccin> vaccin, int can)
{
          cantitate.push_back(can);
          vaccinuri.push_back(vaccin);
};
std::ostream &operator<<(std::ostream &os, const Comanda &obj)
{
          obj.print(os);
          return os;
};
std::istream &operator>>(std::istream &is, Comanda &obj)
{
          obj.read(is);
};