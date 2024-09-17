#include "Pizza.h"
void Pizza::print(std::ostream &os) const
{
    double pretPizza = 0;
    for (auto ingr : ingrediente)
    {
        pretPizza += ingr->getPricePerCantitate();
    }
    os << "Numele pizzei cu codul:" << codPizza << " este " << denPizza
       << " pretul pentru aceasta este " << pretPizza << " "
       << "are un numar de ingrediente "
       << nringPizza << std::endl;
    if (vegPizza)
        os << "Pizza este vegana" << std::endl;
    else
        os << "Pizza nu este vegana" << std::endl;
    for (auto ingr : ingrediente)
        ingr->print(os);
};
void Pizza::read(std::istream &is)
{
    std::cout << "Introduceti numele pizzei?" << std::endl;
    is >> denPizza;
    std::cout << "Pizza este vegana?" << std::endl;
    is >> vegPizza;
    std::cout << "Cate ingrediente vreti sa adaugati?" << std::endl;
    is >> nringPizza;
    std::shared_ptr<Ingrediente> aux;
    for (int i = 0; i < nringPizza; i++)
    {
        aux = std::make_shared<Ingrediente>();
        aux->read(is);
        ingrediente.push_back(aux);
    }
};
void Pizza::addIngrediente()
{
    int i;
    std::cout << "Cate ingrediente vreti sa adaugati?" << std::endl;
    std::cin >> i;
    std::shared_ptr<Ingrediente> aux;
    for (int i = 0; i < nringPizza; i++)
    {
        aux = std::make_shared<Ingrediente>();
        aux->read(std::cin);
        ingrediente.push_back(aux);
    }
};
int Pizza::codClass = 0;
const char *Pizza::nume() const
{
    return denPizza;
};
double Pizza::pret() const
{
    double pretPizza = 0;
    for (auto ingr : ingrediente)
    {
        pretPizza += ingr->getPricePerCantitate();
    }
    return pretPizza;
};
Pizza::Pizza(const Pizza &obj)
{
    delete[] denPizza;
    denPizza = new char(strlen(obj.denPizza));
    strcpy(denPizza, obj.denPizza);
    codClass++;
    codPizza = codClass;
    nringPizza = obj.nringPizza;
    vegPizza = obj.vegPizza;
    ingrediente = obj.ingrediente;
};
Pizza &Pizza::operator=(const Pizza &obj)
{
    delete[] denPizza;
    denPizza = new char(strlen(obj.denPizza));
    strcpy(denPizza, obj.denPizza);
    codClass++;
    codPizza = codClass;
    nringPizza = obj.nringPizza;
    vegPizza = obj.vegPizza;
    ingrediente = obj.ingrediente;
    return *this;
};
Pizza &Pizza::operator+(const Ingrediente &obj)
{
    std::shared_ptr<Ingrediente> aux;
    *aux = obj;
    ingrediente.push_back(aux);
    return *this;
};
Pizza &Pizza::operator-(const Ingrediente &obj)
{
    for (auto i : ingrediente)
    {
        if (*i == obj)
        {
            // ingrediente.erase(i);
        }
    }
    return *this;
};
void Pizza::nume(const char *aux)
{
    delete[] denPizza;
    denPizza = new char(strlen(aux) - 1);
    strcpy(denPizza, aux);
};