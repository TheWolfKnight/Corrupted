#pragma once

#include <SDL.h>

#include "IBounded.hpp"

class EventReciver {
public:
    virtual bool handle_event(SDL_Event* e) {
        return false;
    }
};
