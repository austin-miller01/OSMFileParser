/**
 @mainpage OSM Reader

 @author Marlee Krause & Austin Miller

     @brief Example driver program for class osm
    This tests to see if the osm.cpp can properly 
    analyze the osm test files it gets and can Identify
    the number of nodes, ways, and highways in the file
    as well as the mean number of both latitude and longitude 
    points.
 */

#include <iostream>
#include <string>
#include "osm.hpp"

int main() {
   std::string fileName;
   std::cout << "Enter file name: ";
   std::cin >> fileName;

   Osm osm = Osm(fileName);

   std::cout << osm.getNumNodes() << std::endl;
   std::cout << osm.getNumWays() << std::endl;
   std::cout << osm.getNumHighways() << std::endl;
   std::cout << osm.getMeanLat() << std::endl;
   std::cout << osm.getMeanLon() << std::endl;

   return 0;
}
