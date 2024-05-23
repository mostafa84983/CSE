#include "STD_TYPES.h"
#include "BIT_MATH.h"
#include "DIO_private.h"
#include "DIO_interface.h"
//setting pin direction
void DIO_VidSetPinDirection(u8 Copy_u8Port,u8 Copy_u8Pin,u8 Copy_u8Direction){
	if(Copy_u8Direction==Input)
	{
		switch(Copy_u8Port){
		case Port_A: CLR_BIT(DDRA,Copy_u8Pin);
		break;
		case Port_B: CLR_BIT(DDRB,Copy_u8Pin);
		break;
		case Port_C: CLR_BIT(DDRC,Copy_u8Pin);
		break;
		case Port_D: CLR_BIT(DDRD,Copy_u8Pin);
		break;
		}
	}
	else if(Copy_u8Direction==Output)
	{
		switch(Copy_u8Port){
		case Port_A:SET_BIT(DDRA,Copy_u8Pin);
		break;
		case Port_B:SET_BIT(DDRB,Copy_u8Pin);
		break;
		case Port_C:SET_BIT(DDRC,Copy_u8Pin);
		break;
		case Port_D:SET_BIT(DDRD,Copy_u8Pin);
		break;
		}

	}
	else
	{

	}
}

//setting pin value
void DIO_VidSetPinValue(u8 Copy_u8Port,u8 Copy_u8pin,u8 Copy_u8Value){
	if(Copy_u8Value==PinLow)
	{
		switch(Copy_u8Port){
		case Port_A:CLR_BIT(PORTA,Copy_u8pin);
		break;
		case Port_B:CLR_BIT(PORTB,Copy_u8pin);
		break;
		case Port_C:CLR_BIT(PORTC,Copy_u8pin);
		break;
		case Port_D:CLR_BIT(PORTD,Copy_u8pin);
		break;
		}

	}
	else if(Copy_u8Value==PinHigh)
	{
		switch(Copy_u8Port){
		case Port_A:SET_BIT(PORTA,Copy_u8pin);
		break;
		case Port_B:SET_BIT(PORTB,Copy_u8pin);
		break;
		case Port_C:SET_BIT(PORTC,Copy_u8pin);
		break;
		case Port_D:SET_BIT(PORTD,Copy_u8pin);
		break;
		}

	}
	else
	{

	}

}

//getting pin value
void DIO_VidgetPinValue(u8 Copy_u8Port,u8 Copy_u8Pin,u8 *pu8Data){

	switch(Copy_u8Port){
	case Port_A:*pu8Data=GET_BIT(PINA,Copy_u8Pin);
	break;
	case Port_B:*pu8Data=GET_BIT(PINB,Copy_u8Pin);
	break;
	case Port_C:*pu8Data=GET_BIT(PINC,Copy_u8Pin);
	break;
	case Port_D:*pu8Data=GET_BIT(PIND,Copy_u8Pin);
	break;
	}
	
}

//setting port direction
void DIO_VidSetPortDirection(u8 Copy_u8Port,u8 Copy_u8Direction){
	switch(Copy_u8Port){
				case Port_A: DDRA=Copy_u8Direction;
				break;
				case Port_B: DDRB=Copy_u8Direction;
				break;
				case Port_C: DDRC=Copy_u8Direction;
				break;
				case Port_D: DDRD=Copy_u8Direction;
				break;
				}
}
//Set Port Value
void DIO_VidSetPortValue(u8 Copy_u8Port,u8 Copy_u8Value)
{
	switch(Copy_u8Port){
	case Port_A: PORTA=Copy_u8Value;
	break;
	case Port_B: PORTB=Copy_u8Value;
	break;
	case Port_C: PORTC=Copy_u8Value;
	break;
	case Port_D: PORTD=Copy_u8Value;
	break;
	}
}

//Get Port Value
void DIO_VidGetPortValue(u8 Copy_u8Port,u8 *pu8Data)
{
	switch(Copy_u8Port){
	case Port_A:*pu8Data=PINA;
	break;
	case Port_B:*pu8Data=PINB;
	break;
	case Port_C:*pu8Data=PINC;
	break;
	case Port_D:*pu8Data=PIND;
	break;
	}
}
//Toggle Bit
void DIO_VidToggleBit(u8 Copy_u8Port,u8 Copy_u8pin)
{
	switch(Copy_u8Port){
	case Port_A:Toggle_Bit(PORTA,Copy_u8pin);
	break;
	case Port_B:Toggle_Bit(PORTB,Copy_u8pin);
	break;
	case Port_C:Toggle_Bit(PORTC,Copy_u8pin);
	break;
	case Port_D:Toggle_Bit(PORTD,Copy_u8pin);
	break;
	}
}
