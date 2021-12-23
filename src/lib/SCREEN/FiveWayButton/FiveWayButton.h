#pragma once

#include "targets.h"

typedef enum
{
    INPUT_KEY_LEFT_PRESS = 2,
    INPUT_KEY_UP_PRESS = 3,
    INPUT_KEY_RIGHT_PRESS = 4,
    INPUT_KEY_DOWN_PRESS = 5,
    INPUT_KEY_OK_PRESS = 6,
    INPUT_KEY_NO_PRESS = 7
} Input_Key_Value_t;

class FiveWayButton
{
private:
    int key_state;
    bool keyPressed;
    bool isLongPressed;

public:

    void init();
    void handle();

    void getKeyState(int *keyValue, bool *keyLongPressed);
    void clearKeyState();
};
