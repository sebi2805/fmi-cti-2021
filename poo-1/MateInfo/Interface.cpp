#include "Interface.h"
#include "VaccinAntiGripa.h"
#include "VaccinCovid.h"
#include "VaccinHepatita.h"
void Interface::start()
{
          int i = 1;
          while (i)
          {
                    std::cout << "Ce doriti sa faceti?\n1.Afisarea tuturor vaccinurilor\n2.Adaugare vaccin nou\n3.Numele producatorilor\n4.Adaugarea unei comenzi noi";
                    std::cout << "\n5.Afisarea tuturor comenzilor\n6.Valoarea comenzirlor\n";
                    std::cin >> i;
                    switch (i)
                    {
                    case 1:

                    {
                              for (auto vac : vaccinuri)
                                        vac->print(std::cout);
                              break;
                    }
                    case 2:
                    {
                              int k, m;
                              std::cout << "Cate vaccinuri vreti sa adaugati?" << std::endl;
                              std::cin >> m;
                              std::shared_ptr<Vaccin> aux;
                              for (int j = 0; j < m; j++)
                              {
                                        std::cout << "Ce tip de vaccin este?\n1.AntiCovid\n2.AntiGripal\n3.AntiHepatita" << std::endl;
                                        std::cin >> k;
                                        if (k == 1)
                                                  aux = std::make_shared<VaccinCovid>();
                                        else if (k == 2)
                                                  aux = std::make_shared<VaccinAntiGripa>();
                                        else if (k == 3)
                                                  aux = std::make_shared<VaccinHepatita>();
                                        else
                                                  throw "Acest tip nu exista";
                                        aux->read(std::cin);
                                        vaccinuri.push_back(aux);
                              }
                              break;
                    }
                    case 3:
                    {
                              for (auto vac : vaccinuri)
                                        std::cout << vac->getNume() << " " << std::endl;
                              break;
                    }
                    case 4:
                    {
                              int k;
                              std::shared_ptr<Comanda> aux;
                              aux = std::make_shared<Comanda>();
                              aux->read(std::cin);
                              int i;
                              std::cout << "Cate vaccinuri vreti sa adaugati?" << std::endl;
                              std::cin >> i;
                              for (int j = 0; j < i; j++)
                              {
                                        std::cout << "Ce vaccin vreti sa adaugati?" << std::endl;
                                        int m = 0;
                                        for (auto vac : vaccinuri)
                                        {
                                                  std::cout << m + 1 << ".";
                                                  m++;
                                                  vac->print(std::cout);
                                                                                }

                                        std::cin >> k;
                                        std::cout << "Si in ce cantitate?" << std::endl;
                                        int cant;
                                        std::cin >> cant;
                                        aux->addVaccin(vaccinuri[k - 1], cant);
                              }
                              comenzi.push_back(aux);
                              break;
                    }
                    default:
                              break;
                    }
          }
}