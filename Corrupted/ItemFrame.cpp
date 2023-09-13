
#include <SDL.h>
#include <vector>

#include "ArenaAllocator.hpp"
#include "Application.hpp"
#include "IUIElement.hpp"
#include "ItemFrame.hpp"
#include "Layer.hpp"

void ItemFrame::add_child(IUIElement* elem) {

    // Moves the element to the parent frame
    SDL_Rect bound = elem->get_location();
    bound.x += this->m_bound.x;
    bound.y += this->m_bound.y;
    elem->set_location(bound);

    ChildElement *ch_elem = (ChildElement*)this->m_allocator.alloc<ChildElement>();

    // Dont need to show/handle elements out of bound
    if (!this->is_within_bound(&bound)) {
        ch_elem->should_render = false;
        elem->deactivate();
    }

    ch_elem = new ChildElement(elem);


    this->m_child_elements.push_back(ch_elem);
}

bool ItemFrame::handle_event(SDL_Event* e) {
    if (!this->is_within_bound(e->motion.x, e->motion.y))
        return false;

    for (ChildElement* child : this->m_child_elements) {
        IUIElement* elem = child->elem;

        // NOTE: skip non-active elements
        if (!elem->is_active()) continue;

        // converts the element to a EventReciver*, this will return
        // nullptr if it is not a EventReciver
        EventReciver* reciver = dynamic_cast<EventReciver*>(elem);

        // skip non-EventRecivers
        if (reciver == nullptr) continue;

        // handle the EventReciver
        if (reciver->handle_event(e))
            return true;
    }
    return false;
}

void ItemFrame::show(void) {
    for (ChildElement* child : this->m_child_elements) {
        if (!child->should_render)
            continue;
        child->elem->show();
    }
}

void ItemFrame::update(void) {
    for (ChildElement* child : this->m_child_elements) {
        if (!child->should_render)
            continue;
        child->elem->update();
    }
}

bool ItemFrame::is_within_bound(SDL_Rect* elem_bound) {
    bool is_too_high = (elem_bound->y + elem_bound->h) < this->m_bound.y;
    bool is_too_low = elem_bound->y > (this->m_bound.y + this->m_bound.h);
    bool too_far_left = (elem_bound->x + elem_bound->w) < this->m_bound.x;
    bool too_far_right = elem_bound->x > (this->m_bound.x + this->m_bound.w);

    return !(is_too_high || is_too_low || too_far_left || too_far_right);
}

bool ItemFrame::is_within_bound(int mouse_x, int mouse_y) {
    SDL_Rect* bound = &this->m_bound;

    bool too_far_left = mouse_x < bound->x;
    bool too_far_right = mouse_x > bound->x + bound->w;
    bool is_too_high = mouse_y < bound->y;
    bool is_too_low = mouse_y > bound->y + bound->h;

    return !(too_far_left || too_far_right || is_too_high || is_too_low);
}