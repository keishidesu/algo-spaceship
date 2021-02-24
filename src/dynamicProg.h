#if BUILD_PROGRAM_3

#ifndef DYNAMICPROG_H
#define DYNAMICPROG_H

#include <string>
#include <vector>

#include "planet.h"

class DynamicProg {
  public: 
    const int MAX = 80;
    const int COUNT = 10;
    std::vector<Planet> items;
    DynamicProg(std::vector<Planet> planets);
    // void knapsack01(Planet items, int weight);
};

#endif
#endif