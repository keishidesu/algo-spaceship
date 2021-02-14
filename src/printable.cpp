#include "printable.h"
#include <iostream>

void Printable::print() {
  std::cout << this->toString();
}

void Printable::println() {
  print();
  std::cout << std::endl;
}
