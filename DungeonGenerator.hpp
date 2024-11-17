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

     /**
    * \struct Room
    * \brief Represents a rectangular room in the dungeon.
    */
     struct Room {
      int x, y; ///< Top-left corner coordinates of the room.
      int width, height; ///< Dimensions of the room.

      /**
       * \brief Checks if this room intersects with another room.
       * \param other The other room to check intersection with.
       * \return True if rooms intersect, false otherwise.
       */
      bool intersects(const Room& other) const {
       return (x <= other.x + other.width && x + width >= other.x &&
               y <= other.y + other.height && y + height >= other.y);
      }

      /**
       * \brief Gets the center point of the room.
       * \return A pair of integers representing the center coordinates.
       */
      std::pair<int, int> center() const {
       return { x + width / 2, y + height / 2 };
      }
     };

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
    * \brief Boors out a horizontal corridor of paths through the walls
    */
    void carveHorizontalCorridor(int x1, int x2, int y);
     /**
    * \brief Boors out a Vertical corridor of paths through the walls
    */
    void carveVerticalCorridor(int y1, int y2, int x);
};

#endif // DUNGEONGENERATOR_HPP
