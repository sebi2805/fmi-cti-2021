#ifndef FORMATFIZIC
#define FORMATFIZIC
#include <iostream>
#include <memory>
#include <vector>
#include "Bibliografie.h"
#include "Carte.h"
#include "Articole.h"
#include "Cloneable.h"
class FormatFizic : public Bibliografie, public Cloneable
{
    std::vector<std::shared_ptr<Carte>> carti;
    std::vector<std::shared_ptr<Articol>> articole;

public:
    FormatFizic(std::vector<std::shared_ptr<Carte>> carti = {}, std::vector<std::shared_ptr<Articol>> articole = {}) : carti(carti), articole(articole){};
    FormatFizic(FormatFizic &);
    void print(std::ostream &) const override;
    void read(std::istream &) override;
    friend std::ostream &operator<<(std::ostream &, const FormatFizic &);
    friend std::istream &operator>>(std::istream &, FormatFizic &);
    void searchByYear(int _an);
    void searchByName(std::string name);
};
#endif