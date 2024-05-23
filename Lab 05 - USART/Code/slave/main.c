#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_interface.h"
#include "LCD_interface.h"
#include <avr/io.h>
#include <util/delay.h>


// Function Prototypes
void UART_init(unsigned int baud);
unsigned char UART_receive(void);


int main(void) {
    // Initialize UART
    UART_init(9600);

    // Initialize LCD
    LCD_VidInitilization();

    while (1) {
        // Wait for data to be received
        unsigned char received_data = UART_receive();

        LCD_VidClear();
        LCD_VidSendChar(received_data);
        _delay_ms(200);
    }

    return 0;
}

void UART_init(unsigned int baud) {
    unsigned int ubrr = F_CPU/16/baud-1;
    UBRRH = (unsigned char)(ubrr>>8);
    UBRRL = (unsigned char)ubrr;
    UCSRB = (1<<RXEN) | (1<<TXEN);
    UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);  // URSEL must be set to write to UCSRC
}

unsigned char UART_receive(void) {
    while (!(UCSRA & (1<<RXC)));  // Wait for data to be received
    return UDR;                   // Get and return received data from buffer
}


