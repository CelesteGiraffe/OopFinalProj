#ifndef NOISEALGORITHM_HPP
#define NOISEALGORITHM_HPP

/**
 * @class NoiseAlgorithm
 * @brief Interface for noise algorithms used in terrain generation.
 */
class NoiseAlgorithm {
public:
    virtual ~NoiseAlgorithm() = default;

    /**
     * @brief Gets the noise value at a specific coordinate.
     * @param x The x-coordinate.
     * @param y The y-coordinate.
     * @return The noise value.
     */
    virtual float getValue(float x, float y) = 0;
};

#endif // NOISEALGORITHM_HPP