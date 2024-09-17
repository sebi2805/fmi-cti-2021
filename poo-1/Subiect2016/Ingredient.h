#ifndef INGREDIENT
#define INGREDIENT
#include <iostream>
#include "PrintRead.h"
#include <string.h>
class Ingrediente : public PrintRead
{
    std::string denIng;
    double pretIng;
    int cantIng;
    char *masIng;

public:
    Ingrediente(std::string denIng = "undefined",
                double pretIng = 0,
                int cantIng = 0,
                char *_masIng = "0") : denIng(denIng), pretIng(pretIng), cantIng(cantIng)
    {
        if (sizeof(_masIng) / sizeof(_masIng[0]) > 10)
            throw "MasIng prea lung";
        else
        {
            masIng = new char(strlen(_masIng) - 1);
            strcpy(masIng, _masIng);
        }
    };
    Ingrediente(const Ingrediente &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    double getPricePerCantitate() const;
    Ingrediente &operator++();
    Ingrediente &operator+(int);
    friend std::istream &operator>>(std::istream &, Ingrediente &);
    Ingrediente &operator-=(double);
    bool operator==(const Ingrediente &);
    friend std::ostream &operator<<(std::ostream &, const Ingrediente &);
    ~Ingrediente()
    {
        delete[] masIng;
    }
};
#endif