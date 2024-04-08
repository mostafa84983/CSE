#ifndef EX_INT_CONFIG_H_
#define EX_INT_CINFIG_H_

// GENERAL INTERRUPT CONTROL REGISTER
#define GICR_INT1   7
#define GICR_INT0   6
#define GICR_INT2   5

// MCU CONTROL REGISTER
#define MCUCR_ISC11 3
#define MCUCR_ISC10 2
#define MCUCR_ISC01 1
#define MCUCR_ISC00 0

// MCU CONTROL STATUR REGISTER
#define MCUCSR_ISC2 6

// GENERAL INTERRUPT FLAG REGISTER
#define GIFR_INTF1  7
#define GIFR_INTF0  6
#define GIFR_INTF2  5

// SOURCE DEFINITIONS
#define INT0    GICR_INT0
#define INT1    GICR_INT1
#define INT2    GICR_INT2

// SENSE DEFINITIONS
#define LOW_LEVEL 00
#define LOGICAL_CHANGE 01
#define FALLING_EDGE 10
#define RISING_EDGE 11

#endif