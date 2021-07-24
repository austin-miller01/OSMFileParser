#include <iostream>
#include <string>
#include <cassert>
#include "../src/osm.hpp"

int main() {
   Osm test = Osm("tests/map1.osm");

   test.ParseOsmFile("tests/map3.osm");
   assert(test.getNumWays() == 567);
   assert(test.getNumHighways() == 263);

   return 0;
}
