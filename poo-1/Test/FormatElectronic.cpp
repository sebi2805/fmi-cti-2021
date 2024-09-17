#include "FormatElectronic.h"
FormatElectronic::FormatElectronic(FormatElectronic &obj)
{
    materiale = obj.materiale;
};
void FormatElectronic ::print(std::ostream &) const
{
    std::cout << "Pentru acest material bilbiografica exista:" << std::endl;
    for (auto material : materiale)
    {
        std::cout << *material;
    }
};
void FormatElectronic ::read(std::istream &is)
{
    int i;
    std::cout << "Cate pagini web vreti sa adaugati?" << std::endl;
    is >> i;
    std::shared_ptr<Web> aux;
    for (int j = 0; j < i; j++)
    {
        aux = std::make_shared<Web>();
        is >> *aux;
        materiale.push_back(aux);
    }
};
std::ostream &operator<<(std::ostream &os, const FormatElectronic &obj)
{
    obj.print(os);
    return os;
};
std::istream &operator>>(std::istream &is, FormatElectronic &obj)
{
    obj.read(is);
    return is;
};