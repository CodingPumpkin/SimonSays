#pragma once

#include <stdint.h>
#include <stdlib.h>
#include <time.h>

#define QUEUE_BUFFER_SIZE 4

enum players {Simon, Player};
enum queue_items {Red, Green, Blue, Yellow};

struct {
    uint8_t turn;
    uint8_t game_over;
    uint8_t *queue;
    uint8_t *current_queue_ptr;
} *game_state;

void init_queue(uint8_t *arr);
