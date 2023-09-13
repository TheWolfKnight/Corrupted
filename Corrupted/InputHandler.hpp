#pragma once

#include <functional>
#include <SDL.h>
#include <set>

using KeyboardEventCallback = std::function<void(SDL_KeyboardEvent*)>;

class InputHandler {
public:

    void change_key_event(char ch, KeyboardEventCallback e);
    bool notify(SDL_KeyboardEvent evnt);

private:
    KeyboardEventCallback m_callbacks[255];
};
