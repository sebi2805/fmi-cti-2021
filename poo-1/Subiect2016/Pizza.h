#ifndef PIZZA
#define PIZZA
#include <iostream>
#include <vector>
#include "Ingredient.h"
#include <memory>
#include <string.h>
#include "PrintRead.h"
class Pizza : public PrintRead
{
    static int codClass;
    int codPizza, nringPizza;
    char *denPizza;
    std::vector<std::shared_ptr<Ingrediente>> ingrediente;
    bool vegPizza;

public:
    Pizza(int nringPizza = 0,
          const char _denPizza[] = "undefined", std::vector<std::shared_ptr<Ingrediente>> ingrediente = {},
          bool vegPizza = false) : nringPizza(nringPizza), ingrediente(ingrediente), vegPizza(vegPizza)
    {
        denPizza = new char(strlen(_denPizza) - 1);
        strcpy(denPizza, _denPizza);
        codClass++;
        codPizza = codClass;
    };
    Pizza(const Pizza &);
    void print(std::ostream &) const override;
    Pizza &operator=(const Pizza &);
    Pizza &operator+(const Ingrediente &);
    Pizza &operator-(const Ingrediente &);
    void read(std::istream &) override;
    void addIngrediente();
    const char *nume() const;
    double pret() const;
    void nume(const char *aux);
    ~Pizza()
    {
        delete[] denPizza;
    }
};
#endif