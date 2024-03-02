#ifndef KEYPAD_INTERFACE_H_
#define KEYPAD_INTERFACE_H_

#include "KEYPAD_config.h"

void KEYPAD_VidInit(void);
u8 KEYPAD_u8CheckPress(void);

void KEYPAD_VidInitDirectMode(void);
u8 KEYPAD_u8CheckPressDirectMode(void);

#endif
