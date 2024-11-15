cmake_minimum_required(VERSION 3.29)
project(untitled)

set(CMAKE_CXX_STANDARD 20)

add_executable(untitled main.cpp
        Generator.hpp
        TerrainGenerator.hpp
        TerrainGenerator.cpp
        DungeonGenerator.hpp
        DungeonGenerator.cpp
        Map.hpp
        Map.cpp
        Random.hpp
        Random.cpp
        NoiseAlgorithm.hpp
        PerlinNoise.hpp
        PerlinNoise.cpp
        GeneratorFactory.hpp)
