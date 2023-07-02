// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "SoundManager.h"

std::unordered_map<Sound_Enum, sf::SoundBuffer> SoundManager::sounds;
ObjectPool<sf::Sound> SoundManager::soundPool(16);

std::string SoundManager::getPath(Sound_Enum sound)
{
    std::string filePath = "FinalGameProject/";
    switch(sound)
    {
        case MARIO_JUMP:
            return filePath + "marioJump.wav";
        case MARIO_BUMP:
            return filePath + "marioBump.wav";
        case MARIO_STOMP:
            return filePath + "marioStomp.wav";
        case MARIO_DIE:
            return filePath + "marioDie.wav";
        case COIN_SOUND_EFFECT:
            return filePath + "coinSoundEffect.wav";
        case LAST_SOUND:
            return "!";
    }
}

void SoundManager::load(Sound_Enum sound)
{
    sounds[sound].loadFromFile(getPath(sound));
}

void SoundManager::playSound(Sound_Enum sound)
{
    load(sound);

    sf::Sound* soundObj = soundPool.getObject();
    if (soundObj)
    {
        soundObj->setBuffer(sounds[sound]);
        soundObj->play();
        soundPool.returnObject(soundObj);
    }
}