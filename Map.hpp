#ifndef MAP_HPP
#define MAP_HPP

#include <vector>
#include <string>

// Constants for cell types
const float WALL = 1.0f;
const float PATH = 0.0f;
const float ENTRANCE = -1.0f;
const float EXIT = -2.0f;
const float BLANK = 10.0f;

// constants for outdoor height maps
//... need to be implemented.


/**
 * @class Map
 * @brief Stores the generated map data and provides utility functions.
 */
class Map {
public:
 /**
  * @brief Constructs a Map with given dimensions.
  * @param width Width of the map.
  * @param height Height of the map.
  */
 Map(int width, int height);

 /**
  * @brief Sets the value at a specific coordinate.
  * @param x X-coordinate.
  * @param y Y-coordinate.
  * @param value The value to set.
  */
 void setValue(int x, int y, float value);

 /**
  * @brief Gets the value at a specific coordinate.
  * @param x X-coordinate.
  * @param y Y-coordinate.
  * @return The value at the coordinate.
  */
 float getValue(int x, int y) const;

 /**
  * @brief Saves the map data to a file.
  * @param filename Name of the file.
  */
 void save(const std::string& filename) const;

 /**
  * @brief Loads the map data from a file.
  * @param filename Name of the file.
  */
 void load(const std::string& filename);

 /**
  * @brief Displays the map in the console with characters representing different cell types.
  */
 void displayConsole() const;

 /**
  * @brief Gets the width of the map.
  * @return The width.
  */
 int getWidth() const;

 /**
  * @brief Gets the height of the map.
  * @return The height.
  */
 int getHeight() const;

private:
 int width;
 int height;
 std::vector<std::vector<float>> data;
};

#endif // MAP_HPP
