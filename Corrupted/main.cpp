
#include <SDL.h>
#include <cstdio>
#include <memory>

#include "Window.hpp"
#include "InputHandler.hpp"
#include "IApplication.hpp"

#include "Layer.hpp"
#include "Button.hpp"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char** argv) {

    Window* window = new Window("Test Window", 640, 480);
    IApplication *app = new Application(window);

    SDL_Event e;
    bool quit = false;

    SDL_Color rgba = { 255, 50, 50, 255 };
    SDL_Color hover = { 50, 255, 50, 255 };

    InputHandler *handler = new InputHandler();

    handler->change_key_event('a', [](SDL_KeyboardEvent* e) {
        printf("Hello from event 1\n");
    });

    Button* button1 = new Button(app, 50, 50, 50, 50, 0xFF3232FF, 0x3232FFFF);
    button1->on_button_click([handler](SDL_Event* e) {
        handler->change_key_event('a', [](SDL_KeyboardEvent* ke) {
            printf("Hello from event 2\n");
        });
    });

    Button* button2 = new Button(app, 150, 50, 50, 50, 0x32FF32FF, 0x3232F0FF);
    button2->on_button_click([handler](SDL_Event* e) {
        handler->change_key_event('a', [](SDL_KeyboardEvent* ke) {
            printf("Hello from event 3\n");
        });
    });

    app->add_display_element(button1);
    app->add_display_element(button2);

    while (!quit) {
        while (SDL_PollEvent(&e)) {
            if (e.type == SDL_QUIT) {
                quit = true;
            }
            else if (e.type == SDL_KEYDOWN)
                handler->notify(e.key);
            else app->handle_event(&e);
        }
        app->update_display();
    }

    delete app;

    return 0;
}
