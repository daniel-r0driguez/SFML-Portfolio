// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef FINALPROJECTGAME_MUSICMANAGER_H
#define FINALPROJECTGAME_MUSICMANAGER_H
#include "SFML/Audio.hpp"

enum Music_Enum {OVERWORLD_THEME, FLAG_THEME,
        LAST_MUSIC};

class MusicManager {
private:
    static sf::Music _musicPlayer;
    static std::string getPath(Music_Enum music);
    static void load(Music_Enum music);

public:
    static void playMusic(Music_Enum music, bool loop);
    static void pause();
    static void stop();


};


#endif //FINALPROJECTGAME_MUSICMANAGER_H