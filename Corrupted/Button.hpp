
#include <functional>
#include <cstdint>
#include <SDL.h>

#include "EventReciver.hpp"
#include "Application.hpp"


using ButtonEventCallback = std::function<void(SDL_Event*)>;

static const uint32_t RGBA_MASK = 0x000000FF;

#define RED(rgba) (uint8_t)(rgba >> 24 & RGBA_MASK)
#define GREEN(rgba) (uint8_t)(rgba >> 16 & RGBA_MASK)
#define BLUE(rgba) (uint8_t)(rgba >> 8 & RGBA_MASK)
#define ALPHA(rgba) (uint8_t)(rgba & RGBA_MASK)

class Button : public EventReciver {
public:
    inline explicit Button(Application* app) {
        this->m_surface = app->get_window_surface();
        this->m_app = app;
        this->update();
    }

    inline void on_button_click(ButtonEventCallback e) {
        this->m_button_event = std::move(e);
    }

    bool handle_event(SDL_Event* e);

private:
    bool m_is_hoverd{ false };
    SDL_Color m_background_color{ 255, 50, 50, 255 };
    SDL_Color m_hover_color{ 50, 50, 255, 255 };

    SDL_Rect m_bound{ 50,50,50,50 };

    Application* m_app{ nullptr };
    SDL_Surface* m_surface{ nullptr };

    ButtonEventCallback m_button_event{ nullptr };

private:
    void update(void);
    bool is_within_bound(int mouse_x, int mouse_y);
};
