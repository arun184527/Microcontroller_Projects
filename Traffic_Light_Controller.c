
#include <reg51.h>
sbit A_R = P1^0;
sbit A_Y = P1^1;
sbit A_G = P1^2;
sbit B_R = P1^3;
sbit B_Y = P1^4;
sbit B_G = P1^5;

void delay(unsigned int time) {
    unsigned int i, j;
    for(i = 0; i < time; i++)
        for(j = 0; j < 1275; j++);
}

void set_lights(unsigned char road) {
    A_R = A_Y = A_G = 0;
    B_R = B_Y = B_G = 0;

    switch(road) {
        case 0: // Road A Green
            A_G = 1; B_R = 1;
            delay(300);
            A_G = 0; A_Y = 1;
            delay(100);
            break;

        case 1: // Road B Green
            B_G = 1; A_R = 1;
            delay(300);
            B_G = 0; B_Y = 1;
            delay(100);
            break;
    }
}

void main() {
    while(1) {
        set_lights(0); // A Green
        set_lights(1); // B Green
    }
}