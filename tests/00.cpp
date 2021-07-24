#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "../src/osm.hpp"

const double EPSILON = 1e-8;

bool equals(double num1, double num2);

int main() {
   Osm test = Osm("tests/map1.osm");

   test.ParseOsmFile("tests/map2.osm");
   assert(test.getNumNodes() == 1341);
   assert(equals(test.getMeanLat(), 35.06865228));
   assert(equals(test.getMeanLon(), -89.98088991));
   return 0;
}

bool equals(double num1, double num2) {
   return std::abs(num1 - num2) < EPSILON;
}