#include <stdio.h>
#include <string.h>
#define MAX_SIZE 1000001
typedef int Element;

int data[MAX_SIZE];
int front, rear;

int is_empty()
{
    return (front == rear);
}

int is_full()
{
    return (front == (rear+1) % MAX_SIZE);
}

void init_deque()
{
    front = 0;
    rear = 0;
}

void add_rear(Element e)
{
    if (is_full())
        printf("overflow\n");
    
    rear = (rear+1) % MAX_SIZE;
    data[rear] = e;
}
void add_front(Element e)
{
    if (is_full())
        printf("overflow\n");
    data[front] = e;
    front = (front - 1 + MAX_SIZE) % MAX_SIZE;
}

Element delete_front()
{
    if (is_empty())
        return -1;
    
    front = (front+1) % MAX_SIZE;
    return data[front];
}

Element delete_rear()
{
    if (is_empty())
        return -1;
    
    Element val = rear;
    rear = (rear - 1 + MAX_SIZE) % MAX_SIZE;
    return data[val];
}

Element get_front()
{
    if (is_empty())
        return -1;
    
    return data[(front+1) % MAX_SIZE];
}

Element get_rear()
{
    if (is_empty())
        return -1;
    
    return data[rear];
}

int size()
{
    return (rear - front + MAX_SIZE) % MAX_SIZE;
}

int main(void)
{
    int N;
    int command;
    init_deque();
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%d", &command);
        int val;

        switch (command)
        {
            case 1: scanf("%d", &val); add_front(val); break;
            case 2: scanf("%d", &val); add_rear(val); break;
            case 3: printf("%d\n", delete_front() ); break;
            case 4: printf("%d\n", delete_rear() ); break;
            case 5: printf("%d\n", size()); break;
            case 6: printf("%d\n", is_empty()); break;
            case 7: printf("%d\n", get_front() ); break;
            case 8: printf("%d\n",get_rear() ); break;
        }
    }
    return 0;
}

