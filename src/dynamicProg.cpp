#ifdef BUILD_PROGRAM_3

#include "dynamicProg.h"
#include "planet.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

DynamicProg::DynamicProg(std::vector<Planet> planets) {
  std::cout << "You entered: " << MAX << std::endl;
  std::vector<Planet> items;
  int i = 0;
  for (Planet p : Planet::planets) {
    items.push_back(p);
  }
  std::cout << "Item list: " << std::endl;
  for(int i = 0; i < items.size(); i++) {
    std::cout << items[i].toString() << std::endl;
  }

  int **profit = knapsack(items);

  // show table
  std::cout << std::endl << "Table: " << std::endl;
  for (int i = 1; i <= COUNT; i++) {
    std::cout << items[i-1].getName() << ": ";
    for(int j = 0; j <= MAX; j++)
      printf("%i,", profit[i][j]);
    std::cout << std::endl;
  }

  // show which are selected
  std::cout << std::endl << "Selection: " << std::endl;

  int totalWeight = 0;
  int totalProfit = 0;
  int size = MAX;

  for (int j = COUNT; j > 0; j--) {
    if(profit[j][size] != profit[j-1][size]) {
      std::cout << items[j-1].getName() << " selected: weight=" 
           << items[j-1].getWeight() << ", benefit=" 
           << items[j-1].getProfit() << std::endl;
      totalWeight += items[j-1].getWeight();
      totalProfit += items[j-1].getProfit();
      size -= items[j-1].getWeight();
    }
  }

  std::cout << std::endl << "Total weight = " << totalWeight;
  std::cout << std::endl << "Total profit = " << totalProfit;
}

int** DynamicProg::knapsack(std::vector<Planet> items) {
  int** profit = 0;
  profit = new int*[COUNT + 1];
  for (int x = 0; x <= COUNT; x++)
    profit[x] = new int[MAX + 1];
  for (int k = 0; k <= MAX; k++)
    profit[0][k] = 0;
  for (int i = 1; i <= COUNT; i++) {
    profit[i][0] = 0;
    for (int size = 1; size <= MAX; size++) {
      if (items[i-1].getWeight() > size)
        profit[i][size] = profit[i-1][size];
      else {
        profit[i][size] = std::max(profit[i-1][size], profit[i-1][size - items[i-1].getWeight()]+items[i-1].getProfit());
      }
    }
  }
  return profit;
}

#endif
