#include <stdio.h>
#define MAX_SIZE 102

typedef char Element;

Element stack[MAX_SIZE];
int top = -1;

int is_full(void)
{
    if (top == MAX_SIZE-1)
        return 1;
    else
        return 0;
}

int is_empty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;
}

void init (void)
{
    top = -1;
}

void push (Element e)
{
    if (is_full())
        return;
    else
        stack[++top] = e;
}

Element pop ()
{
    if (is_empty())
        return 1;
    else
        return stack[top--];
}

Element peek()
{
    if (is_empty())
        return 1;
    else
        return stack[top];
}

int check_matching(char expr[])
{
    int i = 0, prev;

    init();
    while(expr[i] != 0)
    {
        char ch = expr[i];
        if ( (ch == '[') || (ch == '('))
            push(ch);
        else if ( ( ch == ']') || (ch == ')') )
        {
            if (is_empty())
                return 2;
            
            prev = pop();
            if ( (ch == ']' && prev != '[') || ( ch == ')' && prev != '(') )
                return 3;
        }
        i++;
    }
    if (is_empty())
        return 0;
    else    return 1;
}

int main(void)
{
    char expr[102];

    while(1)
    {
        fgets(expr, sizeof(expr), stdin);

        if (expr[0] == '.' && expr[1] == '\n')
            return 0;
        
        int check_return = check_matching(expr);

        if (check_return == 0)
            printf("yes\n");
        else
            printf("no\n");
    }
}
