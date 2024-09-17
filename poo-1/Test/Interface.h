#ifndef INTERFACE
#define INTERFACE
#include <iostream>
#include <vector>
#include "FormatFizic.h"
#include <memory>
#include "FormatElectronic.h"
class Interface
{
    std::vector<std::shared_ptr<FormatElectronic>> formatElectronic;
    std::vector<std::shared_ptr<FormatFizic>> formatFizic;

public:
    void start();
};
#endif