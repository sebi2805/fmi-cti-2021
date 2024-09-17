#include "Ingredient.h"
void Ingrediente::print(std::ostream &os) const
{
    os << "Ingredientuil este: " << denIng << " pretul este  " << pretIng
       << " cantitatea este " << cantIng << " unitatea de masura este " << masIng << std::endl;
};
void Ingrediente::read(std::istream &is)
{
    std::cout << "Care este denumirea ingredientului?" << std::endl;
    is >> denIng;
    std::cout << "Care este pretul ingredientului?" << std::endl;
    is >> pretIng;
    std::cout
        << "Care este cantitate ingredientului?" << std::endl;
    is >> cantIng;
    std::cout << "Care este unitatea de masura ingredientului?" << std::endl;
    is >> masIng;
};
double Ingrediente::getPricePerCantitate() const
{
    return pretIng * cantIng;
};
Ingrediente::Ingrediente(const Ingrediente &obj)
{
    denIng = obj.denIng;
    pretIng = obj.pretIng;
    cantIng = obj.cantIng;
    delete[] masIng;
    masIng = new char(strlen(obj.masIng) - 1);
    strcpy(masIng, obj.masIng);
};
Ingrediente &Ingrediente::operator++()
{
    cantIng++;
    return *this;
};
Ingrediente &Ingrediente::operator-=(double pret)
{
    pretIng -= pret;
};
std::ostream &operator<<(std::ostream &os, const Ingrediente &obj)
{
    obj.print(os);
};
bool Ingrediente::operator==(const Ingrediente &obj)
{
    if (pretIng != obj.pretIng)
        return false;
    if (cantIng != obj.cantIng)
        return false;
    if (denIng != obj.denIng)
        return false;
    if (strcmp(masIng, obj.masIng))
        return false;

    return true;
};
Ingrediente &Ingrediente::operator+(int i)
{
    cantIng += i;
};
std::istream &operator>>(std::istream &is, Ingrediente &obj)
{
    obj.read(is);
};