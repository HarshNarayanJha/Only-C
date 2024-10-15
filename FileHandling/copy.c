#include <stdio.h>
#include <string.h>

int main() {
    FILE* src;
    FILE* dest;

    char sname[100];
    char dname[100];

    printf("Enter Source file name: ");
    gets(sname);

    printf("Enter Destination file name: ");
    gets(dname);


    src = fopen(sname, "r");
    if (src == NULL) {
        printf("Err opening file %s\n", sname);
        return -1;
    }

    dest = fopen(dname, "w");
    if (dest == NULL) {
        printf("Err opening file %s\n", dname);
        return -1;
    }

    char c;
    while ((c = fgetc(src)) !=  EOF) {
        fputc(c, dest);
    }

    fclose(src);
    fclose(dest);

    return 0;
}