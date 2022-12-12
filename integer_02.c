#include <stdio.h>
#include <stdint.h>

/*

gdb ./a.out
(gdb) list
(gdb) list
(gdb) break 43 (el que corresponda)
(gdb) run
(gdb) print/x value
(gdb) print/x *((char*)&value+0)
(gdb) print/x *((char*)&value+1)
(gdb) print/x *((char*)&value+2)
(gdb) print/x *((char*)&value+3)
(gdb) quit


3 alternativas para visualziar el archivo binario:
    xxd integer.dump
    hexdump -C integer.dump
    hexedit integer.dump

*/

void dump(int *value);
void memory_dump(int value);

int main()
{

    // multibyte
    int32_t value = 0x12345678;

    // #    add 0x
    // x    hex w/lowwer case letters
    printf("%#x\n", value);

    dump(&value);

    memory_dump(value);

    return 0;
}

void dump(int *value)
{
    FILE *fp;
    fp = fopen("integer.dump", "w");
    fwrite(value, sizeof(int), 1, fp);
    fclose(fp);
}

void memory_dump(int value)
{

    int i = 0;
    int8_t data; // 1 byte

    for (i = 0; i < 4; i++)
    {
        data = *(((int8_t *)&value) + i);
        printf("%02x ", data);
    }
}