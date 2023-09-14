#pragma once

#include <SDL.h>

#include "IBounded.hpp"

class Window : public IBounded {
public:
    SDL_Rect window_size;

public:

    inline explicit Window(const char* title, int width, int height) {
        SDL_Init(SDL_INIT_VIDEO);

        this->m_bounding = SDL_Rect{ 0, 0, width, height };

        this->m_window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
        );

        this->m_surface = SDL_GetWindowSurface(this->m_window);
        this->update();
    }

    inline SDL_Rect* get_bounding_box(void) { return &this->m_bounding; }
    inline void set_bounding_box(SDL_Rect box) { this->m_bounding = box; }

    SDL_Surface* get_window_surface(void);
    void update(void);
    void render_frames(void);

    inline ~Window() {
        SDL_DestroyWindow(this->m_window);
        SDL_Quit();
    }

private:
    SDL_Rect m_bounding{};

    SDL_Window* m_window{ nullptr };
    SDL_Surface* m_surface{ nullptr };
};
