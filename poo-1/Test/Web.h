#ifndef WEB_H
#define WEB_H
#include <iostream>
#include "Cloneable.h"
class Web : public Cloneable
{
    std::string nume, titlu, url;
    int zi, luna, an;

public:
    Web(std::string nume = "undefined", std::string titlu = "undefined", std::string url = "undefined", int zi = 0,
        int luna = 0, int an = 0) : nume(nume), titlu(titlu), url(url), zi(zi), luna(luna), an(an){};
    Web(Web &);
    friend std::ostream &operator<<(std::ostream &, const Web &);
    friend std::istream &operator>>(std::istream &, Web &);
};
#endif