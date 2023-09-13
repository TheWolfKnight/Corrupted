#pragma once

#include <SDL.h>

class Window {
public:
    SDL_Rect window_size;

public:
    inline explicit Window(const char* title, size_t width, size_t height) {
        SDL_Init(SDL_INIT_VIDEO);

        this->m_window = SDL_CreateWindow(
            title,
            SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
            width, height,
            SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE
        );

        this->m_surface = SDL_GetWindowSurface(this->m_window);
        this->update();
    }

    SDL_Surface* get_window_surface(void);
    void update(void);
    void render_frames(void);

    inline ~Window() {
        free(this->m_surface);
        SDL_DestroyWindow(this->m_window);
        SDL_Quit();
    }

private:

    SDL_Window* m_window{ nullptr };
    SDL_Surface* m_surface{ nullptr };

};
