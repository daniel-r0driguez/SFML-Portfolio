// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#include "MusicManager.h"

sf::Music MusicManager::_musicPlayer;

std::string MusicManager::getPath(Music_Enum music)
{
    std::string filePath = "FinalGameProject/";
    switch (music)
    {
        case OVERWORLD_THEME:
            return filePath + "overworldTheme.wav";
        case FLAG_THEME:
            return filePath + "flagTheme.wav";
        case LAST_MUSIC:
            return "!";
    }
}

void MusicManager::load(Music_Enum music)
{
    std::string path = getPath(music);
    if (path.c_str())
    {
        _musicPlayer.openFromFile(path);
    }
}

void MusicManager::playMusic(Music_Enum music, bool loop)
{

    load(music);
    if (loop)
    {
        _musicPlayer.setLoop(loop);
    }
    if (music == OVERWORLD_THEME)
    {}
    _musicPlayer.play();
}

void MusicManager::pause()
{
    _musicPlayer.pause();
}

void MusicManager::stop()
{
    _musicPlayer.stop();
}