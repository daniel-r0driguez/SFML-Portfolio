// Daniel Rodriguez : CS003A
// Super Mario but in SFML! | Final Game Project
#ifndef INPUTCOMPONENT_H
#define INPUTCOMPONENT_H
#include "SFML/Window/Keyboard.hpp"
#include "Bitmask.h"

enum Key{ESC_KEY, LEFT_KEY, RIGHT_KEY, DOWN_KEY, UP_KEY, TAUNT_KEY}; // 6 out of 32 keys so far

class InputComponent {
private:
    Bitmask _lastFrameKeys;
    Bitmask _thisFrameKeys;

public:
    InputComponent();
    void update();
    bool isKeyPressed(Key keycode);
    bool wasKeyJustPressed(Key keycode);
    bool wasKeyReleased(Key keycode);
};

#endif //INPUTCOMPONENT_H