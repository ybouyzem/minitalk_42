#include <stdio.h>

int main() {
    // Binary representation: 01000001
    unsigned char binary = 0b01000001; // 0b prefix indicates binary literal in C
    char character = (char)binary;

    printf("Binary: %u\n", binary);
    printf("Char: %c\n", character);

    return 0;
}
