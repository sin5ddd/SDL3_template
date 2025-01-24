//
// Created by kitayama on 25/01/24.
//

#ifndef APPMAIN_H
#define APPMAIN_H
#include <string>
#include <SDL3/SDL.h>


class AppMain {
private:
    SDL_Window *window;
    SDL_Renderer *renderer;
    int w, h;
    const float scale = 4.0f;

public:
    AppMain(SDL_Window *window, SDL_Renderer *renderer) {
        this->window = window;
        this->renderer = renderer;
        w = 0;
        h = 0;
    }

    int main_loop(std::string &message, unsigned long long delta_tick) {
        SDL_GetRenderOutputSize(renderer, &w, &h);
        SDL_SetRenderScale(renderer, scale, scale);

        SDL_SetRenderScale(renderer, scale, scale);
        float pos_x = (w / scale - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(message.c_str())) / 2;
        float pos_y = (h / scale - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE) / 2;
        auto delta_ms = std::to_string(delta_tick / 16 ).append("/60 fps");
        float pos_x_delta = ((w / scale) - SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * SDL_strlen(delta_ms.c_str())) / 2;


        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);
        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderDebugText(renderer, pos_x, pos_y, message.c_str());
        SDL_RenderDebugText(renderer, pos_x_delta, pos_y + SDL_DEBUG_TEXT_FONT_CHARACTER_SIZE * 1.5, delta_ms.c_str());
        SDL_RenderPresent(renderer);

        return 0;
    }
};


#endif //APPMAIN_H
