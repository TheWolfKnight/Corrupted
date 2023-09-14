#pragma once

#include <SDL.h>

class IBounded {
public:

    virtual SDL_Rect* get_bounding_box(void) { return &this->m_bound; }
    virtual void set_bounding_box(SDL_Rect box) { this->m_bound = box; }

protected:
    SDL_Rect m_bound{};
};
