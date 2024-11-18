//
// Created by Celeste Artley on 17/11/2024.
//

#ifndef ROOM_HPP
#define ROOM_HPP

    /**
    * \struct Room
    * \brief Represents a rectangular room in the dungeon.
    */
     struct Room {
         int x, y; ///< Top-left corner coordinates of the room.
         int width, height; ///< Dimensions of the room.

         /**
          * \brief Checks if this room intersects with another room.
          * \param other The other room to check intersection with.
          * \return True if rooms intersect, false otherwise.
          */
         bool intersects(const Room& other) const {
             return (x <= other.x + other.width && x + width >= other.x &&
                     y <= other.y + other.height && y + height >= other.y);
         }

         /**
          * \brief Gets the center point of the room.
          * \return A pair of integers representing the center coordinates.
          */
         std::pair<int, int> center() const {
             return { x + width / 2, y + height / 2 };
         }
     };

#endif //ROOM_HPP
