#include <world/world.h>

#include <stdlib.h>
#include <stdio.h>

__world_t *world_create(void)
{
    __world_t *__world = calloc(1, sizeof(__world_t));

    for (int x = 0; x < WORLD_X_MAX; x++)
    {
        for (int y = 0; y < WORLD_Y_MAX; y++)
        {
            for (int z = 0; z < WORLD_Z_MAX; z++)
            {
                printf("WORLD: Creating node: [%d : %d : %d]\n", x, y, z);

                world_add_node(__world, position_new(x, y, z));
            }
        }
    }

    return __world;
}

__node_t *world_find_node(__world_t *__world, __position_t *__position)
{
    if (!__position)
    {
        /*
        * TODO: Add debugger
        */

        return NULL;
    }

    if (__position->__x > WORLD_X_MAX ||
        __position->__y > WORLD_Y_MAX ||
        __position->__z > WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return NULL;
    }

    if (__position->__x < -WORLD_X_MAX ||
        __position->__y < -WORLD_Y_MAX ||
        __position->__z < -WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return NULL;
    }

    return &__world->__base[__position->__x][__position->__y][__position->__z];
}

void world_remove_node(__world_t *__world, __position_t *__position)
{
    if (!__position)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    if (__position->__x > WORLD_X_MAX ||
        __position->__y > WORLD_Y_MAX ||
        __position->__z > WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    if (__position->__x < -WORLD_X_MAX ||
        __position->__y < -WORLD_Y_MAX ||
        __position->__z < -WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    __world->__base[__position->__x][__position->__y][__position->__z].__used = WORLD_NODE_UNUSED;
}

void world_add_node(__world_t *__world, __position_t *__position)
{
    if (!__position)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    if (__position->__x > WORLD_X_MAX ||
        __position->__y > WORLD_Y_MAX ||
        __position->__z > WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    if (__position->__x < -WORLD_X_MAX ||
        __position->__y < -WORLD_Y_MAX ||
        __position->__z < -WORLD_Z_MAX)
    {
        /*
        * TODO: Add debugger
        */

        return;
    }

    __world->__base[__position->__x][__position->__y][__position->__z].__used   = WORLD_NODE_UNUSED;
    __world->__base[__position->__x][__position->__y][__position->__z].__floats = NOFLOAT;
}

void world_move_node(__world_t *__world, __position_t *__position_src, __position_t *__position_dst, int __forced)
{
    if (!__world || !__position_src || !__position_dst)
    {
        return;
    }

    __node_t *__src = world_find_node(__world, __position_src);
    __node_t *__dst = world_find_node(__world, __position_dst);

    if (__dst->__used == WORLD_NODE_USED && __forced == 0)
    {
        return;
    }

    __world->__base[__position_dst->__x][__position_dst->__y][__position_dst->__z] = __world->__base[__position_src->__x][__position_src->__y][__position_src->__z];
}