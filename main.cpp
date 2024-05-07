// C++ Standard Libraries
#include <print>

// Third-Party library
#include <SDL.h>

int main(int argc, char* argv[]) {
	SDL_Window* window = nullptr;			// Declare a pointer

	if (SDL_Init(SDL_INIT_VIDEO) < 0)		// Initialize SDL2 & Check if succesful
	{
		std::print("SDL could not be initialized: {0}", SDL_GetError());
	}
	else {
		std::print("SDL video system is ready to go\n");
	}

	// Grab the users display resolution
	SDL_DisplayMode current;
	SDL_GetCurrentDisplayMode(0, &current);
	auto Width = current.w;
	auto Height = current.h;

	// Create an application window with the following setttings:
	window = SDL_CreateWindow(
		"Falling Sand Simulator",			// window title
		SDL_WINDOWPOS_CENTERED,				// the x position of the window 
		SDL_WINDOWPOS_CENTERED,				// the y position of the window
		Width,								// width, in pixels
		Height,								// height, in pixels
		SDL_WINDOW_FULLSCREEN_DESKTOP);		// flag

	// Check that the window was successfully created
	if (window == NULL)
	{
		// In the case that the window could not be made...
		std::print("Could not create window: {0}", SDL_GetError());
		return 1;
	}

	bool running = true;
	bool mouseDown = false;
	int mouseX;
	int mouseY;


	while (running)
	{
		SDL_Event event;
		// Start the event loop
		while (SDL_PollEvent(&event))
		{
			switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				mouseDown = true;
				std::print("mouse button down\n");
				break;
			case SDL_MOUSEBUTTONUP:
				mouseDown = false;
				std::print("mouse button up\n");
				break;
			case SDL_MOUSEMOTION:
				SDL_GetMouseState(&mouseX, &mouseY);
				std::print("mouse x: {0} mouse y: {1}\n", mouseX, mouseY);
				if (mouseDown) {
					std::print("mouse down and moving\n");
				}
				break;
			case SDL_QUIT:
				running = false;
				break;
			default:
				break;
			}

		}

	}

	SDL_DestroyWindow(window);

	SDL_Quit();
	return 0;
}