#pragma once

#include <SDL.h>
#include <string>

#include "IButton.hpp"
#include "IApplication.hpp"

class TextButton : public IButton {
public:
    std::string text;
    SDL_Color bg_color, hover_color;

public:

    inline explicit TextButton(IApplication* app,
        int x, int y,
        int w, int h,
        std::string& text,
        uint32_t bg_color, uint32_t hover_color)
    {
        this->m_bound = { x, y, w, h };
        this->m_surface = app->get_window_surface();
        this->m_app = app;

        this->m_is_active = true;

        this->colors = ButtonColorController(bg_color, hover_color);
    }

    inline void on_button_click(ButtonEventCallback e) {
        this->m_button_event = std::move(e);
    }

    bool handle_event(SDL_Event* e);

    void show(void);
    void update(void);

private:

    bool m_is_hoverd{ false };

    ButtonColorController colors{};

    IApplication* m_app{ nullptr };
    SDL_Surface* m_surface{ nullptr };

    ButtonEventCallback m_button_event{ nullptr };

private:
    bool is_within_bound(int mouse_x, int mouse_y);

};

