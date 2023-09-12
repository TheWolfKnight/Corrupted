
#include <SDL.h>

#include "Window.hpp"

SDL_Surface* Window::get_window_surface(void) {
    return this->m_surface;
}

void Window::update(void) {
    SDL_FillRect(
        this->m_surface,
        nullptr,
        SDL_MapRGB(this->m_surface->format, 40, 40, 40)
    );
}

void Window::render_frames(void) {
    SDL_UpdateWindowSurface(this->m_window);
}
