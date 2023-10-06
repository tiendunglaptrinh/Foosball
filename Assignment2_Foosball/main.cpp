#include <SDL.h>

int main(int argc, char* argv[]) {
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("SDL_Init Error: %s", SDL_GetError());
        return 1;
    }

    SDL_Window* window = SDL_CreateWindow("Mini Soccer Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, SDL_WINDOW_SHOWN);
    if (!window) {
        SDL_Log("SDL_CreateWindow Error: %s", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer) {
        SDL_Log("SDL_CreateRenderer Error: %s", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_SetRenderDrawColor(renderer, 0, 255, 0, 255);

    // Game loop
    bool quit = false;
    SDL_Event event;
    while (!quit) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                quit = true;
            }
        }

        SDL_RenderClear(renderer);

        SDL_Rect fieldRect = { 50, 50, 700, 500 };
        SDL_RenderFillRect(renderer, &fieldRect);

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_Rect topBorder = { 50, 50, 700, 5 };
        SDL_Rect bottomBorder = { 50, 545, 700, 5 };
        SDL_Rect leftBorder = { 50, 50, 5, 500 };
        SDL_Rect rightBorder = { 745, 50, 5, 500 };
        SDL_RenderFillRect(renderer, &topBorder);
        SDL_RenderFillRect(renderer, &bottomBorder);
        SDL_RenderFillRect(renderer, &leftBorder);
        SDL_RenderFillRect(renderer, &rightBorder);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    return 0;
}
