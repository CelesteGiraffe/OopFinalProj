// Need to create Comments for this file in Doxygen format.
// Singleton Random instance

#include "Random.hpp"
#include <chrono>

Random::Random() {
    // Seed with current time
    rng.seed(std::chrono::system_clock::now().time_since_epoch().count());
}

Random& Random::getInstance() {
    static Random instance;
    return instance;
}

void Random::setSeed(unsigned int seed) {
    rng.seed(seed);
}

int Random::getInt(int min, int max) {
    std::uniform_int_distribution<int> dist(min, max);
    return dist(rng);
}

float Random::getFloat(float min, float max) {
    std::uniform_real_distribution<float> dist(min, max);
    return dist(rng);
}

