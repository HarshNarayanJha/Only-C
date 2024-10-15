#include <stdio.h>

typedef struct Book {
  char title[50];
  char author[50];
  float price;
} Book;

int main() {
  Book books[5];

  for (int i = 0; i < 5; i++) {
    printf("Enter title of book %d: ", i + 1);
    scanf("%s", books[i].title);
    printf("Enter author of book %d: ", i + 1);
    scanf("%s", books[i].author);
    printf("Enter price of book %d: ", i + 1);
    scanf("%f", &books[i].price);
    printf("\n");
  }

  int mostExpensiveIndex = 0;
  int leastExpensiveIndex = 0;

  for (int i = 1; i < 5; i++) {
    if (books[i].price > books[mostExpensiveIndex].price) {
      mostExpensiveIndex = i;
    }
    if (books[i].price < books[leastExpensiveIndex].price) {
      leastExpensiveIndex = i;
    }
  }

  printf("Most expensive book: %s by %s, Price: %.2f\n",
         books[mostExpensiveIndex].title, books[mostExpensiveIndex].author,
         books[mostExpensiveIndex].price);

  printf("\nLeast expensive book: %s by %s, Price: %.2f\n",
         books[leastExpensiveIndex].title, books[leastExpensiveIndex].author,
         books[leastExpensiveIndex].price);
}
