#include <math.h>
#include <stdio.h>

#define MAX 20

int arr[MAX];
int length = 0;

void push(int val) {
  arr[length++] = val;
}

int pop() {
  int last = arr[length - 1];
  length--;
  return last;
}

void print() {
  for (int i = 0; i < length; i++) {
    printf("%d ", arr[i]);
  }

  printf("\n");
}

int main() {
  char str[20];
  printf("Enter a expression: ");
  scanf("%s", str);

  int x, y;

  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] >= '0' && str[i] <= '9') {
      push(str[i] - '0');
    } else {
      switch (str[i]) {
        case '+':
          x = pop();
          y = pop();
          push(y + x);
          break;
        case '-':
          x = pop();
          y = pop();
          push(y - x);
          break;
        case '*':
          x = pop();
          y = pop();
          push(y * x);
          break;
        case '/':
          x = pop();
          y = pop();
          if (y != 0) {
            push(y / x);
          } else {
            printf("Division By 0\n");
            return 1;
          }
          break;
        case '%':
          x = pop();
          y = pop();
          if (y != 0) {
            push(y / x);
          } else {
            printf("Division By 0\n");
            return 1;
          }
          break;
        case '^':
          x = pop();
          y = pop();
          push((int)pow(y, x));
          break;
        default:
          printf("Invalid character: %c\n", str[i]);
          return 1;
      }
    }
  }

  printf(" = %d\n", pop());
}
