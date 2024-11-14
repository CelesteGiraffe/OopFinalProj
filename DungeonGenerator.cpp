// Need to comment this file with doxygen style comments

#include "DungeonGenerator.hpp"
#include "Random.hpp"

DungeonGenerator::DungeonGenerator(int width, int height, unsigned int seed)
    : Generator(width, height, seed), map(width, height) {
    Random::getInstance().setSeed(seed);
}

void DungeonGenerator::generate() {
    initializeMap();
    generateRooms();
    generateCorridors();
    placeEntranceAndExit();
    ensureConnectivity();

    //To test what is being Generated before put in the file.
    //map.displayConsole();
}

Map& DungeonGenerator::getMap() {
    return map;
}

//--- Randomization work here
void DungeonGenerator::initializeMap() {
    // Initialize the map with walls
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            map.setValue(x, y, 1.0f); // ALL WALLS
        }
    }
}

void DungeonGenerator::generateRooms() {
    // Implement room
}

void DungeonGenerator::generateCorridors() {
    // Implement corridor
}

void DungeonGenerator::placeEntranceAndExit() {
    // Place entrance
}

void DungeonGenerator::ensureConnectivity() {
    // Keep connected
}
//--- Maps Generated
