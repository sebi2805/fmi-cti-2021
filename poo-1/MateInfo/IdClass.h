#include <iostream>

using namespace std;

class Coord
{
private:
          char *sistem_coordonate;
          double x[1], y, z;

public:
          Coord(char *sistem_coordonate, double x, double &y, double z = 0)
          {
                    this->sistem_coordonate = new char[strlen(sistem_coordonate)];
                    strcpy(this->sistem_coordonate, sistem_coordonate);
                    this->x[0] = x;
                    this->y = y;
                    this->z = z;
          };
          const char *getSistemCoordonate() const
          {
                    return sistem_coordonate;
          }
          const double getX() const
          {
                    return x[0];
          }
          const double getY() const
          {
                    return y;
          }
          const double getZ() const
          {
                    return z;
          }
          void setSistemCoordonate(char *sistem_coordonate)
          {
                    this->sistem_coordonate = new char[strlen(sistem_coordonate)];
                    strcpy(this->sistem_coordonate, sistem_coordonate);
          }

          void setX(double x)
          {
                    this->x[0] = x;
          }
          void setY(double y)
          {
                    this->y = y;
          }
          void setZ(double z)
          {
                    this->z = z;
          }
          ~Coord()
          {
                    delete[] sistem_coordonate;
          };
};

class Par
{
private:
          char *cod;
          char *denumire;
          char *um;

public:
          Par() {}
          Par(char *cod, char *denumire, char *um)
          {
                    this->cod = new char[strlen(cod)];
                    strcpy(this->cod, cod);
                    this->denumire = new char[strlen(denumire)];
                    strcpy(this->denumire, denumire);
                    this->um = new char[strlen(um)];
                    strcpy(this->um, um);
          };
          const char *getCod() const
          {
                    return cod;
          }
          const char *getDenumire() const
          {
                    return denumire;
          }
          const char *getUm() const
          {
                    return um;
          }
          void setCod(char *cod)
          {
                    this->cod = new char[strlen(cod)];
                    strcpy(this->cod, cod);
          }
          void setDenumire(char *denumire)
          {
                    this->denumire = new char[strlen(denumire)];
                    strcpy(this->denumire, denumire);
          }
          void setUm(char *um)
          {
                    this->um = new char[strlen(um)];
                    strcpy(this->um, um);
          }

          virtual ~Par() // este virtual pentru a putea fi suprascrisa in clasa derivate
          {
                    delete[] cod;
                    delete[] denumire;
                    delete[] um;
          };
};
typedef struct MAS
{
          int nr_crt, valoare;

} MAS;

class Pct
{
private:
          char locatie[10];
          Coord *pct; // coordonate punct măsură
          Par *par;   // listă parametri
          int nr_parametri;

public:
          Pct(char locatie[], Coord &pct, int nr_parametri, Par *par)
          {
                    strcpy(this->locatie, locatie);
                    this->pct = new Coord(pct);
                    this->par = new Par[nr_parametri];
                    for (int i = 0; i < nr_parametri; i++)
                    {
                              this->par[i] = par[i];
                    }
                    this->nr_parametri = nr_parametri;
          };
          virtual ~Pct() // este virtual pentru a putea fi suprascrisa in clasa derivate
          {
                    delete[] par;
                    delete[] pct;
          };

          const char *getLocatie() const
          {
                    return locatie;
          }

          const Coord *getPct() const
          {
                    return pct;
          }
          const Par *getPar() const
          {
                    return par;
          }
          const int getNrParametri() const
          {
                    return nr_parametri;
          }
          void setLocatie(char locatie[])
          {
                    strcpy(this->locatie, locatie);
          }
          void setPct(Coord &pct)
          {
                    this->pct = new Coord(pct);
          }
          void setPar(Par par)
          {
                    this->par = new Par(par);
          }
          void setNrParametri(int nr_parametri)
          {
                    this->nr_parametri = nr_parametri;
          }

          bool scrie_locatie_fisier(char *nume_fisier)
          {
                    return true;
          }; // scrie locația într-un fișier folosind bibliotecile ofstream
};
class Mas
{
private:
          MAS *val;
          int nr_masuratori;

public:
          Mas(int nr_masuratori, MAS &val)
          {
                    this->nr_masuratori = nr_masuratori;
                    this->val = new MAS(val);
          };
          ~Mas()
          {
                    delete[] val;
          };
          const int getNrMasuratori() const
          {
                    return nr_masuratori;
          }
          const MAS *getVal() const
          {
                    return val;
          }
          void setNrMasuratori(int nr_masuratori)
          {
                    this->nr_masuratori = nr_masuratori;
          }
          void setVal(MAS &val)
          {
                    this->val = new MAS(val);
          }
          Mas &operator[](int i)
          {
                    return this[i];
          }
          void adaugaMasuratori(MAS &val){};   // adaugă o nouă măsurare în lista măsurători
          void stergeMasuratori(int nr_crt){}; // șterge o măsurare din lista măsurători

          void afisareMasuratori(); // afișează lista măsurători folosind bibliotecile iostream
          virtual ~Mas()            // este virtual ptc altfel nu se apeleaza destructorul din clasa derivata
          {
                    delete[] val;
          };
};
void Mas::adaugaMasuratori(MAS &val)
{
          MAS *aux = new MAS[nr_masuratori + 1];
          for (int i = 0; i < nr_masuratori; i++)
          {
                    aux[i] = val[i];
          }
          aux[nr_masuratori] = val[nr_masuratori];
          delete[] val;
          val = aux;
          nr_masuratori++;
}
class PMas : public Pct, public Mas
{
public:
          PMas(char locatie[], Coord &pct, int nr_parametri, Par *par, int nr_masuratori, MAS &val) : Pct(locatie, pct, nr_parametri, par), Mas(nr_masuratori, val){};
          ~PMas() {}
};
int main()
{
          return 0;
}