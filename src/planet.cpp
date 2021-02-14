#include <iostream>
#include <stdexcept>
#include "planet.h"
#include "edge.h"

// class variables
std::vector<Planet> Planet::planets;

Planet::Planet() {
  this->name = "";
  this->coordinate = Vector3();
  this->item = Item(0, 0);
}

Planet::Planet(std::string name, Vector3 coordinate, Item item) {
  this->name = name;
  this->coordinate = coordinate;
  this->item = item;
  
  for (Planet p : Planet::planets) {
    if (this->name == p.name) {
      throw std::logic_error("planet duplications");
    }
  }
  Planet::planets.push_back(*this);
}

void Planet::addNeighbours(Planet& other) {
  for (Planet p : this->neighbours) {
    if (p.name == other.name) {
      throw std::logic_error("neighbour planet duplications");
    }
  }
  this->neighbours.push_back(other);
  other.neighbours.push_back(*this);
  Edge::edges.push_back(Edge(*this, other));
}

void Planet::printNeighbours() {
  std::string s = "[" + this->name + " <-> ";
  for (int i = 0; i < this->neighbours.size(); i++) {
    Planet p = this->neighbours.at(i);
    s += p.name + ((i < this->neighbours.size() - 1) ? ", " : "");
  }
  std::cout << s << "]" << std::endl;
}

void Planet::serialize(std::ofstream &ofile) {
  ofile << this->name << " ";
  this->coordinate >> ofile;
  ofile << " ";
  this->item >> ofile;
}

void Planet::deserialize(std::ifstream &ifile) {
  ifile >> this->name;
  this->coordinate << ifile;
  this->item << ifile;
  // register to the pool too
  for (Planet p : Planet::planets) {
    if (this->name == p.name) {
      throw std::logic_error("planet duplications");
    }
  }
  Planet::planets.push_back(*this);
}

std::string Planet::getName() {
  return this->name;
}

std::string Planet::toString() {
  return "[Name: " + this->name + ", " + this->coordinate.toString() + ", " + this->item.toString() + "]";
}

float Planet::getDistance(Planet other) {
  return this->coordinate.getRealDistance(other.coordinate);
}

float Planet::getValue() {
  return this->item.getValue();
}

int Planet::getProfit() {
  return this->item.getProfit();
}

int Planet::getWeight() {
  return this->item.getWeight();
}
