## File Handling

A data file is used to store data. A data file can be read or written to.

We use data files to store information in them for later retreival on a permanent storage. They can be accessed at a later point for updation.


Modes for opening

- r
- rb
- w
- wb
- a
- ab
- r+
- r+b
- w+
- w+b
- a+
- a+b

### File handeling funcs
- `FILE* f = fopen(filename, mode)` -> opens a file

- `char c = fgetc(file)` -> read from a file (EOF)
- `fgets(s, size, file)` -> read a string from a file
- `fputc(c, file)` -> read from a file (EOF)
- `fputs(str, file)` -> write string to a file

- `fscanf(file, "formatter", &vars)` -> read from a file (EOF)
- `fprintf(file, "formatter", vars)` -> write to a file

- `fseek(file, offset, whence)` -> makes the cursor dance at offset relative to (SEEK_SET - starting, SEEK_END - end, SEEK_CUR - cursor)
- `rewind(file)` -> dances the cursor to back to start
- `int pos = ftell(file)` -> tells where the cursor is dancing

- `fread(buffer, sizeof (buffer), 1, file)` -> reads an object from a file
- `fwrite(&obj, sizeof (struct Num), 1, file)` -> writes an object to a file

- `getw(file)` -> reads an int
- `putw(w, file)` -> writes an int
- `getc(file)` -> reads a char
- `putc(c, file)` -> writes a char

- `feof(file)` -> return non-zero if at EOF else 0
- `fclose()` -> closes a file

## Structs
structure is a data type to store related data in a single variable.

A self referential structure is a strcuture that references itself.
We can declare self-referential structure like this

```c
struct Node {
    int val;
    struct Node* next;
};
```

call by reference

```c
int main() {
    struct Node node;
    node.val = 10;
    node.next = NULL;
    myfunc(&node);
}
void myfunc(struct Node* node) {
    printf("%d", node->val);
}
```


## Pointers

Advantages

- dynamic memory allocation
- efficient memory usage
- ability to pass references to functions
- dynamic data structures

Disadv
- memory leaks
- dangling pointers

Various types of arithematic operations to be performed on pointers are

inc/dec
addition with const
sub with const
sub to pointer

typedef keyword can be use to make an alias for an existing data type in a C program
redefine the name of an already existing data type in C

```c
// typedef existing_type alias_name;
typedef int grade;

typedef struct Student {
    ..
} student;

int main() {
    int a = 5;
    grade g = 1;

    student s = ...;
}
```