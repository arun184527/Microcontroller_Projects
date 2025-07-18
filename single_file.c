#include <reg51.h>

// ----- DEVICE PINS -----
sbit FAN    = P1^0;
sbit LIGHT  = P1^1;
sbit BUZZER = P1^2;
sbit LOCK   = P1^3;

// ----- BUTTON PINS -----
sbit BTN_FAN    = P2^0;
sbit BTN_LIGHT  = P2^1;
sbit BTN_BUZZER = P2^2;
sbit BTN_LOCK   = P2^3;

// ----- UART FUNCTIONS -----
void uart_init(void) {
    TMOD |= 0x20;  // Timer1, Mode 2 (8-bit auto-reload)
    TH1 = 0xFD;    // Baud rate 9600
    SCON = 0x50;   // Mode 1, 8-bit UART
    TR1 = 1;       // Start Timer1
}

void uart_tx(char ch) {
    SBUF = ch;
    while (!TI);
    TI = 0;
}

void uart_send_string(char *str) {
    while (*str) {
        uart_tx(*str++);
    }
}

// ----- DELAY FUNCTION -----
void delay() {
    int i, j;
    for(i = 0; i < 100; i++)
        for(j = 0; j < 1275; j++);
}

// ----- DEVICE CONTROL FUNCTIONS -----
void fan_on()    { FAN = 1; }
void fan_off()   { FAN = 0; }
void light_on()  { LIGHT = 1; }
void light_off() { LIGHT = 0; }
void buzzer_on() { BUZZER = 1; }
void buzzer_off(){ BUZZER = 0; }
void lock_open() { LOCK = 1; }
void lock_close(){ LOCK = 0; }

// ----- DEVICE INIT -----
void init_devices() {
    FAN = LIGHT = BUZZER = LOCK = 0;
}

// ----- MAIN FUNCTION -----
void main() {
    uart_init();
    init_devices();
    uart_send_string("Smart Home Controller Ready\r\n");

    while(1) {
        // FAN CONTROL
        if (BTN_FAN == 0) {
            fan_on();
            uart_send_string("Fan ON\r\n");
            delay();
        } else {
            fan_off();
        }

        // LIGHT CONTROL
        if (BTN_LIGHT == 0) {
            light_on();
            uart_send_string("Light ON\r\n");
            delay();
        } else {
            light_off();
        }

        // BUZZER CONTROL
        if (BTN_BUZZER == 0) {
            buzzer_on();
            uart_send_string("Buzzer ON\r\n");
            delay();
        } else {
            buzzer_off();
        }

        // LOCK CONTROL
        if (BTN_LOCK == 0) {
            lock_open();
            uart_send_string("Lock OPEN\r\n");
            delay();
        } else {
            lock_close();
        }
    }
}