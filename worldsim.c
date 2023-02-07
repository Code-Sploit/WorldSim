#include <world/world.h>

#include <stdio.h>

int main(int argc, char** argv)
{
    printf("Starting world...\n");

    __world_t *__global_world = world_create();

    printf("World started!\n");

    while (1)
    {
        /* Hang */
    }

    return 0;
}