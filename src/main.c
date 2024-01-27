#include <stdio.h>
#include <SDL2/SDL.h>

#include "./constants.h"
#include "./types.h"
#include "./simon_says.h"

int main(int argc, char *argv[])
{
	is_running = TRUE;
	init_window();
	setup();
	while (is_running)
	{
		process_input();
		update();
		draw();
	}
	destroy_window();
	return 0;
}

int init_window(void)
{
	if(SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return FALSE;
	}
	window = SDL_CreateWindow(
		"Simon Says",
		SDL_WINDOWPOS_CENTERED,
		SDL_WINDOWPOS_CENTERED,
		WINDOW_WIDTH,
		WINDOW_HEIGHT,
		0
	);
	if (!window)
	{
		fprintf(stderr, "Error initializing window.\n");
		return FALSE;
	}
	renderer = SDL_CreateRenderer(window, -1, 0);
	if (!renderer)
	{
		fprintf(stderr, "Error initializing renderer.\n");
		return FALSE;
	}
	return TRUE;
}

void process_input(void)
{
	SDL_Event event;
	SDL_PollEvent(&event);

	switch (event.type) 
	{
		case SDL_QUIT:
			is_running = FALSE;
			break;
		case SDL_MOUSEBUTTONDOWN:
			SDL_GetMouseState(&m_x, &m_y);
			red.is_pressed = check_in_bounds(red, m_x, m_y);
			yellow.is_pressed = check_in_bounds(yellow, m_x, m_y);
			blue.is_pressed = check_in_bounds(blue, m_x, m_y);
			green.is_pressed = check_in_bounds(green, m_x, m_y);
			break;
		case SDL_MOUSEBUTTONUP:
			reset();
	}
}

int check_in_bounds(simon_button sb, int x, int y)
{
	return x >= sb.r.x && x <= (sb.r.x+sb.r.w) && y >= sb.r.y && y <= (sb.r.y + sb.r.h) ? 1 : 0;
}

void setup(void)
{
	SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
	SDL_RenderClear(renderer);

	setup_rect('r');
	SDL_RenderFillRect(renderer, &(red.r));

	setup_rect('g');
	SDL_RenderFillRect(renderer, &(green.r));

	setup_rect('b');
	SDL_RenderFillRect(renderer, &(blue.r));

	setup_rect('y');
	SDL_RenderFillRect(renderer, &(yellow.r));

	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);

	SDL_RenderPresent(renderer);
}

void update(void)
{
}

void draw(void)
{
	SDL_SetRenderDrawColor(renderer, 220, 220, 220, 255);
	SDL_RenderClear(renderer);

	SDL_SetRenderDrawColor(renderer, red.colour.r  - red.is_pressed*PRESSED, red.colour.g, red.colour.b, red.colour.a);
	SDL_RenderFillRect(renderer, &(red.r));

	SDL_SetRenderDrawColor(renderer, green.colour.r, green.colour.g - green.is_pressed*PRESSED, green.colour.b, green.colour.a);
	SDL_RenderFillRect(renderer, &(green.r));

	SDL_SetRenderDrawColor(renderer, blue.colour.r, blue.colour.g, blue.colour.b  - blue.is_pressed*PRESSED, blue.colour.a);
	SDL_RenderFillRect(renderer, &(blue.r));

	SDL_SetRenderDrawColor(renderer, yellow.colour.r  - yellow.is_pressed*PRESSED, yellow.colour.g  - yellow.is_pressed*PRESSED, yellow.colour.b, yellow.colour.a);
	SDL_RenderFillRect(renderer, &(yellow.r));

	SDL_RenderPresent(renderer);
}

void setup_rect(char c)
{
	switch (c)
	{
		case 'r':
			red.r.x = WINDOW_WIDTH/2 - SQUARE_SIZE - OFFSET;
			red.r.y = WINDOW_HEIGHT/2 - SQUARE_SIZE - OFFSET;
			red.r.w = SQUARE_SIZE;
			red.r.h = SQUARE_SIZE;
			red.colour.r = 255;
			red.colour.g = 0;
			red.colour.b = 0;
			red.colour.a = 255;
			SDL_SetRenderDrawColor(renderer, red.colour.r, red.colour.g, red.colour.b, red.colour.a);
			break;
		case 'g':
			green.r.x = WINDOW_WIDTH/2 + OFFSET;
			green.r.y = WINDOW_HEIGHT/2 - SQUARE_SIZE - OFFSET;
			green.r.w = SQUARE_SIZE;
			green.r.h = SQUARE_SIZE;
			green.colour.a = 255;
			green.colour.r = 0;
			green.colour.g = 255;
			green.colour.b = 0;
			SDL_SetRenderDrawColor(renderer, green.colour.r, green.colour.g, green.colour.b, green.colour.a);
			break;
		case 'b':
			blue.r.x = WINDOW_WIDTH/2 - SQUARE_SIZE - OFFSET;
			blue.r.y = WINDOW_HEIGHT/2 + OFFSET;
			blue.r.w = SQUARE_SIZE;
			blue.r.h = SQUARE_SIZE;
			blue.colour.a = 255;
			blue.colour.r = 0;
			blue.colour.g = 0;
			blue.colour.b = 255;
			SDL_SetRenderDrawColor(renderer, blue.colour.r, blue.colour.g, blue.colour.b, blue.colour.a);
			break;
		case 'y':
			yellow.r.x = WINDOW_WIDTH/2 + OFFSET;
			yellow.r.y = WINDOW_HEIGHT/2 + OFFSET;
			yellow.r.w = SQUARE_SIZE;
			yellow.r.h = SQUARE_SIZE;
			yellow.colour.a = 255;
			yellow.colour.r = 255;
			yellow.colour.g = 255;
			yellow.colour.b = 0;
			SDL_SetRenderDrawColor(renderer, yellow.colour.r, yellow.colour.g, yellow.colour.b, yellow.colour.a);
			break;
	}
}

void reset()
{
	red.is_pressed = FALSE;
	blue.is_pressed = FALSE;
	green.is_pressed = FALSE;
	yellow.is_pressed = FALSE;
}

void destroy_window(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}
