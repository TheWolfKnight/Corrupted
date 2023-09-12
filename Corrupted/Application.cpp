
#include <SDL.h>

#include "Application.hpp"

SDL_Surface* Application::get_window_surface(void) {
    return this->m_window->get_window_surface();
}

void Application::quit(void) {
    SDL_Event quit_event{ SDL_QUIT };
    SDL_PushEvent(&quit_event);
}
