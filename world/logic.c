#include <world/logic.h>

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int logic_is_block_valid(__world_t *__world, __position_t *__position)
{
    __node_t *__node = world_find_node(__world, __position);
    
    /*
    * Check if the node is used
    */
    
    if (__node->__used == WORLD_NODE_UNUSED)
    {
        return LOGIC_VALID;
    }

    /*
    * Check if the node can float because then it should always be valid
    * TODO: Add chemical reactions
    */

    if (__node->__floats)
    {
        return LOGIC_VALID;
    }

    /*
    * If the node cannot float then get the node beneath it
    */
   
    __position_t *__oposition = calloc(1, sizeof(__position_t));
    __position_t *__bposition = calloc(1, sizeof(__position_t));

    memcpy(__oposition, __position, sizeof(__position_t));
    memcpy(__bposition, __position, sizeof(__position_t));

    __bposition->__y = (__bposition->__y - 1);

    __node_t *__bnode = world_find_node(__world, __bposition);

    /*
    * If this node is empty then a non-floating node is floating
    */

    if (__bnode->__used == WORLD_NODE_UNUSED)
    {
        printf("WORLD: Invalid block position of block: [%d : %d : %d]!\n", __oposition->__x, __oposition->__y, __oposition->__z);

        return LOGIC_INVALID;
    }

    /* 
    * Nothing wrong with the node
    * Return LOGIC_VALID
    */

    return LOGIC_VALID;
}