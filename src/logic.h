#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#define QUEUE_BUFFER_SIZE 4

enum players {Simon, Player};
enum queue_items {Red, Green, Blue, Yellow, End};

struct game_state_struct{
    uint8_t turn;
    uint8_t game_over;
    struct {
        uint8_t *current_ptr;
        uint8_t *contents_end_ptr;
        uint16_t length;
        uint8_t *arr;
    } queue;
};
// } *game_state;

void init_queue(void);
void generate_queue(void);
void setup_game_state_struct(void);

#endif
