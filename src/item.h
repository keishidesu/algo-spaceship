#ifndef ITEM_H
#define ITEM_H

#include "serializable.h"
#include "printable.h"
#include <string>

class Serializable;
class Printable;

class Item : public Serializable, public Printable {
  public:
    Item();
    Item(int profit, int weight);
    int getProfit();
    int getWeight();
    float getValue();
    std::string toString();
  private:
    int profit;
    int weight;
    float value;
    void serialize(std::ofstream &ofile);
    void deserialize(std::ifstream &ifile);
};

#endif