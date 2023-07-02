// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_IMAGES_H
#define FINALPROJECTGAME_IMAGES_H
#include "SFML/Graphics.hpp"
#include <unordered_map>

enum Image_Enum {MARIO_SPRITE_SHEET, MARIO_TILE_SHEET, GOOMBA_SPRITE_SHEET, KOOPA_SPRITE_SHEET,
        LAST_IMAGE};

class FinalGameImages {
private:
    static std::unordered_map<Image_Enum, sf::Texture> textures;
    static std::string getPath(Image_Enum image);
    static void load(Image_Enum image);

public:
    static sf::Texture& getImage(Image_Enum image);
};


#endif //FINALPROJECTGAME_IMAGES_H