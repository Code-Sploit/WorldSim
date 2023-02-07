#ifndef POSITION_H
#define POSITION_H

typedef enum {
    T_POS_X,
    T_POS_Y,
    T_POS_Z
} __position_type;

typedef struct __position
{
    int __x;
    int __y;
    int __z;
} __position_t;

__position_t *position_new(int __x, int __y, int __z);

void position_update(__position_t *__position, int __x, int __y, int __z);
void position_update_one(__position_t *__position, __position_type __type, int __n);

#endif