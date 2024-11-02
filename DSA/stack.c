#include "stack.h"
#include <stdio.h>

void initStack(Stack *s) { s->top = -1; }

int isEmpty(Stack *s) { return s->top == -1; }

int isFull(Stack *s) { return s->top == MAX_SIZE - 1; }

void push(Stack *s, void* value) {
  if (isFull(s)) {
    printf("Stack overflow!\n");
    return;
  }
  s->items[++(s->top)] = value;
}

void* pop(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack underflow!\n");
    return NULL;
  }
  return s->items[(s->top)--];
}

void* peek(Stack *s) {
  if (isEmpty(s)) {
    printf("Stack is empty!\n");
    return NULL;
  }
  return s->items[s->top];
}
