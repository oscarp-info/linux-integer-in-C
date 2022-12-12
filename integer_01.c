#include <stdio.h>
#include <stdint.h>

int main()
{

    // basicos (signed), se pueden conbinar con unsigned
    // puede variar en funcion a la plataforma
    // en mi caso es linux x86_64
    char a;      // 1 byte
    short int b; // 2 bytes
    int c;       // 4 bytes
    long int d;  // 8 bytes

    printf("(%ld,%ld,%ld,%ld)\n", sizeof(a), sizeof(b), sizeof(c), sizeof(d));

    // stdint.h - signed integer types, se pueden conbinar con unsigned
    // independientes de la plataforma
    int8_t e;  // 1 byte
    int16_t f; // 2 bytes
    int32_t g; // 4 bytes
    int64_t h; // 8 bytes

    printf("(%ld,%ld,%ld,%ld)\n", sizeof(e), sizeof(f), sizeof(g), sizeof(h));

    // numeros negativos
    int8_t value = -15;

    printf("value = %d\n", value); // => -15
    printf("value = %u\n", value); // => 4294967281

    // que paso? te asustaste?
    // pero como se almacena en la memoria?
    // gdb....
    // en la memoria se almacenan en complemento a 2
    /*
    -15
    15
    0000 1111   binario
    1111 0000   ca1
    1111 0001   ca2
    F1          hex

    */

    // verificamos de otra manera que los numeros neg se almacenan en ca2
    int8_t x = 0xF1;
    printf("value = %d\n", x);

    return 0;
}