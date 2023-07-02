// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "FinalGameImages.h"

std::unordered_map<Image_Enum, sf::Texture> FinalGameImages::textures;

std::string FinalGameImages::getPath(Image_Enum image)
{
    std::string filePath = "FinalGameProject/";
    switch (image)
    {
        case MARIO_SPRITE_SHEET:
            return filePath + "marioSpriteSheet.png";
        case MARIO_TILE_SHEET:
            return filePath + "marioTileSheet.png";
        case GOOMBA_SPRITE_SHEET:
            return filePath + "goombaSpriteSheet.png";
        case KOOPA_SPRITE_SHEET:
            return filePath + "koopaSpriteSheet.png";
        case LAST_IMAGE:
            return "!";
    }
}

void FinalGameImages::load(Image_Enum image)
{
    textures[image].loadFromFile(getPath(image));
}

sf::Texture& FinalGameImages::getImage(Image_Enum image)
{
    load(image);
    return textures[image];
}