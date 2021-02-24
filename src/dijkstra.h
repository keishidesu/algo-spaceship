#if BUILD_PROGRAM_2

#ifndef DIJKSTRA_H
#define DIJKSTRA_H

#include <vector>
#include <string>
#include "edge.h"

class Dijkstra{
  public:
    Dijkstra(int** matrix, int init);
  private:
    int minDistance(int dist[], bool Tset[]);
    void printDistance(int distance[], std::string path[]);
    void printPath(std::string path[], int distance[]);
    void initmap(char m[7][7]);
    void connectEdges(char m[7][7], std::string path);
    void display(char m[7][7]);
};

#endif
#endif