#include <reg51.h>
#include "fan.h"
#include "light.h"
#include "buzzer.h"
#include "lock.h"

// Input buttons
sbit BTN_FAN = P2^0;
sbit BTN_LIGHT = P2^1;
sbit BTN_BUZZER = P2^2;
sbit BTN_LOCK = P2^3;

void uart_init(void) {
    SCON = 0x50;  // 8-bit UART
    TMOD |= 0x20; // Timer1 in Mode 2
    TH1 = 0xFD;   // 9600 baud
    TR1 = 1;
}

void uart_tx(char c) {
    SBUF = c;
    while (!TI);
    TI = 0;
}

void uart_send_string(char* str) {
    while (*str)
        uart_tx(*str++);
}

void delay() {
    int i, j;
    for(i=0;i<100;i++)
        for(j=0;j<1275;j++);
}

void main() {
    fan_init();
    light_init();
    buzzer_init();
    lock_init();
    uart_init();

    uart_send_string("Smart Home System Ready\r\n");

    while(1) {
        if (BTN_FAN == 0) {
            fan_on();
            uart_send_string("Fan ON\r\n");
            delay();
        } else {
            fan_off();
        }

        if (BTN_LIGHT == 0) {
            light_on();
            uart_send_string("Light ON\r\n");
            delay();
        } else {
            light_off();
        }

        if (BTN_BUZZER == 0) {
            buzzer_on();
            uart_send_string("Buzzer ON\r\n");
            delay();
        } else {
            buzzer_off();
        }

        if (BTN_LOCK == 0) {
            lock_open();
            uart_send_string("Lock OPEN\r\n");
            delay();
        } else {
            lock_close();
        }
    }
}