#include "LCD_interface.h"

#include "../../include/bitmanip.h"
#include "../../MCAL/DIO/DIO_interface.h"

#include <util/delay.h>
#include <stdio.h>


static void LCD_VidSendNibble(u8 data)
{
	u8 Local_u8LowNibble = data & 0x0F;
	u8 Local_u8HighNibble = (data & 0xF0) >> 4;
	DIO_VidSetLowNibbleValue(LCD_PORT, Local_u8HighNibble, LCD_D4);// send high nibble
	LCD_VidSendPulse();
	DIO_VidSetLowNibbleValue(LCD_PORT, Local_u8LowNibble, LCD_D4);// send low nibble
	LCD_VidSendPulse();
}

// generate high pulse for 1 ms to enable lcd
void LCD_VidSendPulse(void)
{
	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinHigh);
	_delay_ms(1);
	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinLow);
	_delay_ms(1);
}

void LCD_VidInit(const char *str)
{
	_delay_ms(50);
	// Set LCD pins as output
	for(et_Pin LCDPin = LCD_RS; LCDPin <= LCD_D7; LCDPin++){
		DIO_VidSetPinDirection(LCD_PORT, LCDPin, Output);
	}
	DIO_VidSetPinValue(LCD_PORT, LCD_E, PinLow);
	LCD_VidCmd(LCD_HOME);
	LCD_VidCmd(LCD_2LINE_4BIT); // set as 4bit
	LCD_VidCmd(LCD_CURSOR_OFF);
	LCD_VidCmd(LCD_CLEAR);
	LCD_VidCmd(LCD_INCREMENT_CURSOR);

	while (*str){
		LCD_VidPrintChar(*str++);
		_delay_ms(100);
	}

	LCD_VidCmd(LCD_CLEAR);
}

void LCD_VidCmd(u8 Local_u8Cmd)
{
	DIO_VidSetPinValue(LCD_PORT, LCD_RS, PinLow); // set rs as cmd
	LCD_VidSendNibble(Local_u8Cmd);
}

void LCD_VidPrintChar(u8 Local_u8Char)
{
	DIO_VidSetPinValue(LCD_PORT, LCD_RS, PinHigh); // set rs as data
	LCD_VidSendNibble(Local_u8Char);
}

void LCD_VidPrintString(const char *str)
{
	while (*str){
		LCD_VidPrintChar(*str++);
	}
}

void LCD_VidPrintNumber(int Local_intNumber)
{
	char str[20];
	sprintf(str, "%d", Local_intNumber);
	LCD_VidPrintString(str);
}

void LCD_VidMoveCursor(u8 Local_u8Row, u8 Local_u8Column)
{
	u8 Local_u8Data; // the command which will set the position of the cursor
	/* in case of wrong input set the cursor to the first position of the LCD*/
	if (Local_u8Row > 2 || Local_u8Row < 1 || Local_u8Column > 16 || Local_u8Column < 1){
		Local_u8Data = LCD_HOME;
	}
	/********************************************/
	/*set the position of cursor depend on the selected row and column*/
	if (1 == Local_u8Row){
		Local_u8Data = LCD_1ST_LINE + Local_u8Column - 1;
	}
	else if (2 == Local_u8Row){
		Local_u8Data = LCD_2ND_LINE + Local_u8Column - 1;
	}
	/**************************************/

	LCD_VidCmd(Local_u8Data); // set the position  of the cursor
}

void LCD_VidDeleteChar(void)
{
	LCD_VidCmd(LCD_DECREMENT_CURSOR);
	LCD_VidPrintChar(SPACEBAR_KEY);
	LCD_VidCmd(LCD_INCREMENT_CURSOR);
	LCD_VidPrintChar(SPACEBAR_KEY);
	LCD_VidCmd(LCD_DECREMENT_CURSOR);
	LCD_VidPrintChar(SPACEBAR_KEY);
	LCD_VidCmd(LCD_INCREMENT_CURSOR);
}