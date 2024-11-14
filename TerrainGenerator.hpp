#ifndef TERRAINGENERATOR_HPP
#define TERRAINGENERATOR_HPP

#include "Generator.hpp"
#include "Map.hpp"
#include "NoiseAlgorithm.hpp"
#include <memory>

/**
 * @class TerrainGenerator
 * @brief Concrete generator that creates terrain-based maps. Something that might be useable in outdoor maps
 *
 * Uses noise algorithms to generate terrain features like hills and valleys.
 */
class TerrainGenerator : public Generator {
public:
    /**
     * @brief Constructs a TerrainGenerator.
     * @param width Width of the terrain.
     * @param height Height of the terrain.
     * @param seed Seed for random number generation.
     */
    TerrainGenerator(int width, int height, unsigned int seed);

    /**
     * @brief Generates the terrain map.
     */
    void generate() override;

    /**
     * @brief Sets the noise algorithm to use.
     * @param algorithm Shared pointer to a noise algorithm.
     */
    void setNoiseAlgorithm(std::shared_ptr<NoiseAlgorithm> algorithm);

    /**
     * @brief Sets the frequency parameter for noise generation.
     * @param frequency The frequency value.
     */
    void setFrequency(float frequency);

    /**
     * @brief Sets the amplitude parameter for noise generation.
     * @param amplitude The amplitude value.
     */
    void setAmplitude(float amplitude);

    /**
     * @brief Gets the generated map.
     * @return Reference to the Map object.
     */
    Map& getMap();

private:
    float frequency;
    float amplitude;
    Map map;
    std::shared_ptr<NoiseAlgorithm> noiseAlgorithm;

    void applyNoise();
    void smoothTerrain();
};

#endif // TERRAINGENERATOR_HPP
