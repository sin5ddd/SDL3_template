#define SDL_MAIN_USE_CALLBACKS 1
#include <string>
#include <SDL3/SDL.h>
#include <SDL3/SDL_main.h>

#include "AppMain.h"

static SDL_Window *window = nullptr;
static SDL_Renderer *renderer = nullptr;
Uint64 frame = 0;
AppMain *appMain;
bool is_fullscreen = false;

SDL_AppResult SDL_AppInit(void **appstate, int argc, char *argv[]) {
    constexpr int width = 320;
    constexpr int height = 240;
    if (!SDL_CreateWindowAndRenderer("Hello World", width, height, SDL_WINDOW_RESIZABLE, &window, &renderer)) {
        SDL_Log("Couldn't create window and renderer: %s\n", SDL_GetError());
        return SDL_APP_FAILURE;
    }
    appMain = new AppMain(window, renderer);
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppEvent(void *appstate, SDL_Event *event) {
    SDL_Log("Framerate: %d\n", SDL_GetTicks() - frame);
    if (event->type == SDL_EVENT_KEY_DOWN) {
        auto key = event->key.key;
        if (key == SDLK_F) {
            is_fullscreen = !is_fullscreen;
            SDL_SetWindowFullscreen(window, is_fullscreen);
        }
        if (
            key == SDLK_Q || key == SDLK_ESCAPE || event->type == SDL_EVENT_QUIT) {
            return SDL_APP_SUCCESS; /* end the program, reporting success to the OS. */
            }
    }
    return SDL_APP_CONTINUE;
}

SDL_AppResult SDL_AppIterate(void *appstate) {
    auto current_frame = SDL_GetTicks();
    if (current_frame - frame > 16) {
        std::string message = "Hello World!";
        appMain->main_loop(message, current_frame - frame);
        frame = SDL_GetTicks();
    }
    return SDL_APP_CONTINUE;
}


void SDL_AppQuit(void *appstate, SDL_AppResult result) {

}
