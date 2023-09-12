
#include <SDL.h>
#include <cstdio>

#include "Window.hpp"
#include "InputHandler.h"

#include "Layer.hpp"
#include "Button.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv) {

    Window* window = new Window();
    Application app{ window };

    SDL_Event e;
    bool quit = false;

    SDL_Color rgba = { 255, 50, 50, 255 };
    SDL_Color hover = { 50, 255, 50, 255 };

    InputHandler handler = InputHandler();
    Layer UI;

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
                handler.notify(e.key);
            else UI.handle_event(&e);
        }
        window->render_frames();
    }

    delete window;

    return 0;
}