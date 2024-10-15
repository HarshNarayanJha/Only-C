#include <stdio.h>

typedef struct Time {
  int hours;
  int minutes;
  int seconds;
} Time;

Time addTime(Time t1, Time t2) {
  Time sum;
  sum.seconds = t1.seconds + t2.seconds;
  sum.minutes = t1.minutes + t2.minutes + sum.seconds / 60;
  sum.hours = t1.hours + t2.hours + sum.minutes / 60;
  sum.seconds %= 60;
  sum.minutes %= 60;
  sum.hours %= 24;

  return sum;
}

int main() {
  Time t1;
  Time t2;
  Time t3;

  printf("Enter first time (hh:mm:ss): ");
  scanf("%d:%d:%d", &t1.hours, &t1.minutes, &t1.seconds);

  printf("Enter second time (hh:mm:ss): ");
  scanf("%d:%d:%d", &t2.hours, &t2.minutes, &t2.seconds);

  t3 = addTime(t1, t2);

  printf("\nSum: %dh %dm %ds\n", t3.hours, t3.minutes, t3.seconds);
}
