#include "stack.h"

void push(stack* stack1, char c)
{
    if((*stack1).size >= STACK_MAX_SIZE) exit(STACK_OVERFLOW);

    (*stack1).sign[(*stack1).size] = c;
    (*stack1).sign_status[(*stack1).size] = 0;
    (*stack1).size++;
}
char pop(stack* stack1)
{
    if ((*stack1).size == 0) exit(STACK_UNDERFLOW);
    (*stack1).size--;
    return (*stack1).sign[(*stack1).size];
}

int peek_status(stack stack1, int j)
{
    if (stack1.size == 0) exit(STACK_UNDERFLOW);
    return stack1.sign_status[j];
}
