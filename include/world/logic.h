#ifndef LOGIC_H
#define LOGIC_H

#include <world/world.h>

#define LOGIC_VALID   1
#define LOGIC_INVALID 0

int logic_is_block_valid(__world_t *__world, __position_t *__position);

#endif