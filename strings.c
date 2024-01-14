#include <stdio.h>
#include <string.h>

int main() {
    char* name = "Harsh Narayan Jha";
    int age = 67;

    char message[20] = "Hello World!";

    printf("My name is %s, age is %d and I say %s.\n", name, age, message);
    printf("Name length is: %d\n", strlen(name));

    if (strncmp(name, "Harsh", 5) == 0) {
        printf("You are one of the Original Harsh's\n");
    } else {
        printf("Go Away right now\n");
    }

    strncat(message, name, 5);

    printf("%s", message);

    return 0;
}