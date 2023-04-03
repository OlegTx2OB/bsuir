#include "functions.h"

#define MAX_STR_LEN 60

int var(char c)
{
    if((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z')) return 1;
    return 0;
}
int number(char c)
{
    if(c >= '0' && c <= '9') return 1;
    return 0;
}
int sign(char c)
{
    if (c == '*' || c == '/' || c == '+' || c == '-') return 1;
    return 0;
}
void check_first_element(char c)
{
    if(!sign(c))
    {
        printf(" ! First entered element isn't a sign\n");
        exit(-1);
    }
}
void check_2_last_elements(char* expression)
{
    if( !var(expression[strlen(expression) - 2]) && !number(expression[strlen(expression) - 2]) ||
    !var(expression[strlen(expression) - 3]) && !number(expression[strlen(expression) - 3]))
    {
        printf(" ! Last two entered elements aren't vars/signs\n");
        exit(-1);
    }
}
void check_ratio_of_signs_and_vars_numbers(int signs_count, int vars_numbers_count)
{
    if(signs_count != vars_numbers_count - 1)
    {
        printf(" ! Ratio of signs and vars/numbers isn't correct");
        exit(-1);
    }
}
void transformation(stack* stack1, char* expression, char* new_expression)
{
    check_first_element( expression[0]);
    check_2_last_elements(expression);

    int new_expression_pos = 0;

    int signs_count = 0;
    int vars_numbers_count = 0;

    for (int i = 0; expression[i] != '\n' && expression[i] != '\0'; i++)
    {
        if (sign(expression[i]))
        {
            push(stack1, expression[i]);
            signs_count++;
        }
        else if (var(expression[i]) || number(expression[i]))
        {
            new_expression[new_expression_pos] = expression[i];
            new_expression_pos++;
            vars_numbers_count++;

            (*stack1).sign_status[(*stack1).size - 1]++;
            for (int j = (*stack1).size - 1; j >= 0; j--)
            {
                if(peek_status(*stack1, j) == 2)
                {
                    new_expression[new_expression_pos] = pop(stack1);
                    new_expression_pos++;
                    if((*stack1).size != 0) (*stack1).sign_status[(*stack1).size - 1]++;
                }
            }
        }
        else
        {
            printf(" ! Some element isn't sign/var/number\n");
            exit(-1);
        }
    }
    new_expression[new_expression_pos] = '\n';
    new_expression_pos++;
    new_expression[new_expression_pos] = '\0';
    //new_expression_pos++;

    check_ratio_of_signs_and_vars_numbers(signs_count, vars_numbers_count);
}
void input(char* expression)
{
    printf("\n * Enter your expression:\n");
    fgets(expression, MAX_STR_LEN, stdin);
}
void output(char* new_expression)
{
    printf("\n * Your new expression:\n");
    fputs(new_expression, stdout);
}