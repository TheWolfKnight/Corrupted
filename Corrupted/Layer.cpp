
#include <SDL.h>
#include <cstdlib>

#include "EventReciver.hpp"
#include "Layer.hpp"

bool Layer::handle_event(SDL_Event* event) {
    for (const auto handler : this->m_subscribers) {
        if (handler->handle_event(event))
            return true;
    }
    return false;
}

void Layer::subscribe(EventReciver* reciver) {
    this->m_subscribers.push_back(reciver);
}
