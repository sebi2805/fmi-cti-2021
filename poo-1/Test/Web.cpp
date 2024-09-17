#include "Web.h"
Web::Web(Web &obj)
{
    nume = obj.nume;
    titlu = obj.titlu;
    url = obj.url;
    zi = obj.zi;
    luna = obj.luna;
    an = obj.an;
};
std::ostream &operator<<(std::ostream &os, const Web &obj)
{
    os << "Titlul siteului este " << obj.titlu << " detinut de " << obj.nume << " la url: " << obj.url << " in data de "
       << obj.zi << "." << obj.luna << "." << obj.an << std::endl;
    return os;
};
std::istream &operator>>(std::istream &is, Web &obj)
{
    std::cout << "Care este numele proprietarului?" << std::endl;
    is >> obj.nume;
    std::cout << "Care este titlu?" << std::endl;
    is >> obj.titlu;
    std::cout << "Care este url?" << std::endl;
    is >> obj.url;
    std::cout << "Care este ziua?" << std::endl;
    is >> obj.zi;
    std::cout << "Care este luna?" << std::endl;
    is >> obj.luna;
    std::cout << "Care este an?" << std::endl;
    is >> obj.an;
    return is;
};