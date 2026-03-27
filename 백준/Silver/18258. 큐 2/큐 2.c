#include <stdio.h>
#include <string.h>
#define MAX_SIZE 2000001
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
    int Test_case;
    scanf("%d", &Test_case);
    for (int i = 0; i< Test_case; i++)
    {
        char str[10];
        scanf("%s", str);
        if (strcmp(str, "push") == 0)
        {
            int val;
            scanf("%d\n", &val);
            enqueue(val);
        }
        else if (strcmp(str, "pop") == 0)
        {
            printf("%d\n", dequeue());
        }
        else if (strcmp(str, "size") == 0)
        {
            printf("%d\n", size());
        }

        else if (strcmp(str, "empty") == 0)
            printf("%d\n", is_empty());

        else if (strcmp(str, "front") == 0)
            printf("%d\n", peek());

        else if (strcmp(str, "back") == 0)
            printf("%d\n", back());
    }

    
}