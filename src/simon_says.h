#pragma once

#include <stdint.h>

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
u_int8_t is_running = FALSE;
simon_button red, green, yellow, blue;
u_int32_t m_x, m_y;

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
u_int8_t check_in_bounds(simon_button, u_int32_t, u_int32_t);
void reset(void);
