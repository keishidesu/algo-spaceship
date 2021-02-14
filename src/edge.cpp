#include "edge.h"

std::vector<Edge> Edge::edges;

Edge::Edge() {
  // do nothing
}

Edge::Edge(Planet p1, Planet p2) {
  this->length = p1.getDistance(p2);
  this->p1 = p1;
  this->p2 = p2;
}

float Edge::getLength() {
  return this->length;
}

std::string Edge::toString() {
  std::string sl = std::to_string(this->length);
  return "[" + this->p1.getName() + " <-> " + this->p2.getName() + ", Distance: " + sl + "]";
}
