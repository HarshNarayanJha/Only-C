#include <stdio.h>

void main() {

    FILE* fp;

    FILE* fr;

    char ch;

    fp = fopen("./data.txt", "r");
    fr = fopen("./write_data.txt", "w");
    while (1) {
        ch = fgetc(fp);
        if (ch == EOF) break;

        printf("%c", ch);
        fputc(ch, fr);
    }

    fclose(fp);
    fclose(fr);
}