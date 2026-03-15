#include <stdio.h>

#define MAX_SIZE 102

char stack[MAX_SIZE];
int top;

void init(void)
{
    top = -1;
}

int is_empty(void)
{
    return top == -1;
}

void push(char c)
{
    stack[++top] = c;
}

char pop(void)
{
    return stack[top--];
}

int check_matching(char str[])
{
    int i = 0;
    char ch, prev;

    init();

    while (str[i] != '\0')
    {
        ch = str[i];

        if (ch == '(' || ch == '[')
        {
            push(ch);
        }
        else if (ch == ')' || ch == ']')
        {
            if (is_empty())
                return 0;

            prev = pop();

            if ((ch == ')' && prev != '(') ||
                (ch == ']' && prev != '['))
                return 0;
        }

        i++;
    }

    return is_empty();
}

int main(void)
{
    char str[MAX_SIZE];

    while (fgets(str, sizeof(str), stdin) != NULL)
    {
        if (str[0] == '.' && (str[1] == '\n' || str[1] == '\0'))
            break;

        if (check_matching(str))
            printf("yes\n");
        else
            printf("no\n");
    }

    return 0;
}