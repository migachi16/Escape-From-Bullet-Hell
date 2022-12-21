#include <../Escape From Bullet Hell/include/SDL.h>

int main(int argc, char* argv[]) {
    // Initialize SDL
    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        SDL_Log("Failed to initialize SDL: %s", SDL_GetError());
        return 1;
    }

    // Create the game window
    SDL_Window* window = SDL_CreateWindow(
        "My Game",                      // window title
        SDL_WINDOWPOS_CENTERED,         // initial x position
        SDL_WINDOWPOS_CENTERED,         // initial y position
        640,                            // width, in pixels
        480,                            // height, in pixels
        SDL_WINDOW_RESIZABLE            // window flags
    );

    if (window == nullptr) {
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return 1;
    }

    // Create the renderer
    SDL_Renderer* renderer = SDL_CreateRenderer(
        window,                         // window to create renderer for
        -1,                             // index of the rendering driver to initialize
        SDL_RENDERER_ACCELERATED |      // flags for renderer creation
        SDL_RENDERER_PRESENTVSYNC
    );

    if (renderer == nullptr) {
        SDL_Log("Failed to create renderer: %s", SDL_GetError());
        return 1;
    }

    // Main game loop
    bool running = true;
    while (running) {
        // Process events
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                running = false;
            }
            else if (event.type == SDL_KEYDOWN) {
                // Handle key press events
            }
            else if (event.type == SDL_MOUSEBUTTONDOWN) {
                // Handle mouse click events
            }
        }

        // Update game state
        // ... update positions of game objects, check for collisions, etc. ...

        // Render the game
        SDL_RenderClear(renderer);
        // ... render game objects here ...
        SDL_RenderPresent(renderer);
    }

    // Clean up SDL resources
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();

    // Return success
    return 0;
}