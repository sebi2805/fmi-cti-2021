#include "FormatFizic.h"

FormatFizic::FormatFizic(FormatFizic &obj)
{
    carti = obj.carti;
    articole = obj.articole;
};
void FormatFizic ::print(std::ostream &) const
{
    std::cout << "Pentru acest material bilbiografica exista:" << std::endl;
    for (auto carte : carti)
    {
        std::cout << *carte;
    }
    for (auto articol : articole)
    {
        std::cout << *articol;
    }
};
void FormatFizic ::read(std::istream &is)
{
    int i;
    std::cout << "Cate carti vreti sa adaugati?" << std::endl;
    is >> i;
    std::shared_ptr<Carte> aux;
    for (int j = 0; j < i; j++)
    {
        aux = std::make_shared<Carte>();
        is >> *aux;
        carti.push_back(aux);
    }
    std::cout << "Cate articole vreti sa adaugati?" << std::endl;
    is >> i;
    std::shared_ptr<Articol> aux2;
    for (int j = 0; j < i; j++)
    {
        aux2 = std::make_shared<Articol>();
        is >> *aux2;
        articole.push_back(aux2);
    }
};
std::ostream &operator<<(std::ostream &os, const FormatFizic &obj)
{
    obj.print(os);
    return os;
};
std::istream &operator>>(std::istream &is, FormatFizic &obj)
{
    obj.read(is);
    return is;
};
void FormatFizic::searchByYear(int _an)
{
    for (auto carte : carti)
        carte->searchByYear(_an);
};
void FormatFizic::searchByName(std::string name)
{
    for (auto carte : carti)
        carte->searchByName(name);
};