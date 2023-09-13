#pragma once

#include <SDL.h>
#include <vector>

#include "Window.hpp"
#include "IUIElement.hpp"

class Application {
public:
    inline explicit Application(Window *window) : m_window(window) {}

    SDL_Surface* get_window_surface(void);

    inline void add_display_element(IUIElement* elem) {

        this->m_display_elements.push_back(elem);

    }
    void update_display(void);
    void quit(void);

    ~Application() {
        delete this->m_window;
    }

private:
    Window* m_window{ nullptr };
    std::vector<IUIElement*> m_display_elements;
};