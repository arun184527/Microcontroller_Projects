#include <stdio.h>
void printBinary(int n) 
{
    for (int i = 7; i >= 0; i--)
    {
        printf("%d", (n >> i) & 1);
    }
}
int main()
{
    int num, pos;
    printf("Enter a number (hex): ");
    scanf("%x", &num);   
    printf("Enter bit position to set (0-7): ");
    scanf("%d", &pos);
    printf("\nOriginal number in binary : ");
    printBinary(num);
    num = num | (1 << pos);
    printf("\nAfter setting bit %d binary : ", pos);
    printBinary(num);
    printf("\n");
    return 0;
}