#pragma once

#include <stdint.h>

struct simon_button {
	int x;
	int y;
	SDL_Rect r;
	SDL_Colour colour;
	int is_pressed;
};

struct simon_button simbut;
