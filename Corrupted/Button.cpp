
#include <SDL.h>

#include "Button.hpp"

bool Button::handle_event(SDL_Event* e) {
    if (
        e->type == SDL_MOUSEBUTTONDOWN &&
        e->button.button == SDL_BUTTON_LEFT
        )
    {
        if (this->m_button_event != nullptr)
            this->m_button_event(e);
        return true;
    }
    else if (e->type == SDL_MOUSEMOTION) {
        this->m_is_hoverd = this->is_within_bound(e->motion.x, e->motion.y);
    }
}

bool Button::is_within_bound(int mouse_x, int mouse_y) {
    SDL_Rect* bound = &this->m_bound;

    bool too_far_left = mouse_x < bound->x;
    bool too_far_right = mouse_x > bound->x + bound->w;
    bool is_too_high = mouse_y < bound->y;
    bool is_too_low = mouse_y > bound->y + bound->h;

    return !(too_far_left || too_far_right || is_too_high || is_too_low);
}

void Button::update(void) {
    SDL_Color* color = &(this->m_is_hoverd ? this->m_hover_color : this->m_background_color);

    SDL_FillRect(
        this->m_surface,
        &this->m_bound,
        SDL_MapRGB(this->m_surface->format, color->r, color->g, color->b)
    );
}
