
#include <SDL.h>
#include <cstring>

#include "InputHandler.hpp"

void InputHandler::change_key_event(char ch, KeyboardEventCallback e) {
    this->m_callbacks[ch] = e;
}

bool InputHandler::notify(SDL_KeyboardEvent evnt) {

    if (this->m_callbacks[evnt.keysym.sym] == nullptr)
        return false;

    this->m_callbacks[evnt.keysym.sym](&evnt);
    return true;
}
