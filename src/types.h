#pragma once
typedef struct {
	int x;
	int y;
	SDL_Rect r;
	SDL_Colour colour;
	int is_pressed;
} simon_button;

enum players {Simon, Player};
enum queue_items {Red, Green, Blue, Yellow};

struct game_state {
	int turn;
	int game_over;
};
