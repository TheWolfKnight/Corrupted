
#include <SDL.h>

#include "Application.hpp"
#include "IUIElement.hpp"

SDL_Surface* Application::get_window_surface(void) {
    return this->m_window->get_window_surface();
}

void Application::quit(void) {
    SDL_Event quit_event{ SDL_QUIT };
    SDL_PushEvent(&quit_event);
}

void Application::update_display(void) {
    SDL_Surface* window_surface = this->get_window_surface();
    SDL_FillRect(
        window_surface,
        &this->m_window->window_size,
        SDL_MapRGB(window_surface->format, 0, 0, 0)
    );

    for (IUIElement* elem : this->m_display_elements) {
        elem->update();
        elem->show();
    }

    this->m_window->render_frames();
}

void Application::add_display_element(IUIElement* elem) {

    this->m_display_elements.push_back(elem);

    EventReciver* reciver = dynamic_cast<EventReciver*>(elem);
    if (reciver != nullptr)
        m_ui->subscribe(reciver);
}

bool Application::handle_event(SDL_Event* e) {

    if (this->m_ui == nullptr) return false;

    return m_ui->handle_event(e);
}
