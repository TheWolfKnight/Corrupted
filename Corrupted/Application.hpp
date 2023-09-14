#pragma once

#include <SDL.h>
#include <vector>

#include "IApplication.hpp"
#include "Window.hpp"
#include "Layer.hpp"

class Application : public IApplication {
public:
    inline explicit Application(Window* window) : m_window{window} {
        this->m_ui = new Layer(this);
    }

    SDL_Surface* get_window_surface(void);

    void add_display_element(IUIElement* elem);

    inline SDL_Rect* get_bounding_box(void) override { return this->m_window->get_bounding_box(); }
    inline void set_bounding_box(SDL_Rect box) override { this->m_window->set_bounding_box(box); }

    void update_display(void);
    void quit(void);

    bool handle_event(SDL_Event* e);

    ~Application() {
        delete this->m_window;
        delete this->m_ui;
    }

private:
    Window* m_window{ nullptr };
    std::vector<IUIElement*> m_display_elements;
    Layer* m_ui{ nullptr };
};
