#pragma once

#include <SDL.h>
#include <vector>

#include "IUIElement.hpp"
#include "IBounded.hpp"

class IApplication : public IBounded {
public:
    virtual SDL_Surface* get_window_surface(void) = 0;

    virtual void add_display_element(IUIElement* elem) = 0;

    virtual void update_display(void) = 0;
    virtual void quit(void) = 0;

    virtual bool handle_event(SDL_Event* e) = 0;
};
