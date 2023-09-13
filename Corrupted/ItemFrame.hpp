#pragma once

#include <SDL.h>
#include <memory>
#include <vector>

#include "ArenaAllocator.hpp"
#include "Application.hpp"
#include "IUIElement.hpp"
#include "EventReciver.hpp"

struct ChildElement {
public:
    IUIElement* elem;
    bool should_render{ true };

    inline explicit ChildElement(void) = default;

    inline explicit ChildElement(IUIElement* elem) {
        this->elem = elem;
    }
};

class ItemFrame : public IUIElement, public EventReciver {
public:

    inline explicit ItemFrame(Application* parent, int x, int y, int w, int h) {
        this->m_parent = parent;
        this->m_bound = SDL_Rect{ x, y, w, h };
        this->m_allocator = ArenaAllocator(1024 * 2);
    }

    void add_child(IUIElement* elem);

    bool handle_event(SDL_Event* e);

    void show(void);
    void update(void);

    ~ItemFrame() {
        /*this->m_allocator.dealloc(NULL);*/
    }

private:
    Application* m_parent{ nullptr };
    SDL_Rect m_bound{};

    ArenaAllocator m_allocator;
    std::vector<ChildElement*> m_child_elements;

private:

    bool is_within_bound(SDL_Rect* elem_bound);
    bool is_within_bound(int mouse_x, int mouse_y);

};
