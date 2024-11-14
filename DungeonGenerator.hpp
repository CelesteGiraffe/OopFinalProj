#ifndef DUNGEONGENERATOR_HPP
#define DUNGEONGENERATOR_HPP

#include "Generator.hpp"
#include "Map.hpp"

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

    void initializeMap();
    void generateRooms();
    void generateCorridors();
    void placeEntranceAndExit();
    void ensureConnectivity();
};

#endif // DUNGEONGENERATOR_HPP
