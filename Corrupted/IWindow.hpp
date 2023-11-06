#pragma once

#include <SDL.h>

#include "IBounded.hpp"

class IWindow : public IBounded {
public:
    SDL_Rect window_size;

public:
    virtual SDL_Surface* get_window_surface(void) = 0;
    virtual void update(void) = 0;
    virtual void render_frames(void) = 0;
};
