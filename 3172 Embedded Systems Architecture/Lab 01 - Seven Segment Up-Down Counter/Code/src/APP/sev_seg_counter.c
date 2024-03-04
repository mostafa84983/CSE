#include "../lib/HAL/SEV_SEG/SEV_SEG_interface.h"
#include "../lib/HAL/KEYPAD/KEYPAD_interface.h"

#include "sev_seg_counter.h"

void sev_seg_counter()
{
	SEV_SEG_VidInit();
	KEYPAD_VidInitDirectMode();
	
	SEV_SEG_VidSpinner();
	SEV_SEG_VidSpinner();

	u8 Local_u8Counter = 0;
	u8 Local_u8Button = NOT_PRESSED;

	while(1)
	{
		
		SEV_SEG_VidDisplayNumber(Local_u8Counter, PinHigh);

		Local_u8Button = KEYPAD_u8CheckPressDirectMode();
		if ('U' == Local_u8Button)
        {
			if(Local_u8Counter < 99)
                Local_u8Counter++;
        }
		else if ('D' == Local_u8Button)
		{
            if(Local_u8Counter > 0)
                Local_u8Counter--;
        }
		else if ('R' == Local_u8Button)
			Local_u8Counter = 0;
	}
}