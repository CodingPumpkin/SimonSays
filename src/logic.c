#include "./logic.h"

void setup_game()
{
    game_state->turn = Simon;
    game_state->game_over = 0;
    init_queue(game_state->queue);
    game_state->current_queue_ptr=game_state->queue;
}

void init_queue(uint8_t *arr)
{
    arr = (uint8_t *) malloc(sizeof(uint8_t) * QUEUE_BUFFER_SIZE);
}

void generate_queue(uint8_t *arr)
{
    srand(time(NULL));

}

void expand_queue()
{

}

void move_queue_ptr()
{

}

