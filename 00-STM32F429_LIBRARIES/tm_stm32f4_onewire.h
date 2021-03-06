/**
 *	Onewire library for STM32F4
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@link		http://bit.ly/1nvT6jG
 *	@version 	v1.0
 */
#ifndef TM_ONEWIRE_H
#define TM_ONEWIRE_H 100

/**
 * Library dependencies
 * - TM_DELAY
 */
/**
 * Includes
 */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "tm_stm32f4_delay.h"
#include "defines.h"

//Owerwrite this in defines.h if you want to use other pin
#ifndef TM_ONEWIRE_PIN	
#define TM_ONEWIRE_RCC			RCC_AHB1Periph_GPIOD
#define TM_ONEWIRE_PORT			GPIOD
#define TM_ONEWIRE_PIN			GPIO_Pin_0
#endif

#define TM_ONEWIRE_DELAY(x)		Delay(x)

#define TM_ONEWIRE_LOW			TM_ONEWIRE_PORT->BSRRH = TM_ONEWIRE_PIN;
#define TM_ONEWIRE_HIGH			TM_ONEWIRE_PORT->BSRRL = TM_ONEWIRE_PIN;
#define TM_ONEWIRE_INPUT		TM_OneWire_GPIO_InitDef.GPIO_Mode = GPIO_Mode_IN; GPIO_Init(TM_ONEWIRE_PORT, &TM_OneWire_GPIO_InitDef);
#define TM_ONEWIRE_OUTPUT		TM_OneWire_GPIO_InitDef.GPIO_Mode = GPIO_Mode_OUT; GPIO_Init(TM_ONEWIRE_PORT, &TM_OneWire_GPIO_InitDef);

//OneWire commands
#define TM_ONEWIRE_CMD_RSCRATCHPAD			0xBE //Read Scratchpad
#define TM_ONEWIRE_CMD_WSCRATCHPAD			0x4E //Write Scratchpad
#define TM_ONEWIRE_CMD_CPYSCRATCHPAD		0x48
#define TM_ONEWIRE_CMD_RECEEPROM			0xB8
#define TM_ONEWIRE_CMD_RPWRSUPPLY			0xB4
#define TM_ONEWIRE_CMD_SEARCHROM			0xF0
#define TM_ONEWIRE_CMD_READROM				0x33
#define TM_ONEWIRE_CMD_MATCHROM				0x55
#define TM_ONEWIRE_CMD_SKIPROM				0xCC
#define TM_ONEWIRE_CMD_ALARMSEARCH			0xEC

/**
 * Initialize OneWire bus
 *
 */
extern void TM_OneWire_Init(void);

/**
 * Reset OneWire bus
 */
extern uint8_t TM_OneWire_Reset(void);

/**
 * Read single bit from bus
 *
 * 0 or 1 is returned
 */
extern uint8_t TM_OneWire_ReadBit(void);

/**
 * Read byte from bus
 *
 * Byte is returned
 *
 */
extern uint8_t TM_OneWire_ReadByte(void);

/**
 * Write single bit to bus
 *
 * Parameters:
 * 	- uint8_t bit
 * 		0 or 1, what you want to send
 *
 */
extern void TM_OneWire_WriteBit(uint8_t bit);

/**
 * Write byte to bus
 *
 * Parameters:
 * 	- uint8_t byte
 * 		Byte to be sent
 */
extern void TM_OneWire_WriteByte(uint8_t byte);

/**
 * Search for devices
 *
 * Returns 1 if device is found, otherwise 0
 */
extern uint8_t TM_OneWire_Search(void);

/**
 * Start search, reset states
 *
 * Returns 1 if any device on bus
 */
extern uint8_t TM_OneWire_First(void);

/**
 * Read next device
 *
 * Returns 1 if more devices are on bus, otherwise 0
 */
extern uint8_t TM_OneWire_Next(void);

/**
 * Get rom from device from search
 *
 * Parameters
 * 	- uint8_t index:
 * 		because each device has 8bytes long rom, you have to call this 8 times, to get rom bytes from 0 to 7
 */
extern uint8_t TM_OneWire_GetROM(uint8_t index);

/**
 * Select specific slave on bus
 *
 * Parameters:
 * 	- uint8_t addr[]
 * 		8 bytes ROM address
 */
extern void TM_OneWire_Select(uint8_t addr[]);

#endif

