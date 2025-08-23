#include <stdio.h>
void printBinary(unsigned int num)
{
    for (int i = 15; i >= 0; i--) 
    {
        printf("%d", (num >> i) & 1);
        if (i % 4 == 0) printf(" "); 
    }
}
int main() {
    unsigned int num;
    int bit;
    printf("Enter a number (decimal): ");
    scanf("%u", &num);
    printf("Enter the bit position to toggle (0 = LSB): ");
    scanf("%d", &bit);
    printf("\nBefore toggle: ");
    printBinary(num);
    num = num ^ (1 << bit);
    printf("\nAfter toggle : ");
    printBinary(num);
    printf("\n");
    return 0;
}