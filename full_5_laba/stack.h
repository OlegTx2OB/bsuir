#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STACK_MAX_SIZE 20

#define STACK_OVERFLOW 1488
#define STACK_UNDERFLOW 1337

#pragma once

typedef struct
{
    char sign[20];
    int sign_status[20];
    int size;
} stack;

void push(stack* stack1, char c);
char pop(stack* stack1);
int peek_status(stack stack1, int j);
