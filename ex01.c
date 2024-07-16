#include <SDL2.h>

int main() {
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window *window = SDL_CreateWindow("Meu Jogo", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, 0);
    SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, 0);

    int x = 100, y = 300; // Posição inicial do sprite
    SDL_Event event;

    int running = 1;
    while (running) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = 0;
            }
            if (event.type == SDL_MOUSEBUTTONDOWN) {
                x += 10; // Move para a direita ao clicar
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255); // Fundo branco
        SDL_RenderClear(renderer);

        SDL_Rect rect = {x, y, 50, 50}; // Define o retângulo do sprite
        SDL_SetRenderDrawColor(renderer, 0, 0, 255); // Cor do sprite
        SDL_RenderFillRect(renderer, &rect);

        SDL_RenderPresent(renderer);
    }

    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
