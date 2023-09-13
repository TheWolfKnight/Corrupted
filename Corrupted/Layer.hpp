#pragma once

#include <SDL.h>
#include <vector>
#include <cstdlib>
#include <cstdarg>

#include "EventReciver.hpp"

class Layer {
public:
    bool handle_event(SDL_Event* event);
    void subscribe(EventReciver* reciver);
private:
    std::vector<EventReciver*> m_subscribers;
};