#include <stdio.h>

#define MAX 5

typedef struct {
  int list[MAX];
  int rear;
  int front;
} queue;

int isEmpty(queue* q) {
  return q->front == -1 && q->rear == -1;
}

int isFull(queue* q) {
  return q->rear == MAX - 1;
}

void enqueue(queue* q, int val) {
  if (isFull(q)) {
    printf("Queue Overflow\n");
    return;
  }

  if (isEmpty(q)) {
    q->rear = q->front = 0;
  } else {
    q->rear++;
  }

  q->list[q->rear] = val;
}

int dequeue(queue* q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return -1;
  }

  int first;

  if (q->front == q->rear) {
    first = q->list[q->front];
    q->rear = q->front = -1;
  } else {
    first = q->list[q->front];
    q->front++;
  }

  return first;
}

void print(queue* q) {

  if (isEmpty(q)) {
    return;
  }

  for (int i = q->front; i < q->rear + 1; i++) {
    printf("%d -> ", q->list[i]);
  }

  printf("\n");
}

int main() {
  queue q;
  q.rear = -1;
  q.front = -1;

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  printf("%d ", dequeue(&q));
  enqueue(&q, 4);
  enqueue(&q, 5);
  enqueue(&q, 6);

  print(&q);

  printf("%d ", dequeue(&q));
  printf("%d ", dequeue(&q));
  printf("%d ", dequeue(&q));
  printf("%d ", dequeue(&q));
  printf("%d ", dequeue(&q));

  print(&q);

  return 0;
}
