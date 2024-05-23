#include <avr/io.h>
#include <avr/interrupt.h>

volatile char x = 0x41;

void UART_init(unsigned int baud) {
    unsigned int ubrr = F_CPU/16/baud-1;
    UBRRH = (unsigned char)(ubrr>>8);
    UBRRL = (unsigned char)ubrr;
    UCSRB = (1<<RXEN) | (1<<TXEN);
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);  // URSEL must be set to write to UCSRC
}

void UART_transmit(unsigned char data) {
    while (!(UCSRA & (1<<UDRE)));
    UDR = data;
}

ISR(INT0_vect) {
     if (x > 0x7a) {
        x = 0x41;
    }
    UART_transmit(x);
    x++;
}

void INT0_init() {
    MCUCR |= (1<<ISC01);    // Falling edge of INT0 generates an interrupt request
    GICR |= (1<<INT0);      // Enable INT0
}

int main(void) {
    UART_init(9600);
    INT0_init();
    sei();                  // Enable global interrupts

    while (1) {
        // Main loop does nothing, ISR handles everything
    }

    return 0;
}
