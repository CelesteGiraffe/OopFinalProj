#ifndef RANDOM_HPP
#define RANDOM_HPP

#include <random>

/**
 * @class Random
 * @brief Singleton class for random number generation.
 */
class Random {
public:
    /**
     * @brief Gets the singleton instance of Random.
     * @return Reference to the Random instance.
     */
    static Random& getInstance();

    /**
     * @brief Generates a random integer between min and max.
     * @param min Minimum value.
     * @param max Maximum value.
     * @return Random integer.
     */
    int getInt(int min, int max);

    /**
     * @brief Generates a random float between min and max.
     * @param min Minimum value.
     * @param max Maximum value.
     * @return Random float.
     */
    float getFloat(float min, float max);

    /**
     * @brief Sets the seed for random number generation.
     * @param seed The seed value.
     */
    void setSeed(unsigned int seed);

private:
    Random(); // Private constructor
    // Mersenne Twister random number generator 
    // https://www.learncpp.com/cpp-tutorial/generating-random-numbers-using-mersenne-twister/
    std::mt19937 rng; 

};

#endif // RANDOM_HPP
