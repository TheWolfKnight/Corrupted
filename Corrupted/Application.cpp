
#include <SDL.h>

#include "Application.hpp"
#include "IUIElement.hpp"

SDL_Surface* Application::get_window_surface(void) {
    return this->m_window->get_window_surface();
}

void Application::quit(void) {
    SDL_Event quit_event{ SDL_QUIT };
    SDL_PushEvent(&quit_event);
}

void Application::update_display(void) {
    SDL_Surface* window_surface = this->get_window_surface();
    SDL_FillRect(
        window_surface,
        &this->m_window->window_size,
        SDL_MapRGB(window_surface->format, 0, 0, 0)
    );

    for (IUIElement* elem : this->m_display_elements) {
        elem->update();
        elem->show();
    }
}
