#pragma once

#include <SDL.h>
#include <vector>

#include "ArenaAllocator.hpp"
#include "IApplication.hpp"
#include "IUIElement.hpp"
#include "EventReciver.hpp"

struct ChildElement {
public:
    IUIElement* elem;
    bool out_of_frame;

    inline explicit ChildElement(void) = default;

    inline explicit ChildElement(IUIElement* elem) {
        this->elem = elem;
        this->out_of_frame = false;
    }
};

class ItemFrame : public IUIElement, public EventReciver {
public:
    inline explicit ItemFrame(IApplication* parent, SDL_Rect bound) {
        this->m_parent = parent;
        this->m_bound = bound;
        this->m_allocator = new ArenaAllocator(1024 * 2);
    }

    inline explicit ItemFrame(IApplication* parent, int x, int y, int w, int h) {
        this->m_parent = parent;
        this->m_bound = SDL_Rect{ x, y, w, h };
        this->m_allocator = new ArenaAllocator(1024 * 2);
    }

    void add_child(IUIElement* elem);

    bool handle_event(SDL_Event* e);
    bool is_within_bound(SDL_Rect* elem_bound);
    bool is_within_bound(int mouse_x, int mouse_y);

    void show(void);
    void update(void);

    ~ItemFrame() {
        delete this->m_allocator;
    }

private:
    IApplication* m_parent{ nullptr };

    ArenaAllocator* m_allocator;
    std::vector<ChildElement*> m_child_elements;
};
