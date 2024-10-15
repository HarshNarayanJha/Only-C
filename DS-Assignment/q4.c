#include <stdio.h>

#define MAX_SIZE 10

typedef struct Stack {
  int arr[MAX_SIZE];
  int length;
} Stack;

void initStack(Stack *stack) { stack->length = 0; }

int isEmpty(Stack *stack) { return stack->length == 0; }

int isFull(Stack *stack) { return stack->length == MAX_SIZE; }

void push(Stack *stack, int data) {
  if (isFull(stack)) {
    printf("Stack Overflow\n");
    return;
  }
  stack->arr[stack->length] = data;
  stack->length++;
}

int pop(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack Underflow\n");
    return -1;
  }
  stack->length--;
  return stack->arr[stack->length];
}

void traverse(Stack *stack) {
  if (isEmpty(stack)) {
    printf("Stack is empty\n");
    return;
  }
  for (int i = 0; i < stack->length; i++) {
    printf("%d ", stack->arr[i]);
  }
  printf("\n");
}

int main() {
  Stack stack;
  initStack(&stack);

  push(&stack, 10);
  push(&stack, 20);
  push(&stack, 30);

  printf("Stack after pushing elements: ");
  traverse(&stack);

  printf("Popped element: %d\n", pop(&stack));

  printf("Stack after popping an element: ");
  traverse(&stack);

  return 0;
}
