#include "APP/lcd_mov_name.h"
#include "../lib/MCAL/ADC/ADC_interface.h"
#include "../lib/MCAL/EX_INT/EX_INT_interface.h"
#include "../lib/MCAL/GIE/GIE_interface.h"
#include "../lib/HAL/LCD/LCD_interface.h"
#include <util/delay.h>

int main(){
    ADC_VidInit(ADC_REF_AVCC,ADC_CLOCK_DIV_128);
    GIE_VidEnable();
    EXTINT_VidInit(INT0,FALLING_EDGE);
    lcd_mov_name("HELLO");
}

ISR(INT0_VECT){
    u8 Local_u8Reading = ADC_u8ReadChannel(ADC_CHANNEL_0);
    LCD_VidCmd(LCD_CLEAR);
    LCD_VidPrintNumber(Local_u8Reading);
    _delay_ms(2000);
}
