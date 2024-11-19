#pragma once

#include <stdint.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
uint8_t is_running = FALSE;
struct simon_button red, green, yellow, blue;
int32_t m_x, m_y;

//Window related methods
int init_window(void);
void destroy_window(void);

//Game related methods
void setup(void);
void process_input(void);
void update(void);
void draw(void);
void setup_rect(char);

//Additional methods
uint8_t check_in_bounds(struct simon_button, int32_t, int32_t);
void reset(void);
