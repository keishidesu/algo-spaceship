#ifdef BUILD_PROGRAM_2

#include "dijkstra.h"
#include "edge.h"

#define SIZE Edge::Edges.size()

#include <string>
#include <limits.h> 

Dijkstra::Dijkstra(int src){
  int dist[SIZE];

  bool sptSet[SIZE];

  for(int i = 0; i < SIZE; i++)
    dist[i] = INT_MAX, sptSet[i] = false;

  dist[src] = 0;

  for(int i = 0; i < SIZE; i++){
    int u = minDistance(dist, sptSet);

    sptSet[u] = true;

    for(int j = 0; j < SIZE; j++){
      if(!sptSet[j] && )
    }
  }

}

int minDistance(int dist[], bool sptSet[]){
  int min = INT_MAX, min_index; 

  for (int v = 0; v < V; v++) 
    if (sptSet[v] == false && dist[v] <= min) 
      min = dist[v], min_index = v; 

  return min_index; 
} 

#endif