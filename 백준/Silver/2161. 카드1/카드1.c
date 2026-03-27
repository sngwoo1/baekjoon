#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1002
typedef int Element;

Element data[MAX_SIZE];
int front, rear;

void init_queue()
{
    front = 0;
    rear = 0;
}

int is_empty(void)
{
    return (front == rear);
}

int is_full(void)
{
    return (front == (rear+1)%MAX_SIZE);
}

void enqueue(Element e)
{
    rear = (rear+1) % MAX_SIZE;
    data[rear] = e;
}

Element dequeue(void)
{
    if (is_empty())
        return -1;
    front = (front+1) % MAX_SIZE;

    return data[front];
}

int size()
{
    return (rear - front + MAX_SIZE) % MAX_SIZE;
}

Element peek(void)
{
    if (is_empty())
        return -1;
    Element value = (front+1) % MAX_SIZE;

    return data[value];
}

Element back(void)
{
    if (is_empty())
        return -1;
    return data[rear];
}

int main(void) 
{
    int N;
    scanf("%d", &N);

    for (int i = 1; i <= N; i++)
        enqueue(i);
    
    while(!is_empty())
    {
        printf("%d ",dequeue() );

        if (!is_empty())
            enqueue(dequeue());
    }
    return 0;
}