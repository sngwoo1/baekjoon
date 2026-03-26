#include <stdio.h>

#define MAX_SIZE 1002
typedef int Element;

struct Queue {
    Element data[MAX_SIZE];
    int front;
    int rear;
};
typedef struct Queue Queue;

void init_queue(Queue *q) {
    q->front = 0;
    q->rear = 0;
}

int is_empty(Queue *q) {
    return (q->front == q->rear);
}

int is_full(Queue *q) {
    return (q->front == (q->rear + 1) % MAX_SIZE);
}

void enqueue(Queue *q, Element e) {
    if (is_full(q)) return;
    q->rear = (q->rear + 1) % MAX_SIZE;
    q->data[q->rear] = e;
}

Element dequeue(Queue *q) {
    if (is_empty(q)) return -1;
    q->front = (q->front + 1) % MAX_SIZE;
    return q->data[q->front];
}

int main(void) {
    Queue que;
    int N, K;

    if (scanf("%d %d", &N, &K) != 2) return 0;

    init_queue(&que);

    // 1부터 N까지 큐에 삽입
    for (int i = 1; i <= N; i++) {
        enqueue(&que, i);
    }

    printf("<");

    for (int i = 0; i < N; i++) {
        // 1. K-1번 동안 앞에 있는 사람을 꺼내서 다시 뒤로 보냄 (회전)
        for (int j = 0; j < K - 1; j++) {
            enqueue(&que, dequeue(&que));
        }

        // 2. K번째 사람을 꺼내서 출력
        printf("%d", dequeue(&que));

        // 3. 마지막 요소가 아니면 쉼표 출력
        if (i < N - 1) {
            printf(", ");
        }
    }

    printf(">\n");

    return 0;
}