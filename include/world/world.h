#ifndef WORLD_H
#define WORLD_H

#include <world/position.h>

#define WORLD_X_MAX 64
#define WORLD_Y_MAX 64
#define WORLD_Z_MAX 64

#define WORLD_NODE_USED   1
#define WORLD_NODE_UNUSED 0

typedef enum
{
    AIR,
    DIRT,
    GRASS,
    WOOD,
    STONE,
    FIRE,
    WATER
} __node_type;

typedef enum
{
    CANFLOAT,
    NOFLOAT
} __node_float;

typedef struct __node
{
    __node_type __type;
    __node_float __floats;

    int __used;
} __node_t;

typedef struct __world
{
    /*
    * TODO: Add array of objects living in the world
    */

    /*
    * We need a 3 dimensional array
    * for all the nodes in our world
    */

    __node_t __base[WORLD_X_MAX][WORLD_Y_MAX][WORLD_Z_MAX];
} __world_t;

__world_t *world_create(void);

__node_t *node_create(int __type, int __floats, int __used);
__node_t node_cache(int __type, int __floats, int __used);
__node_t *world_find_node(__world_t *__world, __position_t *__position);

void world_remove_node(__world_t *__world, __position_t *__position);
void world_add_node(__world_t *__world, __position_t *__position);
void world_set_node(__world_t *__world, __position_t *__position, __node_t __node);

void world_move_node(__world_t *__world, __position_t *__position_src, __position_t *__position_dst, int __forced);

#endif