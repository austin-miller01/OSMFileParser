/**
 * \file osm.cpp
 * @brief Implementation of class Osm.
 */

#include <regex>
#include <fstream>
#include <iostream>
#include "osm.hpp"

/** \brief initializes
   
   This is the default concstructor for the osm class
   initializes all the values to zero

    @return void
*/
Osm::Osm()
{
    this->numNodes = 0;
    this->numWays = 0;
    this->numHighways = 0;
    this->meanLat = 0;
    this->meanLon = 0;
}
/** \brief initializes the object of the file
   
   This uses a valid given osm file name and sets the values of the osm object
   using that osm file.

    @return void
*/
Osm::Osm(const std::string &str)
{
    this->numNodes = 0;
    this->numWays = 0;
    this->numHighways = 0;
    this->meanLat = 0;
    this->meanLon = 0;
    this->ParseOsmFile(str);

}

    Osm::~Osm() {}

    /** \brief calculates the number of nodes and the mean longitude and latitude
   
    This uses regular expression to search through the given 
    osm file and calculate the number of nodes and what the mean 
    latitude and longitude are of the file.

    @return void
*/

void Osm::parseNodes(const std::string &str)
    {
        this->numNodes = 0;
        this->meanLat = 0;
        this->meanLon = 0;
    std::regex lat("lat=\"(.*)\"[[:space:]]");
    std::regex lon("lon=\"(.*)\"");
    std::regex node("<node");
    std::smatch results;
    std::string line;
double sumLat = 0, sumLon = 0;

    
    std::ifstream OSMstream(str);
    
    while(std::getline(OSMstream,line)){
        if(regex_search(line,node)){
            this->numNodes++;
         if(regex_search(line,results,lat)){
             sumLat+=stod(results[results.size()-1]);
         }
         if(regex_search(line,results,lon)){
             sumLon+=stod(results[results.size()-1]);
         }
        }
         
    }
    
    OSMstream.close();
    
    this->meanLon = sumLon/this->numNodes;
    this->meanLat = sumLat/this->numNodes;       
}

 /** \brief calculates numWays and numHighways
   
    This uses regular expression to find and count
    the number of ways and highways within the specified 
    osm file

    @return void
*/
void Osm::parseWays(const std::string &str){
//updates NumWays and numHighways
    this->numHighways = 0;
    this->numWays = 0;
    std::ifstream OSMstream(str);
    

    std::string inString ="";

    std::regex way("<way");
    std::regex tag("<tag");
    std::regex highWay("\"highway\"");
    std::regex wayEnd("</way>");

    bool wayCheck = false;

    while(getline(OSMstream, inString)){

        if(regex_search(inString,way)){
            wayCheck = true;
            this->numWays++;
        }
        if(wayCheck == true && regex_search(inString, tag)){
            if(regex_search(inString,highWay)){
                this->numHighways++;
                wayCheck = false;
            }
        }
        if(regex_search(inString,wayEnd))wayCheck = false;
    } 
     OSMstream.close();
}

/** \brief parses the osm file
   
   This acepts the OSM file name, calls the parse Nodes 
   and parseways.

    @return void
*/
    void Osm::ParseOsmFile(const std::string &str)
    {
        this->parseNodes(str);
        this->parseWays(str);
        //acepts OSM file name
        // calls the parse Nodes and parsways
        // the OSM file name is input
    }
    /** \brief returns the Number of nodes
     * 
    @return int
    */
    int Osm::getNumNodes() const
    {
        return this->numNodes;
    }
    /** \brief returns the number of ways 
     * 
    @return int
    */
    int Osm::getNumWays() const
    {
        return this->numWays;
    }
    /** \brief  returns the number of highways
     * 
    @return int
    */
    int Osm::getNumHighways() const
    {
        return this->numHighways;
    }
    /** \brief returns the mean latitude
     * 
    @return double
    */
    double Osm::getMeanLat() const
    {
        return this->meanLat;
    }
    /** \brief returns the mean longitude
     * 
    @return double
    */
    double Osm::getMeanLon() const
    {
        return this->meanLon;
    }
