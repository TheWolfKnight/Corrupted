
#include <SDL.h>
#include <cstdio>

#include "InputHandler.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv) {
    SDL_Window* window = NULL;

    SDL_Surface* screen_surface = NULL;

    if (SDL_Init(SDL_INIT_VIDEO) < 0) {
        printf("SDL Could not initialize! SDL_ERROR: %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("SDL_Window", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if (window == NULL) {
        printf("Could not create window! SDL_Error: %s\n", SDL_GetError());
        return 2;
    }

    screen_surface = SDL_GetWindowSurface(window);

    SDL_FillRect(screen_surface, NULL, SDL_MapRGB(screen_surface->format, 0xff, 0xff, 0xff));
    SDL_UpdateWindowSurface(window);

    SDL_Event e;
    bool quit = false;

    InputHandler* handler = new InputHandler();

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
                handler->notify(e.key);
        }
    }

    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}