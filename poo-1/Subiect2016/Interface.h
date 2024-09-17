#ifndef INTERFACE
#define INTERFACE
#include <iostream>
#include <vector>
#include <memory>
#include "Pizza.h"
class Interface
{
    std::vector<std::shared_ptr<Pizza>> pizza;

public:
    void start();
};
#endif