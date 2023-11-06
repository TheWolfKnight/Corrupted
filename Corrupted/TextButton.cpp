
#include <SDL.h>

#include "TextButton.hpp"

bool TextButton::is_within_bound(int mouse_x, int mouse_y) {

    bool x_is_within = this->m_bound.x < mouse_x && this->m_bound.x + this->m_bound.w > mouse_x;
    bool y_is_within = this->m_bound.y < mouse_x && this->m_bound.y + this->m_bound.h > mouse_y;
    return x_is_within && y_is_within;
}

bool TextButton::handle_event(SDL_Event* e) {
    if (
        e->type == SDL_MOUSEBUTTONDOWN &&
        e->button.button == SDL_BUTTON_LEFT &&
        this->m_is_hoverd && this->m_is_active
        ) {
        if (this->m_button_event != nullptr)
            this->m_button_event(e);
        return true;
    }
    else if (e->type == SDL_MOUSEMOTION)
        this->m_is_hoverd = this->is_within_bound(e->motion.x, e->motion.y);
    return false;
}

void TextButton::show(void) {

}

void TextButton::update(void) {

}
