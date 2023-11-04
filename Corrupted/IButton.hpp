
#include <functional>
#include <cstdint>
#include <SDL.h>

#include "EventReciver.hpp"
#include "Application.hpp"
#include "IUIElement.hpp"

using ButtonEventCallback = std::function<void(SDL_Event*)>;

static const uint32_t RGBA_MASK = 0x000000FF;

#define RED(rgba) (uint8_t)(rgba >> 24 & RGBA_MASK)
#define GREEN(rgba) (uint8_t)(rgba >> 16 & RGBA_MASK)
#define BLUE(rgba) (uint8_t)(rgba >> 8 & RGBA_MASK)
#define ALPHA(rgba) (uint8_t)(rgba & RGBA_MASK)

struct ButtonColorController {
    SDL_Color background_color{};
    SDL_Color on_hover_color{};
    SDL_Color* current_color{ &background_color };

    inline ButtonColorController(void) = default;

    inline ButtonColorController(uint32_t bg_color, uint32_t hover_color) {
        this->background_color = { RED(bg_color), GREEN(bg_color), BLUE(bg_color), ALPHA(bg_color) };
        this->on_hover_color = { RED(hover_color), GREEN(hover_color), BLUE(hover_color), ALPHA(hover_color) };
    }

    inline void change_color(bool is_hoverd) {
        this->current_color = &(is_hoverd ? this->on_hover_color : this->background_color);
    }

};

class IButton : public EventReciver, public IUIElement {
public:


    virtual bool handle_event(SDL_Event* e) = 0;

    virtual void show(void) = 0;
    virtual void update(void) = 0;

    inline ~IButton() {}

};
