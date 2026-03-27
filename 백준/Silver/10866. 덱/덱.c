#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10001
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
    char str[50];
    init_deque();
    scanf("%d", &N);

    for (int i = 0; i < N; i++)
    {
        scanf("%s", str);
        int val;
        if (strcmp(str, "push_front") == 0)
        {
            scanf("%d", &val);
            add_front(val);
        }
        else if (strcmp(str, "push_back") == 0)
        {
            scanf("%d", &val);
            add_rear(val);
        }
        else if (strcmp(str, "pop_front") == 0 )
            printf("%d\n", delete_front() );
        else if (strcmp(str, "pop_back") == 0 )
            printf("%d\n", delete_rear() );
        else if (strcmp(str, "size") == 0)
            printf("%d\n", size() );
        else if (strcmp(str, "empty") == 0 )
            printf("%d\n", is_empty() );
        else if (strcmp(str, "front") == 0 )
            printf("%d\n", get_front() );
        else if (strcmp(str, "back") == 0 )
            printf("%d\n",get_rear() );
    }
    return 0;
}

