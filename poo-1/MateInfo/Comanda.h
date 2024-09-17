
#ifndef COMANDA
#define COMANDA
#include <vector>
#include <memory>
#include "PrintRead.h"
#include "IdClass.h"
#include "Vaccin.h"
class Comanda : virtual public PrintRead, virtual public AutoId
{
          std::string nume;
          std::vector<std::shared_ptr<Vaccin>> vaccinuri;
          std::vector<int> cantitate;
          int zi, luna, an;

public:
          Comanda(int zi = 0, int luna = 0, int an = 0, std::string nume = "undefined",
                  std::vector<std::shared_ptr<Vaccin>> vaccinuri = {},
                  std::vector<int> cantitate = {}) : zi(zi), luna(luna), an(an), nume(nume), vaccinuri(vaccinuri), cantitate(cantitate){};
          Comanda(Comanda &);
          void print(std::ostream &) const override;
          void read(std::istream &) override;
          friend std::ostream &operator<<(std::ostream &, const Comanda &);
          friend std::istream &operator>>(std::istream &, Comanda &);
          void addVaccin(std::shared_ptr<Vaccin>, int);
};
#endif