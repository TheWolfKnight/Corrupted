#pragma once

#include <SDL.h>
#include <vector>
#include <cstdlib>

#include "EventReciver.hpp"
#include "IApplication.hpp"

class Layer {
public:
    inline explicit Layer(IApplication* app) {
        this->m_parent = app;
        this->m_max_orginization_depth = 5;
    }

    inline explicit Layer(IApplication* app, unsigned int max_orginization_depth) {
        this->m_max_orginization_depth = max_orginization_depth;
        this->m_parent = app;
    }

    bool handle_event(SDL_Event* event);
    void subscribe(EventReciver* reciver);

    inline ~Layer() {
        for (EventReciver* reciver : this->m_subscribers) delete reciver;
    }

private:
    unsigned int m_max_orginization_depth;

    IApplication* m_parent{ nullptr };

    std::vector<EventReciver*> m_subscribers;
    bool m_orginized{ false };
private:
    void orignize(void);
};
