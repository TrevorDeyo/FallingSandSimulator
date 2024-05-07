// C++ Standard Libraries
#include <iostream>

// Third-Party library
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* window = nullptr;			// Declare a pointer

	if (SDL_Init(SDL_INIT_VIDEO) < 0)		// Initialize SDL2 & Check if succesful
	{
		std::cout << "SDL could not be initialized: " << SDL_GetError();
	} 
	else {
		std::cout << "SDL video system is ready to go\n";
	}

	// Grab the users display resolution
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	auto Width = current.w;
	auto Height = current.h;

	// Create an application window with the following setttings:
	window = SDL_CreateWindow(
		"Falling Sand Simulator",   // window title
		SDL_WINDOWPOS_CENTERED,		// the x position of the window 
		SDL_WINDOWPOS_CENTERED,		// the y position of the window
		Width,						// width, in pixels
		Height,						// height, in pixels
		SDL_WINDOW_FULLSCREEN_DESKTOP);		// flag

	// Check that the window was successfully created
	if (window == NULL)
	{
		// In the case that the window could not be made...
		std::cout << "Could not create window: " << SDL_GetError;
		return 1;
	}

	bool running = true;
	while (running)
	{
		SDL_Event event;
		// Start the event loop
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else if (event.type == SDL_MOUSEBUTTONDOWN)
			{
				std::cout << "mouse button down\n";
			}
			else if (event.type == SDL_MOUSEBUTTONUP)
			{
				std::cout << "mouse button up\n";
			}
		}
	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}