#include <stdio.h>

#define MAX 10

int arr[MAX];
int front;
int rear;

void initdeque() {
  front = -1;
  rear = -1;
}

int empty() { return front == -1 && rear == -1; }

void insertFront(int val) {
  if (front == 0 && rear == MAX - 1) {
    printf("Deque is full");
    return;
  }

  if (front == -1) {
    front = rear = 0;
  } else {
    front = (front - 1 + MAX) % MAX;
  }

  arr[front] = val;
}

void insertRear(int val) {
  if (rear + 1 == MAX && front == 0) {
    printf("Deque is full");
    return;
  }

  if (rear == -1) {
    front = rear = 0;
  } else {
    rear = (rear + 1) % MAX;
  }

  arr[rear] = val;
}

int deleteFront() {
  if (front == -1) {
    printf("Deque is empty!");
    return -1;
  }

  int val = arr[front];

  if (front == rear) {
    front = rear = -1;
  } else {
    front = (front + 1) % MAX;
  }

  return val;
}

int deleteRear() {
  if (rear == -1) {
    printf("Deque is empty!");
    return -1;
  }

  int val = arr[rear];

  if (front == rear) {
    front = rear = -1;
  } else {
    rear = (rear - 1 + MAX) % MAX;
  }

  return val;
}

void printdeque() {
  if (empty()) {
    printf("Deque is empty\n");
    return;
  }

  int i = front;
  do {
    printf("%d ", arr[i]);
    i = (i + 1) % MAX;
  } while (i != rear);

  printf("%d\n", arr[i]);
}

int main() {
  initdeque();

  insertFront(1);
  insertRear(2);
  insertRear(3);
  insertRear(4);
  insertRear(5);
  insertFront(0);

  printdeque();

  deleteFront();
  deleteFront();
  deleteRear();

  printdeque();
}
