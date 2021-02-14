#include "serializable.h"
#include <stdexcept>

void Serializable::operator>>(std::ofstream &ofile) {
  if (!ofile.is_open()) throw std::runtime_error("file not open!");
  serialize(ofile);
}

void Serializable::operator<<(std::ifstream &ifile) {
  if (!ifile.is_open()) throw std::runtime_error("file not open!");
  deserialize(ifile);
}
