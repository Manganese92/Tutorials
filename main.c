#include <stdio.h>
#include <stdbool.h>
#include "SDL2/SDL.h"

//Defining screen size by constant
const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

int main(int argc, char *argv[]) {
	//The window we'll be working with
	SDL_Window *window = NULL;
	//The surface contained by the window
	SDL_Surface *screenSurface = NULL;
	//Event variable we'll be using
	SDL_Event e;
	//The boolean for the event loop
	bool quit = false;
	
	//Making sure SDL is initialized
	if (SDL_Init(SDL_INIT_VIDEO) < 0) {
		fprintf(stderr, "SDL could not initialize correctly => SDL_Error: %s\n", SDL_GetError());
	} else {
		//Creating window here
		window = SDL_CreateWindow("First SDL", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT,SDL_WINDOW_SHOWN);
		//Making sure window have been created correctly
		if (window == NULL) {
			fprintf(stderr, "Window could not be created correctly => SDL_Error: %s\n", SDL_GetError());
		} else {
			//If everything is good, we render the surface into the window
			screenSurface = SDL_GetWindowSurface(window);
			//Filling the surface with RGB color
			SDL_FillRect(screenSurface, NULL, SDL_MapRGB(screenSurface->format, 0x2C, 0x25, 0xFF));
			SDL_UpdateWindowSurface(window);
			
			//Main even loop over here
			while (quit == false) {
				while (SDL_PollEvent(&e)) {
					if (e.type == SDL_QUIT) {
						quit = true;
					}
				}
			}
			
		}
	}
	
	SDL_FreeSurface(screenSurface);
	SDL_DestroyWindow(window);
	SDL_Quit();
	
	return 0;
}
