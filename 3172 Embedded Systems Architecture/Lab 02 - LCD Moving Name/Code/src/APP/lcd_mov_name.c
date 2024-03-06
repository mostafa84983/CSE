#include "lcd_mov_name.h"

#include "../../lib/MCAL/DIO/DIO_interface.h"
#include "../../lib/HAL/LCD/LCD_interface.h"

#include <util/delay.h>

void lcd_mov_name(void)
{
    LCD_VidInit("HELLO AVR!");

    char str[] = "TEAM GABAL";
    u8 Local_u8MaxIndex = 16 - sizeof(str) + 2;
    u8 Local_u8Index = 1;
    typedef enum u8 {backward, forward} direction;
    direction cursor = forward;

    while(1)
    {
        LCD_VidCmd(LCD_CLEAR);

        if(Local_u8Index == Local_u8MaxIndex)
            cursor = backward;
        else if(Local_u8Index == 1)
            cursor = forward; 
        // 
        LCD_VidMoveCursor(1, Local_u8Index);
        LCD_VidPrintString(str);
        
        cursor ? Local_u8Index++ : Local_u8Index--;

        _delay_ms(500);
    }
}