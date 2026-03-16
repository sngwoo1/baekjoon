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

int precedence(char ch)
{
    switch(ch)
    {
        case '(': case ')':
            return 0;
        case '+': case '-' :
            return 1;
        case '*': case '/':
            return 2;
    }
}


void infix_postfix (char * str)
{
    init_stack();
    int i = 0;

    while(str[i]!= 0)
    {
        char c = str[i++];

        if ( c >= 'A' && c <= 'Z')
            printf("%c", c);
        else if ( c == '(')
        {
            push(c);
        }
        else if ( c == ')')
        {
            while (is_empty() == 0)
            {
                if (peek() == '(')
                {
                    pop();
                    break;
                }
                printf("%c", pop());
            }
        }
        else if ( c == '+' || c=='-' || c=='*' || c=='/' )
        {
            while(is_empty() == 0)
            {
                char op = peek();
                if (precedence(c) <= precedence(op))
                {
                    printf("%c", pop());
                }
                else break;
            }
            push(c);
        }
    }
    while(is_empty() == 0)
        printf("%c", pop());
}

int main(void)
{
    char str[100];
    scanf("%s", str);
    infix_postfix(str);
    return 0;
}