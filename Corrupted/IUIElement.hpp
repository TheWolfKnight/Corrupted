#pragma once

#include <SDL.h>

#include "IBounded.hpp"

class IUIElement : public IBounded {
public:
    /*
        Runs the render functions for the element
    */
    virtual void show(void) = 0;

    /*
        Runs the update function for the element
    */
    virtual void update(void) = 0;

    /*
        Gets the bounding box of the UI element
    */
    virtual SDL_Rect get_location(void) { return this->m_bound; }

    /*
        Sets the bounding box of the UI element
    */
    virtual void set_location(int x, int y) {
        this->m_bound.x = x;
        this->m_bound.y = y;
    }

    /*
        Tells the caller if the UI element is active
    */
    virtual bool is_active(void) { return this->m_is_active; }

    /*
        Makes the element active
    */
    virtual void activate(void) { this->m_is_active = true; }

    /*
        Makes the element inactive
    */
    virtual void deactivate(void) { this->m_is_active = false; }

protected:
    bool m_is_active{ true };
};