#include <stdio.h>

int top = -1;
unsigned int data[1000000];

// push
void push(int e)
{
    data[++top] = e;
}

void pop(void)
{
    top--;
}


int main(void)
{
    int K;

    scanf("%d", &K);

    for(int i=0; i<K; i++)
    {
        int value;
        scanf("%d", &value);

        if (value == 0)
            pop();
        else
            push(value);
    }

    unsigned int sum=0;
    for(int i=0; i<=top; i++)
    {
        sum += data[i];
    }
    printf("%u", sum);
    return 0;
}