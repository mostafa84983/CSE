#include "KEYPAD_interface.h"

/*	KEYPAD VALUES	*/
static u8 Global_u8_Kpd_Arr[KEYPAD_ROW_NUM][KEYPAD_COL_NUM] = KEYPAD_ARR_VAL;

/*	KEYPAD VALUES	*/
static u8 Global_u8_Kpd_Arr_DirectMode[KEYPAD_ROW_NUM] = KEYPAD_ARR_VAL_DirectMode;

/*	KEYPAD COLUMNS	*/
static u8 Global_u8_Kpd_Col_Arr[KEYPAD_COL_NUM] = {KEYPAD_COL_1, KEYPAD_COL_2, KEYPAD_COL_3, KEYPAD_COL_4};

/*	KEYPAD ROWS	*/
static u8 Global_u8_Kpd_Row_Arr[KEYPAD_ROW_NUM] = {KEYPAD_ROW_1, KEYPAD_ROW_2, KEYPAD_ROW_3, KEYPAD_ROW_4};

void KEYPAD_VidInit(void)
{
	/* Initialize column and row bits in keypad as input pins */
	for (u8 Local_u8_Counter = 0; Local_u8_Counter < KEYPAD_COL_NUM; Local_u8_Counter++)
	{
		DIO_VidSetPinDirection(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], Input);  // SET COL AS INPUT
		DIO_VidSetPinDirection(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Counter], Output); // SET ROW AS OUTPUT
		DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Counter], PinHigh);	  // SET ROW VALUE AS HIGH
		DIO_VidSetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], PinHigh);	  // CONNECT COL TO PULL-UP RESISTANCE
	}
}

u8 KEYPAD_u8CheckPress(void)
{
	u8 Local_u8_Btn = NOT_PRESSED; // KEY HOLDER

	for (u8 Local_u8_Row_Cntr = 0; Local_u8_Row_Cntr < KEYPAD_ROW_NUM; Local_u8_Row_Cntr++) // LOOP ON ROWS
	{
		DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], PinLow); // SET ROW VALUE AS LOW

		for (u8 Local_u8_Col_Cntr = 0; Local_u8_Col_Cntr < KEYPAD_COL_NUM; Local_u8_Col_Cntr++) // LOOP ON COLUMNS
		{
			DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn); // GET COLUMN VALUE

			if (PinLow == Local_u8_Btn) // CHECK IF COLUMN IS LOW
			{
				while (PinLow == Local_u8_Btn)																	  // DEBOUNCING
					DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn); // GET COLUMN VALUE

				Local_u8_Btn = Global_u8_Kpd_Arr[Local_u8_Row_Cntr][Local_u8_Col_Cntr];					// RETURN KEYPAD VALUE
				DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], PinHigh); // REVERT ROW VALUE AS HIGH
				return Local_u8_Btn;
			}
		}

		DIO_VidSetPinValue(KEYPAD_ROW_PORT, Global_u8_Kpd_Row_Arr[Local_u8_Row_Cntr], PinHigh); // REVERT ROW VALUE AS HIGH
	}

	return NOT_PRESSED; // return the pressed key in case of key pressed or return 0xff in case of no key pressed
}

void KEYPAD_VidInitDirectMode(void)
{
	/* Initialize first row & all column bits in keypad as input pins */
	for (u8 Local_u8_Counter = 0; Local_u8_Counter < KEYPAD_COL_NUM; Local_u8_Counter++)
	{
		DIO_VidSetPinDirection(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], Input);  // SET COL AS INPUT
		DIO_VidSetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Counter], PinHigh);	  // CONNECT COL TO PULL-UP RESISTANCE
	}
}

u8 KEYPAD_u8CheckPressDirectMode(void)
{
	u8 Local_u8_Btn = NOT_PRESSED; // KEY HOLDER

	for (u8 Local_u8_Col_Cntr = 0; Local_u8_Col_Cntr < KEYPAD_COL_NUM; Local_u8_Col_Cntr++) // LOOP ON COLUMNS
	{
		DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn); // GET COLUMN VALUE

		if (PinLow == Local_u8_Btn) // CHECK IF COLUMN IS LOW
		{
			while (PinLow == Local_u8_Btn)																	  // DEBOUNCING
				DIO_VidGetPinValue(KEYPAD_COL_PORT, Global_u8_Kpd_Col_Arr[Local_u8_Col_Cntr], &Local_u8_Btn); // GET COLUMN VALUE

			Local_u8_Btn = Global_u8_Kpd_Arr_DirectMode[Local_u8_Col_Cntr]; // RETURN KEYPAD VALUE
			return Local_u8_Btn;
		}
	}

	return NOT_PRESSED; // return the pressed key in case of key pressed or return 0xff in case of no key pressed
}