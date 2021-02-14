#if BUILD_GENERATOR
#ifndef GENERATOR_H
#define GENERATOR_H

#include <string>

class Generator {
  public:
    Generator();
    Generator(std::string studentId[3]);
    void generatePlanet();
  private:
    std::string studentId[3];
    void generateNumberGroup(std::string id, int a[]);
};

#endif
#endif
