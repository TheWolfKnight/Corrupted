#pragma once

#include <SDL.h>
#include <set>

typedef void (*key_event_callback_t)(SDL_KeyboardEvent *e);

class InputHandler {
public:

    void change_key_event(char ch, key_event_callback_t e);
    bool notify(SDL_KeyboardEvent evnt);

private:
    key_event_callback_t m_callbacks[255];
};
