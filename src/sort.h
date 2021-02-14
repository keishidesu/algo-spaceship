#ifdef BUILD_PROGRAM_1
#ifndef SORT_H
#define SORT_H

#include <vector>
#include "printable.h"
#include "planet.h"
#include "edge.h"

class Printable;
class Planet;
class Edge;

template <class T>
class Sort {
  static_assert(std::is_base_of<Printable, T>::value, "T must inherit from Printable");
  public:
    virtual void sort(std::vector<T> &list) = 0;
  private:
    virtual int compare(T a, T b) = 0;
};

template <class T>
class MergeSort : public Sort<T> {
  public:
    void sort(std::vector<T> &list);
  private:
    void merge(std::vector<T> &left, std::vector<T> &right, std::vector<T> &out);
    virtual int compare(T a, T b) = 0;
};

class MergeSortPlanet : public MergeSort<Planet> {
  private:
    int compare(Planet a, Planet b);
};

class MergeSortEdge : public MergeSort<Edge>  {
  private:
    int compare(Edge a, Edge b);
};

#endif
#endif