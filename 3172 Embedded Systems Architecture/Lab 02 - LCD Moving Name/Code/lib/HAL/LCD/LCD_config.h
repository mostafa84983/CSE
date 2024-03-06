#ifndef LCD_CONFIG_H_
#define LCD_CONFIG_H_

#define LCD_RS Pin1
#define LCD_E Pin2
#define LCD_D4 Pin3
#define LCD_D5 Pin4
#define LCD_D6 Pin5
#define LCD_D7 Pin6

#define LCD_PORT Port_A

#define LCD_CLEAR 0x01
#define LCD_HOME 0x02
#define LCD_INCREMENT_CURSOR 0x06 // left to right
#define LCD_DECREMENT_CURSOR 0x04 // right to left
#define LCD_CURSOR_BLINKING 0x0D // Display ON cursor blinking
#define LCD_CURSOR_OFF 0x0C // Display ON cursor off
#define LCD_CURSOR_FIXED 0x0E // Display ON cursor fixed
#define LCD_2LINE_4BIT 0x28 // 2 lines, 5x8 matrix, 4-bit mode
#define LCD_1LINE_4BIT 0x20 // 1 line, 4-bit mode
#define LCD_1ST_LINE 0x80 // cursor first line
#define LCD_2ND_LINE 0xC0 // cursor second line

#define SPACEBAR_KEY 0x20

#endif
