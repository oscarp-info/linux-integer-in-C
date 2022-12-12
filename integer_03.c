/*

    Big-Endian:     es el orden intuitivo. El primer byte guardado representa la cifra
                    más significativa.
    Little-Endian:  es al revés de lo que uno esperaría. El primer byte guardado representa
                    la cifra menos significativa.

    gcc -Wall -S -O0 endian.c

            uint32_t be = __builtin_bswap32(le);
    0x0000000000400535 <+15>:    mov    -0x8(%rbp),%eax
    0x0000000000400538 <+18>:    bswap  %eax
    0x000000000040053a <+20>:    mov    %eax,-0x4(%rbp)

    == solo una instruccion 'bswap', es muy rapido! ===
*/

#include <stdio.h>
#include <inttypes.h>
#include <netinet/in.h> //htonl

int check_for_endianness(void);

int main()
{
    uint32_t le = 0x12345678;
    uint32_t be;

    // little or big endian?
    check_for_endianness() ? printf("platform little endian\n") : printf("platform  big endian\n");

    // alternativa (1)
    be = __builtin_bswap32(le);
    printf("little endian: %#x\n", le);
    printf("big endian:    %#x\n", be);

    // alternativa (2)
    uint32_t network_byte_order;
    network_byte_order = htonl(le);
    printf("big endian:    %#x\n", network_byte_order);

    // alternativa (3)
    uint32_t num = 0x12345678;
    uint32_t res =
        ((num & 0x000000FF) << 24) |
        ((num & 0x0000FF00) << 8) |
        ((num & 0x00FF0000) >> 8) |
        ((num & 0xFF000000) >> 24);
    printf("big endian:    %#x\n", res);

    return 0;
}

/*
    Function check_for_endianness() returns 1, if architecture
    is little endian, 0 in case of big endian.
*/
int check_for_endianness(void)
{
    unsigned int x = 1;
    char *c = (char *)&x;
    return (int)*c;
}
