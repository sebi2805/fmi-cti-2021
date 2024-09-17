#include <iostream>
using namespace std;
#include "Interface.h"
// VIRTOPEANU SEBASTIAN GRUPA 264
// g++.exe (MinGW.org GCC-6.3.0-1) 6.3.0
int main()
{
          Interface menu;
          try
          {
                    menu.start();
          }
          catch (const char *s)
          {
                    cout << s;
          }
          catch (...)
          {
                    cout << "An error has occured in start from interface";
          }
          return 0;
}