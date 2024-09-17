#ifndef PRINTREAD
#define PRINTREAD
#include <iostream>
class PrintRead
{
public:
          PrintRead()
          {
          }
          virtual void print(std::ostream &) const = 0;
          virtual void read(std::istream &) = 0;
          virtual ~PrintRead() {}
};

#endif