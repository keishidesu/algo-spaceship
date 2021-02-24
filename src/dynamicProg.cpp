#ifdef BUILD_PROGRAM_3

#include "dynamicProg.h"
#include "planet.h"

#include <string>
#include <vector>
#include <iostream>
#include <fstream>

// Program 4 – Dynamic Programming. Your spaceship has the capacity of 80 tons.
// Write a program to identify the set of planets to visit without returning to home
// planet, using the 0/1 Knapsack Algorithm (assume that if you reach a planet, you
// have to take all the items/products). Display the resulting matrix and the list of
// planets to visit, with the weights and benefits from each planet.

DynamicProg::DynamicProg(std::vector<Planet> planets) {
  std::cout<< "you entered: " << MAX << std::endl;
  std::vector<Planet> items;
  int i = 0;
  for (Planet p : Planet::planets) {
    items.push_back(p);
  }
  std::cout << "Item list: " << std::endl;
  for(int i = 0; i < items.size(); i++) {
    std::cout << items[i].toString() << std::endl;
  }

  int profit[COUNT+1][MAX+1];
  int itemprofit;
  for(int k=0; k<=MAX; k++)
    profit[0][k] = 0;
  for(int i=1; i<=COUNT; i++) {
    profit[i][0] = 0;
    for (int size=1; size <= MAX; size++) {
      if (items[i-1].getWeight() > size)
        profit[i][size] = profit[i-1][size];
      else {
        profit[i][size] = std::max(profit[i-1][size], profit[i-1][size - items[i-1].getWeight()]+items[i-1].getProfit());
      }
    }
  }

  std::cout << std::endl << "Table: " << std::endl;
  for(int i = 1; i <= COUNT; i++) {
    std::cout << items[i-1].getName() << ": ";
    for(int j = 0; j <= MAX; j++)
      std::cout << profit[i][j] << " ";
    std::cout << std::endl;
  }

  std::cout << std::endl << "Selection: " << std::endl;

  int itemIndex = 1;
  int totalWeight = 0;
  int totalProfit = 0;
  int size = MAX;

  for(int j = COUNT; j > 0; j--) {
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

// void DynamicProg::knapsack01(Planet items, int weight) {
//   int profit[COUNT+1][MAX+1];
//   int itemprofit;
//   for(int k=0; k<=MAX; k++)
//     profit[0][k] = 0;
//   for(int i=1; i<=COUNT; i++) {
//     profit[i][0] = 0;
//     for (int size=1; size <= MAX; size++) {
//       if (items[i-1].getWeight > size)
//         profit[i][size] = profit[i-1][size];
//       else
//         profit[i][size] = std::max(profit[i-1][size], profit[i-1][size - items[i-1].getWeight]+items[i-1].getProfit);
//     }
//   }
// }

#endif
