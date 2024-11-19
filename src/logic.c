#include "./logic.h"

struct game_state_struct{
    uint8_t turn;
    uint8_t game_over;
    struct {
        uint8_t *current_ptr;
        uint8_t *contents_end_ptr;
        uint16_t length;
        uint8_t *arr;
    } queue;
} *game_state;

void setup_game_state_struct()
{
    game_state = (struct game_state_struct *) malloc(sizeof(struct game_state_struct));
    game_state->turn = Simon;
    game_state->game_over = 0;
    init_queue();
}

void init_queue()
{
    game_state->queue.arr = (uint8_t *) malloc(sizeof(uint8_t) * QUEUE_BUFFER_SIZE);
    game_state->queue.length = QUEUE_BUFFER_SIZE;
    game_state->queue.current_ptr = game_state->queue.arr;
    game_state->queue.contents_end_ptr = game_state->queue.arr;
}

void generate_queue()
{
    srand(time(NULL));
    for(uint8_t i = 0; i < QUEUE_BUFFER_SIZE; i++)
    {
        *game_state->queue.contents_end_ptr = rand() % 4;
        printf("%d\t", *game_state->queue.contents_end_ptr);
        game_state->queue.contents_end_ptr++;
    }
    printf("\n");
}

void expand_queue()
{

}

void move_queue_ptr()
{

}

