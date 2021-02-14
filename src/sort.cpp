#ifdef BUILD_PROGRAM_1
#include "sort.h"
#include <iostream>

template<class T>
void MergeSort<T>::sort(std::vector<T> &list) {
  if (list.size() <= 1) return;

  int mid = list.size() / 2;
  std::vector<T> left(list.begin(), list.end() - mid);
  std::vector<T> right(list.begin() + mid + ((list.size() % 2 != 0) ? 1 : 0), list.end());

  sort(left);
  sort(right);
  merge(left, right, list);
}

template<class T>
void MergeSort<T>::merge(std::vector<T> &left, std::vector<T> &right, std::vector<T> &out) {
  int i = 0, j = 0, k = 0;
  while (j < left.size() && k < right.size()) {
    if (compare(left[j], right[k]) <= 0) {
      out[i++] = left[j++];
    } else {
      out[i++] = right[k++];
    }
  }
  while (j < left.size()) {
    out[i++] = left[j++];
  }
  while (k < right.size()) {
    out[i++] = right[k++];
  }
}

int MergeSortPlanet::compare(Planet a, Planet b) {
  if (a.getValue() > b.getValue()) {
    return -1;
  } else if (a.getValue() < b.getValue()) {
    return 1;
  } else {
    return 0;
  }
}

int MergeSortEdge::compare(Edge a, Edge b) {
  if (a.getLength() > b.getLength()) {
    return 1;
  } else if (a.getLength() < b.getLength()) {
    return -1;
  } else {
    return 0;
  }
}

#endif