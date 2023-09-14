
#include <SDL.h>
#include <cstdlib>
#include <cstdarg>
#include <vector>

#include "EventReciver.hpp"
#include "ItemFrame.hpp"
#include "Layer.hpp"

#define MAX_LAYER_ELEMENT_COUNT 20

void Layer::orignize(void) {
    SDL_Rect* bound = this->m_parent->get_bounding_box();

    int half_width = bound->w / 2;
    int half_hight = bound->h / 2;

    ItemFrame* top_left = new ItemFrame(this->m_parent, 0, 0, half_width, half_hight);
    ItemFrame* top_right = new ItemFrame(this->m_parent, half_width, 0, half_width, half_hight);
    ItemFrame* bottom_left = new ItemFrame(this->m_parent, 0, half_hight, half_width, half_hight);
    ItemFrame* bottem_right = new ItemFrame(this->m_parent, half_width, half_hight, half_width, half_hight);
}

bool Layer::handle_event(SDL_Event* event) {
    for (EventReciver* handler : this->m_subscribers) {
        if (handler->handle_event(event))
            return true;
    }
    return false;
}

void Layer::subscribe(EventReciver* reciver) {
    if (this->m_subscribers.size() > MAX_LAYER_ELEMENT_COUNT && !this->m_orginized) {
        this->orignize();
        this->m_orginized = true;
    }

    if (!this->m_orginized) {
        m_subscribers.push_back(reciver);
        return;
    }

    for (EventReciver* revicer : this->m_subscribers) {
        ItemFrame* frame = dynamic_cast<ItemFrame*>(reciver);

        if (frame == nullptr) throw "frame not found exception";


    }
}
