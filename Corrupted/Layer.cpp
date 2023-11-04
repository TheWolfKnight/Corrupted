
#include <SDL.h>
#include <cstdlib>
#include <cstdarg>
#include <vector>

#include "EventReciver.hpp"
#include "Layer.hpp"

#define MAX_LAYER_ELEMENT_COUNT 20

void Layer::orignize(void) {
    throw "Not Implemented";
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

}
