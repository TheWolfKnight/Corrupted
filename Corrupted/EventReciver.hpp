#pragma once

#include <SDL.h>

class EventReciver {
public:
    virtual bool handle_event(SDL_Event* e) {
        return false;
    }
};
