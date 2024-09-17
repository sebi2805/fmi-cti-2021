#include <iostream>
#include <vector>
#include "Angajat.h"
#include <memory>
class Interface
{
    std::vector<std::shared_ptr<Angajat>> anagajati;

public:
    void start();
};