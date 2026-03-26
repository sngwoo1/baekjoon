#include <stdio.h>
#define MAX_SIZE 500001
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
    if (is_full())
        printf("overflow\n");
    rear = (rear+1) % MAX_SIZE;
    data[rear] = e;
}

Element dequeue(void)
{
    if (is_empty())
        printf("underflow\n");
    front = (front+1) % MAX_SIZE;

    return data[front];
}

Element peek(void)
{
    if (is_empty())
        printf("underflow\n");
    Element value = (front+1) % MAX_SIZE;

    return data[value];
}



int main(void)
{
    init_queue();
    int N;

    scanf("%d", &N);

    for(int i = 1; i <= N; i++)
        enqueue(i);
    
    int value = 1;
    while(!is_empty())
    {
        value = dequeue();

        if (!is_empty())
        {
            enqueue(dequeue());
        }
    }
    printf("%d\n", value);

    return 0;


}