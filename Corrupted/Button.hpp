#pragma once

#include "IButton.hpp"
#include "IUIElement.hpp"
#include "Application.hpp"

class Button : public IButton {
public:

    inline explicit Button(Application *app,
        int x, int y,
        int w, int h,
        uint32_t bg_color,
        uint32_t hover_color) {

        this->m_bound = { x, y, w, h };
        this->m_surface = app->get_window_surface();
        this->m_app = app;

        this->m_is_active = true;

        this->colors = ButtonColorController(bg_color, hover_color);
    }

    inline void on_button_click(ButtonEventCallback e) {
        this->m_button_event = std::move(e);
    }

    virtual bool handle_event(SDL_Event* e);

    virtual void show(void);
    virtual void update(void);

private:
    bool m_is_hoverd{ false };

    ButtonColorController colors{};

    Application* m_app{ nullptr };
    SDL_Surface* m_surface{ nullptr };

    ButtonEventCallback m_button_event{ nullptr };

private:
    virtual bool is_within_bound(int mouse_x, int mouse_y);
};
