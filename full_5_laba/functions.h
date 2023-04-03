#include "stack.h"

int var(char c);
int number(char c);
int sign(char c);
void check_first_element(char c);
void check_2_last_elements(char* expression);
void check_ratio_of_signs_and_vars_numbers(int signs_count, int vars_numbers_count);

void transformation(stack* stack1, char* expression, char* new_expression);
void input(char* expression);
void output(char* new_expression);
