#ifndef STACK_H
#define STACK_H

#define MAX_SIZE 100

typedef struct {
  void* items[MAX_SIZE];
  int top;
} Stack;

void initStack(Stack *s);
int isEmpty(Stack *s);
int isFull(Stack *s);
void push(Stack *s, void* value);
void* pop(Stack *s);
void* peek(Stack *s);

#endif
