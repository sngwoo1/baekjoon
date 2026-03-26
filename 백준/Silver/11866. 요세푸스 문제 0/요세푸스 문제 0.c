#include <stdio.h>
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
    int N, K;

    scanf("%d %d", &N, &K);

    init_queue();

    // 1부터 N까지 큐에 삽입
    for (int i = 1; i <= N; i++) 
        enqueue(i);

    printf("<");

    for (int i = 0; i < N; i++) 
    {
        for (int j = 0; j < K - 1; j++) 
        {
            enqueue(dequeue());
        }

        printf("%d", dequeue());

        if (i < N - 1) 
        {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}