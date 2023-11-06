
#include <SDL.h>
#include <cstdlib>
#include <cstdarg>
#include <vector>

#include "EventReciver.hpp"
#include "Layer.hpp"

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
    if (this->m_subscribers.size() > 20 && !this->m_orginized) {
        this->orignize();
        this->m_orginized = true;
    }

    if (!this->m_orginized) {
        m_subscribers.push_back(reciver);
        return;
    }

}
