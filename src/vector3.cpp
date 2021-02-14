#include "vector3.h"
#include <cmath>
#include <string>

Vector3::Vector3() : Vector3(0, 0, 0) {
  // do nothing
}

Vector3::Vector3(float x, float y, float z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

Vector3::Vector3(int x, int y, int z) {
  this->x = x;
  this->y = y;
  this->z = z;
}

float Vector3::getRelativeDistance(Vector3 other) {
  float xx = this->x - other.x;
  float yy = this->y - other.y;
  float zz = this->z - other.z;
  return xx * xx + yy * yy + zz * zz;
}

float Vector3::getRealDistance(Vector3 other) {
  return sqrtf(getRelativeDistance(other));
}

Vector3 Vector3::operator+(const Vector3& other) {
  return Vector3(
    this->x + other.x,
    this->y + other.y,
    this->z + other.z
  );
}

Vector3 Vector3::operator-(const Vector3& other) {
  return Vector3(
    this->x - other.x,
    this->y - other.y,
    this->z - other.z
  );
}

std::string Vector3::toString() {
  std::string sx = std::to_string(this->x);
  std::string sy = std::to_string(this->y);
  std::string sz = std::to_string(this->z);
  return "[X: " + sx + ", Y: " + sy + ", Z: " + sz + "]";
}

void Vector3::serialize(std::ofstream &ofile) {
  ofile
    << this->x << " "
    << this->y << " "
    << this->z;
}

void Vector3::deserialize(std::ifstream &ifile) {
  std::string sx, sy, sz;
  ifile >> sx >> sy >> sz;
  this->x = atof(sx.c_str());
  this->y = atof(sy.c_str());
  this->z = atof(sz.c_str());
}
