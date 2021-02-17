#if BUILD_GENERATOR

#include "generator.h"
#include "planet.h"
#include "vector3.h"
#include "edge.h"
#include <chrono>
#include <string>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <cstring>

#define PLANET_COUNT 10
#define FILE_NAME "A2planets.txt"

Generator::Generator() : Generator(new std::string[3] { "1171103211", "1171103378", "1171103504" }) {
  // do nothing
}

Generator::Generator(std::string studentId[]) {
  memcpy(this->studentId, studentId, 3 * sizeof(std::string));
}

// generates 10 numbers from id
void Generator::generateNumberGroup(std::string id, int a[]) {
    id += id;
    for (int i = 0; i < PLANET_COUNT; i++) {
      char t1[4] = {id[i], id[i+1], id[i+2], '\0'};
      a[i] = atoi(t1);
    }
}

void Generator::generatePlanet()
{
    std::string id1 = this->studentId[0];
    std::string id2 = this->studentId[1];
    std::string id3 = this->studentId[2];
    // reverse id1
    if ((id1.compare(id2) == 0) || (id1.compare(id3) == 0)) {
      std::reverse(id1.begin(), id1.end());
    }

    // reverse id2
    if (id2.compare(id3) == 0) {
      std::reverse(id2.begin(), id2.end());
    }

    int x[PLANET_COUNT], y[PLANET_COUNT], z[PLANET_COUNT];
    generateNumberGroup(id1, x);
    generateNumberGroup(id2, y);
    generateNumberGroup(id3, z);
    
    // reset random seed
    srand(time(0));

    // write to file
    std::ofstream file(FILE_NAME);
    std::cout << "Generating data ..." << std::endl;

    // initialise other planets
    int totalweight = 0;
    for (int i = 0; i < PLANET_COUNT; i++) {
      std::string name = "Planet_";
      name += char(65 + i);
      Planet planet(name, Vector3(x[i], y[i], z[i]), i == 0 ? Item(0, 0) : Item());
      planet.println();
      planet >> file;
      file << std::endl;
      totalweight += planet.getWeight();
    }

    file.close();
    std::cout << "Total weight: " << totalweight << std::endl;
    std::cout << std::endl << "Data generated." << std::endl;
}

#endif
