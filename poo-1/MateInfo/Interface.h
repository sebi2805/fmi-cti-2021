#ifndef INTERFACE
#define INTERFACE
#include "Comanda.h"
#include "Vaccin.h"
class Interface
{
          std::vector<std::shared_ptr<Comanda>> comenzi;
          std::vector<std::shared_ptr<Vaccin>> vaccinuri;

public:
          Interface() {}
          void start();
};
#endif