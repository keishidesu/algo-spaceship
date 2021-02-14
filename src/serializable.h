#ifndef SERIALIZABLE_H
#define SERIALIZABLE_H

#include <fstream>
#include <string>

class Serializable {
  public:
    void operator>>(std::ofstream &ofile);
    void operator<<(std::ifstream &ifile);
  private:
    virtual void serialize(std::ofstream &ofile) = 0;
    virtual void deserialize(std::ifstream &ifile) = 0;
};

#endif