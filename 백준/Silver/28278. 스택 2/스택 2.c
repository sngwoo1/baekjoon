#include <stdio.h>

int top = -1;
int stack[1000000];

//is_empty
int is_empty(void)
{
    if (top == -1)
        return 1;
    else
        return 0;    
}


void push(int e)
{
    stack[++top] = e;
}

int pop(void)
{
    if (is_empty() == 1)
        return -1;
    else   
        return stack[top--];
}

int peek(void)
{
    if (is_empty()==1)
        return -1;
    else
        return stack[top];
}

int main(void)
{
    int N;
    int value;

    scanf("%d", &N);

    int num;
    for(int i=0; i<N; i++)
    {
        scanf(" %d", &num);
        
        switch (num)
        {
            case 1:
                scanf(" %d", &value);
                push(value);
                break;
            
            case 2:
                printf("%d\n", pop());
                break;
            
            case 3:
                printf("%d\n", top+1);
                break;
            case 4:
                printf("%d\n", is_empty());
                break;
            case 5:
                printf("%d\n", peek());
                break;
        }
    }
    return 0;
    

}