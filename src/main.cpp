#include <iostream>
#include <fstream>

#ifdef BUILD_GENERATOR
#include "generator.h"
#endif

#ifndef BUILD_GENERATOR
#include "planet.h"
#endif

#ifdef BUILD_PROGRAM_1
#include "sort.h"
#include "edge.h"
#endif

#define PLANET_COUNT 10
#define FILE_NAME "A2planets.txt"

#ifndef BUILD_GENERATOR
void loadPlanets(int count) {
  std::ifstream file(FILE_NAME);
  for (int i = 0; i < count; i++) {
    Planet planet;
    planet << file;
  }
}

void setupStaticRelationship() {
  Planet::planets[0].addNeighbours(Planet::planets[3]);
  Planet::planets[0].addNeighbours(Planet::planets[9]);
  Planet::planets[0].addNeighbours(Planet::planets[7]);
  Planet::planets[0].addNeighbours(Planet::planets[5]);

  Planet::planets[3].addNeighbours(Planet::planets[9]);
  Planet::planets[9].addNeighbours(Planet::planets[7]);
  Planet::planets[7].addNeighbours(Planet::planets[5]);

  Planet::planets[3].addNeighbours(Planet::planets[1]);
  Planet::planets[9].addNeighbours(Planet::planets[6]);
  Planet::planets[7].addNeighbours(Planet::planets[8]);
  Planet::planets[5].addNeighbours(Planet::planets[2]);

  Planet::planets[1].addNeighbours(Planet::planets[6]);
  Planet::planets[6].addNeighbours(Planet::planets[8]);
  Planet::planets[8].addNeighbours(Planet::planets[2]);

  Planet::planets[4].addNeighbours(Planet::planets[1]);
  Planet::planets[4].addNeighbours(Planet::planets[6]);
  Planet::planets[4].addNeighbours(Planet::planets[8]);
  Planet::planets[4].addNeighbours(Planet::planets[2]);
}
#endif

#ifdef BUILD_GENERATOR
bool isValid(std::string id) {
  for (int i = 0; i < id.size(); i++) {
    if (!isdigit(id[i]) || i >= 10) {
      std::cout << " invalid id!" << std::endl;
      return false;
    }
  }
  return true;
}
#endif

int main()
{
#ifdef BUILD_GENERATOR
#ifndef BUILD_DEBUG
  std::string student[3];
  for (int i = 0; i < 3; i++) {
    do {
      try {
        std::cout << "Enter student ID " << i + 1 << ": ";
        std::cin >> student[i];
      } catch (...) {
        std::cout << " invalid input!" << std::endl;
        continue;
      }
    } while (!isValid(student[i]));
  }
  Generator generator(student);
#else
  Generator generator;
#endif
  generator.generatePlanet();
#endif

#ifdef BUILD_PROGRAM_1
  // expecting 10 planets...
  loadPlanets(PLANET_COUNT);
  setupStaticRelationship();
  // adjacency list
  std::cout << "Planets adjacency list:" << std::endl;
  for (Planet p : Planet::planets) {
    p.printNeighbours();
  }
  // merge sort planets
  MergeSortPlanet sortPlanet;
  sortPlanet.sort(Planet::planets);
  std::cout << "Planets sorted by values:" << std::endl;
  for (Planet p : Planet::planets) {
    std::cout << "[Name: " << p.getName() << ", Value: " << p.getValue() << "]" << std::endl;
  }
  // merge sort edges
  MergeSortEdge sortEdge;
  sortEdge.sort(Edge::edges);
  std::cout << "Edges sorted by distance:" << std::endl;
  for (Edge e : Edge::edges) {
    e.println();
  }
#endif

  return 0;
}
