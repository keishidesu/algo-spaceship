#ifdef BUILD_PROGRAM_2

#define SIZE 10
#define INF 999999999

#include "dijkstra.h"
#include "edge.h"
#include "planet.h"

#include <string>
#include <vector>
#include <iostream>

Dijkstra::Dijkstra(int** matrix, int init){
  int distance[SIZE];
  std::string path[SIZE];
  bool visited[SIZE];
  for (int i = 0; i < SIZE; i++) {
    distance[i] = INF;
    visited[i] = false;
  }
  distance[init] = 0;

  for(int i = 0; i < SIZE; i++){
    int index = minDistance(distance, visited);
    visited[index] = true;
    if (path[index].find((char)(index + 65)) == std::string::npos)
      path[index] += std::string(1, (char)(index + 65));
    for(int j = 0; j < SIZE; j++){
      if(!visited[j] && matrix[index][j] > 0 && distance[index] != INF && distance[index] + matrix[index][j] < distance[j]){
        std::cout << "distance: " << distance[index] << "matrix: " << matrix[index][j] << std::endl;
        distance[j] = distance[index] + matrix[index][j];
        path[j] = path[index] + (char)(j + 65);
      }
    }
  }

  printDistance(distance, path);
  printPath(path, distance);

}

int Dijkstra::minDistance(int dist[], bool Tset[]) { 
  int min = INF, index = 0;
              
	for(int i = 0;i < SIZE; i++) {
		if(Tset[i] == false && dist[i] <= min) {
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void Dijkstra::printDistance(int distance[], std::string path[]){
  std::cout << "Planets list" << std::endl;
  for(int i = 0; i < SIZE; i++){
    char planet = 65 + i;
    int pd = i == 0 ? -1 : (int)path[i][path[i].length()-2]-65;
		std::cout << i << ":" << Planet::planets[i].toString() << ", [Distance:" << distance[i] << "], " << "[Predecessor: " << pd << "]" << std::endl;
  }
}

void Dijkstra::initmap(char m[7][7])
{
  for (int i=0; i<7; i++)
    for (int j=0; j<7; j++)
      m[i][j] = ' ';
}

void connect(char m[7][7], int a, int b) {
  switch (a) {
    case 1:
      m[0][3] = 'A';
      if (b == 4) {
        m[2][0] = 'D';
        m[0][0] = '+';
        m[0][1] = '-';
        m[0][2] = '-';
        m[1][0] = '|';
      }
      else if (b == 6) {
        m[2][6] = 'F';
        m[0][6] = '+';
        m[0][5] = '-';
        m[1][6] = '|';
      }
      else if (b == 10) {
        m[2][2] = 'J';
        m[0][2] = '+';
        m[1][2] = '|';
      }
      else if (b == 8) {
        m[2][4] = 'H';
        m[0][4] = '+';
        m[1][4] = '|';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 2: 
      m[4][0] = 'B';
      if (b == 4) {
        m[2][0] = 'D';
        m[3][0] = '|';
      }
      else if (b == 5) {
        m[6][3] = 'E';
        m[6][0] = '+';
        m[6][1] = '-';
        m[6][2] = '-';
        m[5][0] = '|';
      }
      else if (b == 7) {
        m[4][2] = 'G';
        m[4][1] = '-';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 3:
      m[4][6] = 'C';
      if (b == 6) {
        m[2][6] = 'F';
        m[3][6] = '|';
      }
      else if (b == 5) {
        m[6][3] = 'E';
        m[6][6] = '+';
        m[6][5] = '-';
        m[6][4] = '-';
        m[5][6] = '|';
      }
      else if (b == 9) {
        m[4][4] = 'I';
        m[4][5] = '-';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 4:
      m[2][0] = 'D';
      if (b == 10) {
        m[2][2] = 'J';
        m[2][1] = '-';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 5:
      m[6][3] = 'E';
      if (b == 7) {
        m[4][2] = 'G';
        m[6][2] = '+';
        m[5][2] = '|';
      }
      else if (b == 9) {
        m[4][4] = 'I';
        m[6][4] = '+';
        m[5][4] = '|';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 6:
      m[2][6] = 'F';
      if (b == 8) {
        m[2][4] = 'H';
        m[2][5] = '-';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 7:
      m[4][2] = 'G';
      if (b == 10) {
        m[2][2] = 'J';
        m[3][2] = '|';
      }
      else if (b == 9) {
        m[4][4] = 'I';
        m[4][3] = '-';
      }
      else {
        connect(m, b, a);
      }
      break;
    case 8:
      m[2][4] = 'H';
      if (b == 10) {
        m[2][2] = 'J';
        m[2][3] = '-';
      }
      else if (b == 9) {
        m[4][4] = 'I';
        m[3][4] = '|';
      }
      else{
        connect(m, b, a);
      }
      break;
  }
}

void Dijkstra::connectEdges(char m[7][7], std::string path){
  for(int i = 1; i < path.size(); i++){
    connect(m, (int)path[i - 1] - 64, (int)path[i] - 64);
  }
}

void Dijkstra::display(char m[7][7])
{
  std::cout << std::endl;
  for (int i = 0; i < 7; i++) {
    std::cout << "  ";
    for (int j = 0; j < 7; j++)
      std::cout << m[i][j];
    std::cout << std::endl;
  }
}

void Dijkstra::printPath(std::string path[], int distance[]){
  char map[7][7];
  initmap(map);
  for(int i = 0; i < SIZE; i++){
    if(distance[i] == 0) continue;
    connectEdges(map, path[i]);
  }
  display(map);
}
#endif