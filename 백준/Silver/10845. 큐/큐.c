#include <stdio.h>
#include <string.h>
#define MAX_SIZE 10000

int data[MAX_SIZE];
int front = 0;
int rear = 0;

//empty
int is_empty()
{
    if ( (front == rear))
        return 1;
    else return 0;
}
//push
void enqueue(int e)
{
    data[++rear] = e;
}
//pop
void dequeue()
{
    if (is_empty())
        printf("-1\n");
    else    
        printf("%d\n",data[++front]);
}
//size
int size()
{
    printf("%d\n", (rear - front));
}

//front
void peek()
{
    if (is_empty())
        printf("-1\n");
    else
        printf("%d\n", data[front+1]);
}
//back
void back()
{
    if (is_empty())
        printf("-1\n");
    else
        printf("%d\n", data[rear]);
}

int main(void)
{
    int n;
    scanf("%d", &n);

    for(int i = 0; i < n; i++)
    {
        char str[10];
        scanf("%s", str);
        if (strcmp(str, "push") == 0)
        {
            int e;
            scanf("%d", &e);
            enqueue(e);
        }
        else if (strcmp(str, "pop") == 0)
            dequeue();
        else if (strcmp(str, "size") == 0)
            size();
        else if (strcmp(str, "empty") == 0)
            printf("%d\n", is_empty());
        else if (strcmp(str, "front") == 0)
            peek();
        else if (strcmp(str, "back") == 0)
            back();
    }
    return 0;
}