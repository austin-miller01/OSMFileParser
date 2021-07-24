#include <iostream>
#include <string>
#include <cassert>
#include <cmath>
#include "../src/osm.hpp"

const double EPSILON = 1e-8;

bool equals(double num1, double num2);

int main() {
   Osm test = Osm("tests/map1.osm");

   assert(test.getNumNodes() == 174);
   assert(test.getNumWays() == 2);
   assert(test.getNumHighways() == 0);
   assert(equals(test.getMeanLat(), 52.17742537));
   assert(equals(test.getMeanLon(), -0.15598928));

   test.ParseOsmFile("tests/map2.osm");
   assert(test.getNumNodes() == 1341);
   assert(test.getNumWays() == 141);
   assert(test.getNumHighways() == 130);
   assert(equals(test.getMeanLat(), 35.06865228));
   assert(equals(test.getMeanLon(), -89.98088991));

   test.ParseOsmFile("tests/map3.osm");
   assert(test.getNumNodes() == 3830);
   assert(test.getNumWays() == 567);
   assert(test.getNumHighways() == 263);
   assert(equals(test.getMeanLat(), 19.43439364));
   assert(equals(test.getMeanLon(), -99.14117330));

   return 0;
}

bool equals(double num1, double num2) {
   return std::abs(num1 - num2) < EPSILON;
}
