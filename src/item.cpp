#include "item.h"

Item::Item() : Item((rand() % 16 + 5) * 10, rand() % 16 + 5) {
  // do nothing
}

Item::Item(int profit, int weight) {
  this->profit = profit;
  this->weight = weight;
  this->value = (weight == 0) ? 0 : (float)profit / (float)weight;
}

int Item::getProfit() {
  return this->profit;
}

int Item::getWeight() {
  return this->weight;
}

float Item::getValue() {
  return this->value;
}

std::string Item::toString() {
  std::string sp = std::to_string(this->profit);
  std::string sw = std::to_string(this->weight);
  return "[Profit: " + sp + ", Weight: " + sw + "]"; 
}

void Item::serialize(std::ofstream &ofile) {
  ofile
    << this->weight << " "
    << this->profit;
}

void Item::deserialize(std::ifstream &ifile) {
  std::string sp, sw;
  ifile >> sw >> sp;
  this->weight = atoi(sw.c_str());
  this->profit = atoi(sp.c_str());
  this->value = (weight == 0) ? 0 : (float)profit / (float)weight;
}
