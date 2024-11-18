#ifndef DUNGEONGENERATOR_HPP
#define DUNGEONGENERATOR_HPP

#include "Generator.hpp"
#include "Map.hpp"
#include "Room.hpp"

/**
 * @class DungeonGenerator
 * @brief Concrete generator that creates dungeon layouts.
 *
 * Uses cellular automata to generate dungeons.
 */
class DungeonGenerator : public Generator {
public:
    /**
     * @brief Constructs a DungeonGenerator.
     * @param width Width of the dungeon.
     * @param height Height of the dungeon.
     * @param seed Seed for random number generation.
     */
    DungeonGenerator(int width, int height, unsigned int seed);

    /**
     * @brief Generates the dungeon map.
     */
    void generate() override;

    /**
     * @brief Gets the generated map.
     * @return Reference to the Map object.
     */
    Map& getMap();

private:

    Map map;
    std::vector<Room> rooms;
    /**
    * \brief Creates the map with a number of WALLS based on a percentage
    */
    void initializeMap();
     /**
    * \brief Creates a number of rooms within the bounds of the generated space that will contain the entrance and exit.
    */
    void generateRooms();
     /**
    * \brief Chooses to create a verticle and horizontal corridor
    */
    void generateCorridors();
     /**
    * \brief Places the entrance and exit in the first and last room
    */
    void placeEntranceAndExit();
     /**
    * \brief
    */
     void clearLikeWalls(Map& map);
     /**
    * \brief Boors out a horizontal corridor of paths through the walls
    */
    void carveHorizontalCorridor(int x1, int x2, int y);
     /**
    * \brief Boors out a Vertical corridor of paths through the walls
    */
    void carveVerticalCorridor(int y1, int y2, int x);
     /**
    * \brief
    */
    bool isSurroundedByWalls(const Map& map, int x, int y);
};

#endif // DUNGEONGENERATOR_HPP
