#ifndef GENERATOR_HPP
#define GENERATOR_HPP

/**
 * @class Generator
 * @brief Abstract base class for all procedural content generators. Could be used for generating things ouside of Dungeons like Terrain...
 *
 * interface for content generator types.
 */
class Generator {
public:
 /**
  * @brief Virtual destructor.
  */
 virtual ~Generator() = default;

 /**
  * @brief virtual method for generating content wihin all derived classes.
  */
 virtual void generate() = 0;

protected:
 int width;
 int height;
 unsigned int seed; // Always above 0

 /**
  * @brief Protected constructor to prevent direct instantiation of the base class.
  * @param width Width of the content to generate.
  * @param height Height of the content to generate.
  * @param seed Seed for random number generation.
  */
 Generator(int width, int height, unsigned int seed)
     : width(width), height(height), seed(seed) {}
};

#endif // GENERATOR_HPP
