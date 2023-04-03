#include "stack.h"
#include "functions.h"
//+*-*2a*3dc*2b
#define MAX_STR_LEN 60

int main()
{
    stack stack1;
    stack1.size = 0;

    char* expression = malloc(MAX_STR_LEN);
    char* new_expression = malloc(MAX_STR_LEN);

    input(expression);
    transformation(&stack1, expression, new_expression);
    output(new_expression);
    return 0;
}