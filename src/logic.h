#ifndef GAME_LOGIC_H
#define GAME_LOGIC_H

#include <stdint.h>
#include <stdlib.h>
#include <time.h>
#include <stdio.h>

#include "constants.h"

enum players {Simon, Player};
enum queue_items {Red, Green, Blue, Yellow, End};

struct game_state_struct;

void init_queue(void);
void generate_queue(void);
void setup_game_state_struct(void);

#endif
