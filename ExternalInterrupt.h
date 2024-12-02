/*
 * ExternalInterrupt.h
 *
 * Created: 24-11-2023 13:29:38
 *  Author: ltpe
 */ 


#ifndef EXTERNALINTERRUPT_H_
#define EXTERNALINTERRUPT_H_

typedef enum
{
	LOW_LEVEL_GENERATE_INTERRUPT = 0,
	ANY_CHANGE_GENERATE_INTERRUPT,
	FALLING_EDGE_GENERATE_INTERRUPT,
	RISING_EDGE_GENERATE_INTERRUPT
} Interrupt_Cause_C;

typedef enum
{
	EXTERNAL_INTERRUPT_0,
	EXTERNAL_INTERRUPT_1,
	EXTERNAL_INTERRUPT_2,
	EXTERNAL_INTERRUPT_3,
	EXTERNAL_INTERRUPT_4,
	EXTERNAL_INTERRUPT_5,
	EXTERNAL_INTERRUPT_6,
	EXTERNAL_INTERRUPT_7,	
} ExternalInterruptEnum;

typedef void (*Function_Pointer_With_One_Uint16t_Parameter)(uint16_t);

typedef struct
{
	Function_Pointer_With_One_Uint16t_Parameter ThisFunctionPointer;
	uint16_t NumberOfExternalInterruptsOnPin;
} ExternalInterruptCallbackStruct;

//#define NUMBER_OF_EXTERNAL_INTERRUPTS	8
extern bool AttachExternalInterrupt(uint8_t ExternalInterruptNumber, Function_Pointer_With_One_Uint16t_Parameter FunctionPointer, Interrupt_Cause_C InterruptMode);
extern bool DetachExternalInterrupt(uint8_t ExternalInterruptNumber);
#endif /* EXTERNALINTERRUPT_H_ */