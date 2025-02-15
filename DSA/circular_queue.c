#include <stdio.h>

#define MAX 5

typedef struct {
  int arr[MAX];
  int front;
  int rear;
} queue;

int isFull(queue* q) {
  return (q->rear + 1) % MAX == q->front;
}

int isEmpty(queue* q) {
  return q->rear == -1 && q->front == -1;
}

void enqueue(queue* q, int val) {
  if (isFull(q)) {
    printf("Queue Overflow\n");
    return;
  }

  if (isEmpty(q)) {
    q->front++;
  }

  q->rear = (q->rear + 1) % MAX;
  q->arr[q->rear] = val;
}

int dequeue(queue* q) {
  if (isEmpty(q)) {
    printf("Queue Underflow\n");
    return -1;
  }

  int front = q->arr[q->front];
  if (q->front == q->rear) {
    q->front = q->rear = -1;
  } else {
    q->front = (q->front + 1) % MAX;
  }

  return front;
}

void print(queue* q) {
  if (isEmpty(q)) {
    return;
  }

  int i = q->front;
  while (i != q->rear) {
    printf("%d ", q->arr[i]);
    i = (i + 1) % MAX;
  }

  printf("%d ", q->arr[i]);

  printf("\n");
}

int main() {
  queue q;
  q.front = -1;
  q.rear = -1;

  enqueue(&q, 1);
  enqueue(&q, 2);
  enqueue(&q, 3);
  printf("Dequeued: %d\n", dequeue(&q));
  enqueue(&q, 4);
  enqueue(&q, 5);
  enqueue(&q, 6);

  print(&q);

  printf("Dequeued: %d\n", dequeue(&q));
  printf("Dequeued: %d\n", dequeue(&q));
  printf("Dequeued: %d\n", dequeue(&q));
  printf("Dequeued: %d\n", dequeue(&q));
  printf("Dequeued: %d\n", dequeue(&q));
  printf("Dequeued: %d\n", dequeue(&q));

  print(&q);

  return 0;
}
