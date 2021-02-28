#if BUILD_PROGRAM_3

#ifndef DYNAMICPROG_H
#define DYNAMICPROG_H

#include <string>
#include <vector>

#include "planet.h"

class DynamicProg {
  public: 
    DynamicProg(std::vector<Planet> planets);
    const int MAX = 80;
    const int COUNT = 10;
    int** knapsack(std::vector<Planet> items);
};

#endif
#endif