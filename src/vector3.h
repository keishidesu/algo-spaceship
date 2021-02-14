#ifndef VECTOR3_H
#define VECTOR3_H

#include "serializable.h"
#include "printable.h"

class Serializable;
class Printable;

class Vector3 : public Serializable, public Printable {
  public:
    Vector3();
    Vector3(float x, float y, float z);
    Vector3(int x, int y, int z);
    float getRelativeDistance(Vector3 other);
    float getRealDistance(Vector3 other);
    Vector3 operator+(const Vector3& other);
    Vector3 operator-(const Vector3& other);
    std::string toString();
  private:
    float x;
    float y;
    float z;
    void serialize(std::ofstream &ofile);
    void deserialize(std::ifstream &ifile);
};

#endif