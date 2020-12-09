#ifndef STACK_H
#define STACK_H

#include "status.h"
typedef void* STACK;

STACK init_stack_default(void);
Status stack_push(STACK hStack, int item);
Status stack_pop(STACK hStack);
Boolean stack_empty(STACK hStack);
char stack_top(STACK hStack);
void stack_destroy(STACK* phStack);

#endif