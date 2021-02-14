#ifndef PLANET_H
#define PLANET_H

#include <string>
#include <vector>
#include "serializable.h"
#include "printable.h"
#include "vector3.h"
#include "item.h"

class Serializable;
class Printable;
class Vector3;
class Item;

class Planet : public Serializable, public Printable {
  public:
    // class variables
    static std::vector<Planet> planets;

    Planet();
    Planet(std::string name, Vector3 coordinate, Item item);
    void addNeighbours(Planet& other);
    void printNeighbours();
    std::string getName();
    float getDistance(Planet other);
    float getValue();
    int getProfit();
    int getWeight();
    std::string toString();
  private:
    std::string name;
    Vector3 coordinate;
    Item item;
    std::vector<Planet> neighbours;
    void serialize(std::ofstream &ofile);
    void deserialize(std::ifstream &ifile);
};

#endif