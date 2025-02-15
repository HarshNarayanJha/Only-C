#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "stack.h"

bool isOp(char c);
int prec(char op);
char* infixToPostfix(char* infix);
char* infixToPrefix(char* infix);

int main() {
  char infix[100];
  printf("Infix> ");
  scanf("%s", infix);

  char* postfix = infixToPostfix(infix);
  char* prefix = infixToPrefix(infix);

  printf("\nThe Postfix is: %s\n", postfix);
  printf("\nThe Prefix is: %s\n", prefix);
}

bool isOp(char c) {
  switch (c) {
    case '+':
    case '-':
    case '*':
    case '/':
    case '%':
    case '^':
    case ')':
    case '(':
      return true;
    default:
      return false;
  }
}

int prec(char op) {
  if (op == '^') {
    return 3;
  } else if (op == '*' || op == '/') {
    return 2;
  } else if (op == '+' || op == '-') {
    return 1;
  } else {
    return -1;
  }
}

char* infixToPostfix(char* infix) {
  char* postfix = malloc(100 * sizeof(char));
  int pi = 0;

  Stack s;
  initStack(&s);

  for (int i = 0; i < strlen(infix); i++) {
    char c = infix[i];

    if (isOp(c)) {
      if (c == '(') {
        push(&s, (void*)(long)c);

      } else if (c == ')') {
        while ((char)(long)peek(&s) != '(' && !isEmpty(&s)) {
          postfix[pi++] = (char)(long)pop(&s);
        }
        pop(&s);

      } else {
        while (!isEmpty(&s) && prec(c) <= prec((char)(long)peek(&s))) {
          postfix[pi++] = (char)(long)pop(&s);
        }
        push(&s, (void*)(long)c);
      }
    } else {
      postfix[pi++] = c;
    }
  }

  while (!isEmpty(&s)) {
    postfix[pi++] = (char)(long)pop(&s);
  }

  postfix[pi++] = '\0';

  return postfix;
}

char* infixToPrefix(char* infix) {
  char* infixReversed = malloc(100 * sizeof(char));
  int n = strlen(infix);

  // Reverse and swap parentheses
  for (int i = 0; i < n; i++) {
    if (infix[n - 1 - i] == ')')
      infixReversed[i] = '(';
    else if (infix[n - 1 - i] == '(')
      infixReversed[i] = ')';
    else
      infixReversed[i] = infix[n - 1 - i];
  }
  infixReversed[n] = '\0';

  printf("\n\n%s\n\n", infixReversed);

  // Convert reversed infix to postfix
  char* reversedPostfix = infixToPostfix(infixReversed);
  free(infixReversed);

  printf("\n\n%s\n\n", reversedPostfix);

  // Reverse the postfix to get prefix
  char* prefix = malloc(100 * sizeof(char));
  n = strlen(reversedPostfix);

  for (int i = 0; i < n; i++) {
    prefix[i] = reversedPostfix[n - 1 - i];
  }
  prefix[n] = '\0';
  printf("\n\n%s\n\n", prefix);

  free(reversedPostfix);
  return prefix;
}
