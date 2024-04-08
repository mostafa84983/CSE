#include "GIE_interface.h"
#include "GIE_private.h"

#include "../../../include/bitmanip.h"

void GIE_VidEnable(void){
    SET_BIT(SREG,SREG_I);
}

void GIE_VidDisnable(void){
    CLR_BIT(SREG,SREG_I);
}