/**
 * ADC library for STM32F4xx
 *
 *	@author		Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@link
 *	@version 	v1.0
 *	@gcc		v4.7 20013qr3
 *	@ide		CooCox CoIDE v1.7.6
 */
#ifndef TM_ADC_
#define TM_ADC_ 100

/*
ADC pins

CHANNEL			ADC1	ADC2	ADC3
ADC Channel 0	PA0		PA0		PA0
ADC Channel 1	PA1		PA1		PA1
ADC Channel 2	PA2		PA2		PA2
ADC Channel 3	PA3		PA3		PA3
ADC Channel 4	PA4		PA4		PF6
ADC Channel 5	PA5		PA5		PF7
ADC Channel 6	PA6		PA6		PF8
ADC Channel 7	PA7		PA7		PF9
ADC Channel 8	PB0		PB0		PF10
ADC Channel 9	PB1		PB1		PF3
ADC Channel 10	PC0		PC0		PC0
ADC Channel 11	PC1		PC1		PC1
ADC Channel 12	PC2		PC2		PC2
ADC Channel 13	PC3		PC3		PC3
ADC Channel 14	PC4		PC4		PF4
ADC Channel 15	PC5		PC5		PF5
*/

#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_adc.h"
#include "defines.h"

/**
 * This values can be overwriten in defines.h file
 */
#ifndef TM_ADC1_RESOLUTION
#define TM_ADC1_RESOLUTION		ADC_Resolution_12b
#endif

#ifndef TM_ADC2_RESOLUTION
#define TM_ADC2_RESOLUTION		ADC_Resolution_12b
#endif

#ifndef TM_ADC3_RESOLUTION
#define TM_ADC3_RESOLUTION		ADC_Resolution_12b
#endif

/**
 * Initialize ADCx with ADCx channel
 *
 * Parameters:
 * 	- ADC_TypeDef* ADCx: ADCx
 * 		ADC1, ADC2, ADC3
 * 	- uint8_t channel: channel (pin) for ADCx
 * 		- ADC_Channel_0, ADC_Channel_1, ..., ADC_Channel_15
 */
extern void TM_ADC_Init(ADC_TypeDef* ADCx, uint8_t channel);

/**
 * Read from ADCx channel
 *
 * Parameters:
 * 	- ADC_TypeDef* ADCx: ADCx
 * 		ADC1, ADC2, ADC3
 * 	- uint8_t channel: channel (pin) for ADCx
 * 		- ADC_Channel_0, ADC_Channel_1, ..., ADC_Channel_15
 */
extern uint16_t TM_ADC_Read(ADC_TypeDef* ADCx, uint8_t channel);

/**
 * Initialize pin for
 */
extern void TM_ADC_InitPin(uint16_t RCCx, GPIO_TypeDef* GPIOx, uint16_t PinX);

/**
 * Initialize ADC pins
 *
 * Parameters:
 * 	- ADC_TypeDef* ADCx: Select ADC
 *		- ADC1, ADC2, ADC3
 */
extern void TM_ADC_Channel_0_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_1_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_2_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_3_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_4_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_5_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_6_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_7_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_8_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_9_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_10_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_11_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_12_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_13_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_14_Init(ADC_TypeDef* ADCx);
extern void TM_ADC_Channel_15_Init(ADC_TypeDef* ADCx);

#endif
