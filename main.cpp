// C++ Standard Libraries
#include <iostream>

// Third-Party library
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* window = nullptr;			// Declare a pointer

	if (SDL_Init(SDL_INIT_VIDEO) < 0) {		// Initialize SDL2 & Check if succesful
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	} else {
		std::cout << "SDL video system is ready to go\n";
	}

	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	auto Width = current.w;
	auto Height = current.h;

	// Create an application window with the following setttings:
	window = SDL_CreateWindow(
		"Falling Sand Simulator",   // window title
		SDL_WINDOWPOS_CENTERED,		// the x position of the window 
		SDL_WINDOWPOS_CENTERED,		// the y position of the window
		Width - 100,				// width, in pixels
		Height - 100,				// height, in pixels (-50 for windows taskbar)
		SDL_WINDOW_SHOWN);			// flag

	// Check that the window was successfully created
	if (window == NULL) {
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError;
		return 1;
	}

	bool gameIsRunning = true;
	while (gameIsRunning) {
		SDL_Event event;
		// Start the event loop
		while (SDL_PollEvent(&event)) {
			if (event.type == SDL_QUIT) {
				gameIsRunning = false;
			}
			if (event.type == SDL_MOUSEBUTTONDOWN) {
				std::cout << "mouse has been clicked test" << '\n';
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}