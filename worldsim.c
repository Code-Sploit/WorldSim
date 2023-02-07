#include <world/world.h>
#include <world/logic.h>

#include <stdio.h>

int main(int argc, char** argv)
{
    printf("Starting world...\n");

    __world_t *__global_world = world_create();

    printf("World started!\n");
    printf("Creating a random node and running a check on it to see if logic evaluation works!\n");

    world_set_node(__global_world, position_new(25, 3, 8), node_cache(AIR, CANFLOAT, WORLD_NODE_USED));

    int __return1 = logic_is_block_valid(__global_world, position_new(25, 3, 8));

    world_set_node(__global_world, position_new(25, 2, 8), node_cache(STONE, NOFLOAT, WORLD_NODE_USED));

    int __return2 = logic_is_block_valid(__global_world, position_new(25, 3, 8));

    printf("\nLOGIC CHECK 1: [%d]\n", __return1);
    printf("LOGIC CHECK 2: [%d]\n", __return2);

    return 0;
}