#include "DungeonGenerator.hpp"
#include "Random.hpp"
#include <vector>
#include <algorithm>


DungeonGenerator::DungeonGenerator(int width, int height, unsigned int seed)
    : Generator(width, height, seed), map(width, height) {
    Random::getInstance().setSeed(seed);
}

void DungeonGenerator::generate() {
    initializeMap();
    generateRooms();
    generateCorridors();
    placeEntranceAndExit();
}

Map& DungeonGenerator::getMap() {
    return map;
}

void DungeonGenerator::initializeMap() {
    // Randomly initialize the map with walls or empty spaces. Also at least 60% because too few is weird
    float wallProbability = 0.60f; // This is how often you find Walls instead of space.
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            if (Random::getInstance().getFloat(0, 1) < wallProbability) {
                map.setValue(x, y, WALL);
            }
            else {
                map.setValue(x, y, PATH);
            }
        }
    }
    // This takes O(n)^2 + 8 iterations based on where you are in the Arrays
    // Apply cellular automata rules
    for (int i = 0; i < 5; ++i) { // Number of iterations can be tweaked
        Map tempMap = map; // Copy current map
        for (int x = 1; x < width - 1; ++x) {
            for (int y = 1; y < height - 1; ++y) {
                int wallCount = 0;
                for (int dx = -1; dx <= 1; ++dx) {
                    for (int dy = -1; dy <= 1; ++dy) {
                        if (tempMap.getValue(x + dx, y + dy) == WALL) {
                            ++wallCount;
                        }
                    }
                }
                // If there are 5 walls around you or less set it to a wall
                if (wallCount >= 5) {
                    map.setValue(x, y, WALL);
                }
                else {
                    map.setValue(x, y, PATH);
                }
            }
        }
    }
}

void DungeonGenerator::generateRooms() {
    const int MIN_ROOMS = 5;
    const int MAX_ROOMS = 10;
    const int MIN_ROOM_SIZE = 3;
    const int MAX_ROOM_SIZE = 8;

    int roomCount = Random::getInstance().getInt(MIN_ROOMS, MAX_ROOMS);
    rooms.clear();

    // Loop to generate each room
    for (int i = 0; i < roomCount; ++i) {
        //Get the room Size
        int roomWidth = Random::getInstance().getInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);
        int roomHeight = Random::getInstance().getInt(MIN_ROOM_SIZE, MAX_ROOM_SIZE);

        //Get the position for the room within the dungeon.
        int x = Random::getInstance().getInt(1, width - roomWidth - 1);
        int y = Random::getInstance().getInt(1, height - roomHeight - 1);

        // Add create the room and check if it overlaps.
        Room newRoom = { x, y, roomWidth, roomHeight };
        bool failed = false;
        for (const auto& otherRoom : rooms) {
            if (newRoom.intersects(otherRoom)) {
                failed = true;
                break;
            }
        }
        if (!failed) {
            // Add room to the list
            rooms.push_back(newRoom);

            // Carve out the room, but leave the area around for the walls
            for (int rx = x + 1; rx < x + roomWidth - 1; ++rx) {
                for (int ry = y + 1; ry < y + roomHeight - 1; ++ry) {
                    map.setValue(rx, ry, PATH); // Set as PATH
                }
            }

            // Surround the room with walls
            for (int rx = x; rx < x + roomWidth; ++rx) {
                map.setValue(rx, y, WALL); // Top wall
                map.setValue(rx, y + roomHeight - 1, WALL); // Bottom wall
            }
            for (int ry = y; ry < y + roomHeight; ++ry) {
                map.setValue(x, ry, WALL); // Left wall
                map.setValue(x + roomWidth - 1, ry, WALL); // Right wall
            }

            // Create a  door (which for now is just a path)
            // Choose a random position for the door on one of the walls
            enum Wall { TOP, BOTTOM, LEFT, RIGHT };
            Wall wall = static_cast<Wall>(Random::getInstance().getInt(0, 3));

            switch(wall) {
                case TOP:
                    map.setValue(Random::getInstance().getInt(x + 1, x + roomWidth - 2), y, PATH);
                break;
                case BOTTOM:
                    map.setValue(Random::getInstance().getInt(x + 1, x + roomWidth - 2), y + roomHeight - 1, PATH);
                break;
                case LEFT:
                    map.setValue(x, Random::getInstance().getInt(y + 1, y + roomHeight - 2), PATH);
                break;
                case RIGHT:
                    map.setValue(x + roomWidth - 1, Random::getInstance().getInt(y + 1, y + roomHeight - 2), PATH);
                break;
            }
        }
    }
}

void DungeonGenerator::generateCorridors() {
    //Go through all the rooms and either do horizontal and or vertical corridor
    for (size_t i = 1; i < rooms.size(); ++i) {
        //pair (x,y) of centre
        auto prevCenter = rooms[i - 1].center();
        auto currCenter = rooms[i].center();

        // Randomly choose to first go horizontal then vertical or vice versa
        if (Random::getInstance().getInt(0, 1) == 0) {
            // Horizontal then vertical
            carveHorizontalCorridor(prevCenter.first, currCenter.first, prevCenter.second);
            carveVerticalCorridor(prevCenter.second, currCenter.second, currCenter.first);
        }
        else {
            // Vertical then horizontal
            carveVerticalCorridor(prevCenter.second, currCenter.second, prevCenter.first);
            carveHorizontalCorridor(prevCenter.first, currCenter.first, currCenter.second);
        }
    }
}

void DungeonGenerator::placeEntranceAndExit() {
    if (rooms.empty()) return;

    // Place entrance in the first room
    auto firstRoomCenter = rooms.front().center();
    map.setValue(firstRoomCenter.first, firstRoomCenter.second, ENTRANCE);

    // Place exit in the last room
    auto lastRoomCenter = rooms.back().center();
    map.setValue(lastRoomCenter.first, lastRoomCenter.second, EXIT);
}

// Might not need to create doors in the rooms because this technically does it for me.
void DungeonGenerator::carveHorizontalCorridor(int x1, int x2, int y) {
    //Only need the Y in the Centre because it's at the same level as the other due to no diagnal rooms.
    int start = std::min(x1, x2);
    int end = std::max(x1, x2);
    for (int x = start; x <= end; ++x) {
        map.setValue(x, y, PATH); // PATH
    }
}

void DungeonGenerator::carveVerticalCorridor(int y1, int y2, int x) {
    int start = std::min(y1, y2);
    int end = std::max(y1, y2);
    for (int y = start; y <= end; ++y) {
        map.setValue(x, y, PATH); // PATH
    }
}
