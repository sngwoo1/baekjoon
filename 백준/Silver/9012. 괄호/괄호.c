#include <stdio.h>
#define Element char
int top = -1;
Element data[50];

int is_empty()
{
    if (top == -1)
        return 1;
    else
        return 0;
}

int is_full()
{
    if (top == (50-1))
        return 1;
    else
        return 0;
}

void push(Element e)
{
    //if (is_full())

        data[++top] = e;       
}

Element pop()
{
    if (is_empty())
        return (Element)-1;
    else
        return data[top--];
}




int main(void)
{
    int N;
    scanf("%d", &N);
    char str[51];

    for(int i=0; i<N; i++)
    {
        top = -1;
        char j = 0;
        scanf("%s", str);

        while(str[j] != 0)
        {
            if ( str[j] == '(' )
                push(str[j]);

            else if (str[j] == ')')
            {
                Element op = pop();
                if (op != '(')
                {
                    printf("NO\n");
                    break;
                }
            }
            j++;
        }
        if (str[j] == 0)
        {
            if (top != -1)
                printf("NO\n");
            else
                printf("YES\n");
        }
    }
}