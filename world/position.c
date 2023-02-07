#include <world/position.h>

#include <stdlib.h>

__position_t *position_new(int __x, int __y, int __z)
{
    __position_t *__position = calloc(1, sizeof(__position_t));

    __position->__x = __x;
    __position->__y = __y;
    __position->__z = __z;

    return __position;
}

void position_update(__position_t *__position, int __x, int __y, int __z)
{
    if (!__position)
    {
        /*
        * TODO: Add a debugger
        */

       return;
    }

    __position->__x = __x;
    __position->__y = __y;
    __position->__z = __z;
}

void position_update_one(__position_t *__position, __position_type __type, int __n)
{
    if (!__position)
    {
        /*
        * TODO: Add a debugger
        */

       return;
    }

    if (__type == T_POS_X) __position->__x = __n; return;
    if (__type == T_POS_Y) __position->__y = __n; return;
    if (__type == T_POS_Z) __position->__z = __n; return;
}