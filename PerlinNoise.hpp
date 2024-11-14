#ifndef PERLINNOISE_HPP
#define PERLINNOISE_HPP

#include "NoiseAlgorithm.hpp"

/**
 * @class PerlinNoise
 * @brief Implementation of the Perlin noise algorithm.
 */
class PerlinNoise : public NoiseAlgorithm {
public:
    /**
     * @brief Constructs a PerlinNoise generator.
     * @param seed Seed for random number generation.
     */
    PerlinNoise(unsigned int seed);

    /**
     * @brief Gets the noise value at a specific coordinate.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return The noise value.
     */
    float getValue(float x, float y) override;

private:
    unsigned int seed;
};

#endif // PERLINNOISE_HPP