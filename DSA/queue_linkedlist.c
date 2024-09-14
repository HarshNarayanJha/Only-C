#include <stdio.h>
#include <stdlib.h>

struct Node {
  int val;
  struct Node *next;
};

typedef struct Node Node;

Node *front;
Node *rear;

int isEmpty() { return front == NULL && rear == NULL; }

void enqueue(int val) {

  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->val = val;
  newNode->next = NULL;

  if (isEmpty()) {
    rear = front = newNode;
    return;
  }

  rear->next = newNode;
  rear = rear->next;
}

int dequeue() {
  if (isEmpty()) {
    printf("Queue Underflow\n");
    return -1;
  }

  Node *temp = front;
  int val = temp->val;

  if (front == rear) {
    front = rear = NULL;
  } else {
    front = front->next;
  }
  free(temp);
  return val;
}

void print() {

  if (isEmpty()) {
    return;
  }

  Node *curr = front;
  while (curr != NULL) {
    printf("%d -> ", curr->val);
    curr = curr->next;
  }
  printf("\n");
}

int main() {
  enqueue(1);
  enqueue(2);
  enqueue(3);
  printf("%d ", dequeue());
  enqueue(4);
  enqueue(5);
  enqueue(6);

  print();

  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());
  printf("%d ", dequeue());

  print();

  return 0;
}
