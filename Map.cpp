// Need to create Comments for this file in Doxygen format.

#include "Map.hpp"
#include <fstream>
#include <stdexcept>
#include <iostream>

Map::Map(int width, int height)
    : width(width), height(height), data(width, std::vector<float>(height, 0.0f)) {
}

void Map::setValue(int x, int y, float value) {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        data[x][y] = value;
    } else {
        throw std::out_of_range("Map::setValue coordinates out of range");
    }
}

float Map::getValue(int x, int y) const {
    if (x >= 0 && x < width && y >= 0 && y < height) {
        return data[x][y];
    } else {
        throw std::out_of_range("Map::getValue coordinates out of range");
    }
}

void Map::save(const std::string& filename) const {
    //open the file to be written to
    std::ofstream file(filename, std::ios::binary);
    // make sure it's open
    if (file.is_open()) {
        //uses reinterpret cast which pulls the data in a way that can be retrieved later from the file
        file.write(reinterpret_cast<const char*>(&width), sizeof(width));
        file.write(reinterpret_cast<const char*>(&height), sizeof(height));
        for (const auto& column : data) {
            file.write(reinterpret_cast<const char*>(column.data()), height * sizeof(float));
        }
        //make sure you close the file silly :D
        file.close();
    } else {
        throw std::runtime_error("Map::save failed to open file");
    }
}

void Map::load(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (file.is_open()) {
        file.read(reinterpret_cast<char*>(&width), sizeof(width));
        file.read(reinterpret_cast<char*>(&height), sizeof(height));
        data.resize(width, std::vector<float>(height));
        for (auto& column : data) {
            file.read(reinterpret_cast<char*>(column.data()), height * sizeof(float));
        }
        file.close();
    } else {
        throw std::runtime_error("Map::load failed to open file");
    }
}

int Map::getWidth() const {
    return width;
}

int Map::getHeight() const {
    return height;
}

void Map::displayConsole() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            float value = getValue(x, y);
            if (value == WALL) {            // Wall
                std::cout << '#';
            } else if (value == PATH) {     // Open path
                std::cout << ' ';
            } else if (value == ENTRANCE) { // Entrance
                std::cout << 'E';
            } else if (value == EXIT) {     // Exit
                std::cout << 'X';
            } else if (value = BLANK) {
                std::cout << '.';
            } else {
                std::cout << '?';           // Unknown cell type
            }
        }
        std::cout << '\n';
    }
}