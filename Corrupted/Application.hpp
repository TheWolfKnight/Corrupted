#pragma once

#include <SDL.h>

#include "Window.hpp"

class Application {
public:
    inline explicit Application(Window *window) : m_window(window) {}

    SDL_Surface* get_window_surface(void);

    void quit(void);

private:
    Window* m_window{ nullptr };

};