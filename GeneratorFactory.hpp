#ifndef GENERATORFACTORY_HPP
#define GENERATORFACTORY_HPP

#include <string>
#include "Generator.hpp"
#include "TerrainGenerator.hpp"
#include "DungeonGenerator.hpp"

/**
 * @class GeneratorFactory
 * @brief Factory class to create generator instances based on type.
 */
class GeneratorFactory {
public:
    /**
     * @brief Creates a generator of specified type. Currently supports "terrain" and "dungeon". Could be expanded to support more types using something like an ENUM.
     * @param type Type of the generator ("terrain" or "dungeon").
     * @param width Width of the content.
     * @param height Height of the content.
     * @param seed Seed for random number generation.
     * @return Unique pointer to a Generator instance.
     */
    static std::unique_ptr<Generator> createGenerator(const std::string& type, int width, int height, unsigned int seed) {
        if (type == "terrain") {
            return std::make_unique<TerrainGenerator>(width, height, seed);
        } else if (type == "dungeon") {
            return std::make_unique<DungeonGenerator>(width, height, seed);
        }
        return nullptr;
    }
};

#endif // GENERATORFACTORY_HPP
