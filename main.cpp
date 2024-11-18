#include <iostream>
#include "GeneratorFactory.hpp"

// To DO:
// Create a MAKE file to compile the project. 
// Comment the CPP final implementations with doxygen style comments
// Utilize the factory to create a Terrain generator and display the generated map to the console.
// Create a Dungeon and Terrain with a simplistic implementation of the Perlin Noise algorithm.
// -- Create the PerlinNoise Algorithm's implementation.
// Finish the Map Generation algorithm for the Dungeon and Terrain.
// -- Dungeon: Generate rooms, corridors, and ensure connectivity, Drunkard's Walk, and points to create larger rooms and a path to finish.
// -- Terrain: Generate a height map using Perlin Noise, And ensure Natural finish through Smoothing.

// Done:
// Comment the header files with doxygen style comments
// Utilize the factory to create a Dungeon generator and display the generated map to the console. (Currently only WALLS)
// Save the generated dungeon map to a file.
// Save the generated terrain map to a file. 

int main() {
    // Sophie's number 60069
    // This see is my test seed 23042934
    unsigned int seed = 3;
    int width = 80;
    int height = 20;

    // Create a dungeon generator using the factory then display the file it to the console.
    auto dungeonGen = GeneratorFactory::createGenerator("dungeon", width, height, seed);
    if (dungeonGen) {
        dungeonGen->generate();
        Map& dungeonMap = static_cast<DungeonGenerator*>(dungeonGen.get())->getMap();
        dungeonMap.save("dungeon_map.dat");

        std::cout << "Generated dungeon layout...\n";
        std::cout << "Current Generated Dungeon:\n";
        dungeonMap.displayConsole();
    }

    return 0;
}
