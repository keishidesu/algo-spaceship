#ifndef EDGE_H
#define EDGE_H

#include <string>
#include "planet.h"
#include "printable.h"

class Printable;
class Planet;

class Edge : public Printable {
  public:
    // class variables
    static std::vector<Edge> edges;

    Edge();
    Edge(Planet p1, Planet p2);
    float getLength();
    std::string getName();
    std::string toString();
  private:
    Planet p1;
    Planet p2;
    float length;
    std::string name;
};

#endif
