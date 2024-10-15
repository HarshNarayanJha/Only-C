#include <stdio.h>
#include <stdint.h>

typedef uint8_t byte;

int main(int argc, char const *argv[])
{
    FILE *src = fopen(argv[1], "rb");
    FILE *dst = fopen(argv[2], "wb");

    byte b;

    while(fread(&b, sizeof(b), 1, src) != 0) {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(dst);
    fclose(src);


    return 0;
}
