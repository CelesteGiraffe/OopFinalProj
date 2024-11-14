// Need to comment this file with doxygen style comments

#include "TerrainGenerator.hpp"

#include "PerlinNoise.hpp"
#include "Random.hpp"

TerrainGenerator::TerrainGenerator(int width, int height, unsigned int seed)
    : Generator(width, height, seed), frequency(1.0f), amplitude(1.0f), map(width, height) {
    // Default noise algorithm
    noiseAlgorithm = std::make_shared<PerlinNoise>(seed);
}

void TerrainGenerator::setNoiseAlgorithm(std::shared_ptr<NoiseAlgorithm> algorithm) {
    noiseAlgorithm = algorithm;
}

void TerrainGenerator::setFrequency(float freq) {
    frequency = freq;
}

void TerrainGenerator::setAmplitude(float amp) {
    amplitude = amp;
}

void TerrainGenerator::generate() {
    applyNoise();
    smoothTerrain();
}

void TerrainGenerator::applyNoise() {
    for (int x = 0; x < width; ++x) {
        for (int y = 0; y < height; ++y) {
            float nx = static_cast<float>(x) / width * frequency;
            float ny = static_cast<float>(y) / height * frequency;
            float elevation = noiseAlgorithm->getValue(nx, ny) * amplitude;
            map.setValue(x, y, elevation);
        }
    }
}

void TerrainGenerator::smoothTerrain() {
    // Implement terrain smoothing algorithm in order to make the terrain look more natural and outdoorsy
}

Map& TerrainGenerator::getMap() {
    return map;
}
