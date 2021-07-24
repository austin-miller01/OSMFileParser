/**
 * @class Osm
 * @brief Parses an OSM file for node & way data.
 */

#ifndef OSM_H
#define OSM_H

#include <string>

class Osm {
   private:
      int numNodes;   /**< Number of nodes in OSM file int */
      int numWays;   /**< Number of ways in OSM file int */
      int numHighways;   /**< Number of highways in OSM file int */
      double meanLat;   /**< Mean latitude of all nodes */
      double meanLon;   /**< Mean longtidue of all nodes */
      void parseNodes(const std::string &); /**< Parse OSM file for numNodes */
      void parseWays(const std::string &); /**< Parse OSM file for numWays & numHighways */
   public:
      Osm();
      Osm(const std::string &);
      ~Osm();
      void ParseOsmFile(const std::string &);
      int getNumNodes() const;
      int getNumWays() const;
      int getNumHighways() const;
      double getMeanLat() const;
      double getMeanLon() const;
};

#endif

