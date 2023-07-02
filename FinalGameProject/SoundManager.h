// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_SOUNDMANAGER_H
#define FINALPROJECTGAME_SOUNDMANAGER_H
#include "ObjectPool.h"
#include "SFML/Audio/SoundBuffer.hpp"
#include "SFML/Audio/Sound.hpp"
#include <unordered_map>

enum Sound_Enum {MARIO_JUMP, MARIO_BUMP, MARIO_STOMP, MARIO_DIE, COIN_SOUND_EFFECT,
        LAST_SOUND};

class SoundManager {
private:
    static ObjectPool<sf::Sound> soundPool;
    static std::unordered_map<Sound_Enum, sf::SoundBuffer> sounds;
    static std::string getPath(Sound_Enum sound);
    static void load(Sound_Enum sound);

public:
    static void playSound(Sound_Enum sound);
};

#endif //FINALPROJECTGAME_SOUNDMANAGER_H