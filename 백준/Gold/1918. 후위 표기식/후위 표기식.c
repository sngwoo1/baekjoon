#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100
typedef char Element;

Element data[MAX_SIZE];
int top;
void error(char str[])
{
    printf("%s\n", str);
    exit(1);
}

void init_stack()
{
    top = -1;
}
int is_empty()
{
    if (top == -1) return 1;
    else return 0;
}
int is_full()
{
    return (top == (MAX_SIZE - 1));
}
void push(Element e)
{
    if (is_full())
        error("Overflow Error!");
    else data[++top] = e;
}
Element pop()
{
    if (is_empty())
        error("Underflow Error!");
    return data[top--];
}
Element peek()
{
    if (is_empty())
        error("Underflow Error!");
    return data[top];
}

int size()
{
    return top + 1;
}


double eval_postfix(char* expr)
{
    init_stack();
    int i = 0;

    while(expr[i] != 0)
    {
        char c = expr[i];
        if ( c >= '0' && c <= '9')
            push(((double)c-'0'));
        
        else if ( ( c == '+') || (c == '-') || (c == '*') || (c == '/'))
        {
            double right = pop();
            double left = pop();

            switch(c)
            {
                case '+':
                push( left + right);
                break;

                case '-':
                push( left - right);
                break;

                case '*':
                push( left * right);
                break;

                case '/':
                push( left / right);
                break;

            }
        }
        i ++;
    }
    return pop();
}

int precedence(char op)
{
    switch (op)
    {
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
}

void infix_to_postfix(char * expr)
{
    init_stack();

    int i = 0;
    while (expr[i] != 0)
    {
        char c = expr[i++];

        if ( ( c>= 'A') && ( c <= 'Z') )
            printf("%c", c);
        
        else if (c == '(')
            push(c);
        else if (c == ')')
        {
            while (is_empty() == 0)
            {
                char op = pop();
                if (op == '(')
                    break;
                else
                    printf("%c", op);
            }
        }

        else if ( (c == '+') || (c == '-') || (c == '*') || (c == '/') )
        {
            while(is_empty() == 0)
            {
                char op = peek();
                if (precedence(c) <= precedence(op))
                {
                    printf("%c", op);
                    pop();
                }
                else break;
            }
            push(c);
        }
    }
    while (is_empty() == 0)
        printf("%c", pop());
    printf("\n");
}

int main(void)
{
    char str[100];
    scanf("%s", str);
    infix_to_postfix(str);

    return 0;
}
