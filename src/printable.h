#ifndef PRINTABLE_H
#define PRINTABLE_H

#include <string>

class Printable {
  public:
    void print();
    void println();
    virtual std::string toString() = 0;
};

#endif