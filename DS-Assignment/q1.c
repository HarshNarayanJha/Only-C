#include <stdio.h>

int NUM_SUBJECTS = 5;

typedef struct student {
  char name[20];
  int age;
  int total_marks;
} student;

int main() {
  student s1;
  student s2;

  printf("First Student\n");
  printf("Name: ");
  scanf("%s", s1.name);
  printf("Age: ");
  scanf("%d", &s1.age);
  printf("Total Marks: ");
  scanf("%d", &s1.total_marks);

  printf("\nSecond Student\n");
  printf("Name: ");
  scanf("%s", s2.name);
  printf("Age: ");
  scanf("%d", &s2.age);
  printf("Total Marks: ");
  scanf("%d", &s2.total_marks);

  printf("\n%s: (%d y/o)\n", s1.name, s1.age);
  printf("Total Marks: %d\n", s1.total_marks);
  printf("Average Marks: %.2f\n", (float)s1.total_marks / NUM_SUBJECTS);

  printf("\n%s: (%d y/o)\n", s2.name, s2.age);
  printf("Total Marks: %d\n", s2.total_marks);
  printf("Average Marks: %.2f\n", (float)s2.total_marks / NUM_SUBJECTS);
}
