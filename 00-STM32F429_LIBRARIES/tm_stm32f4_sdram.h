/**
 *	SDRAM on STM32F429 Discovery board
 *
 *	@author 	Tilen Majerle
 *	@email		tilen@majerle.eu
 *	@website	http://stm32f4-discovery.com
 *	@version 	v1.0
 */

#ifndef TM_SDRAM_H
#define TM_SDRAM_H 100

/**
 * Includes
 */
#include "stm32f4xx.h"
#include "stm32f4xx_rcc.h"
#include "stm32f4xx_gpio.h"
#include "stm32f4xx_fmc.h"
#include "defines.h"

#define SDRAM_START_ADR			0xD0000000

/**
 * Initialize SD ram
 *
 */
extern void TM_SDRAM_Init(void);

/**
 * Initialize SD ram used pins for FMC
 *
 * Called internally
 */
extern void TM_SDRAM_InitPins(void);

/**
 * Write 8 bit value to SD ram
 *
 * Parameters:
 * 	- uint32_t address:
 * 		address from 0x00 to 0x800000 for 8MBytes
 * 	- uint8_t value:
 * 		value to be saved in SD RAM
 */
extern void TM_SDRAM_Write8(uint32_t address, uint8_t value);

/**
 * Read 8 bit value from SD ram
 *
 * Parameters:
 * 	- uint32_t address
 * 		address to read from ram location
 * Return: value stored at desired location
 */
extern uint8_t TM_SDRAM_Read8(uint32_t address);

/**
 * Write 16 bit value to SD ram
 *
 * Parameters:
 * 	- uint32_t address:
 * 		address from 0x00 to 0x800000 for 8MBytes
 * 	- uint16_t value:
 * 		value to be saved in SD RAM
 */
extern void TM_SDRAM_Write16(uint32_t address, uint16_t value);

/**
 * Read 16 bit value from SD ram
 *
 * Parameters:
 * 	- uint32_t address
 * 		address to read from ram location
 * Return: value stored at desired location
 */
extern uint16_t TM_SDRAM_Read16(uint32_t address);

/**
 * Write 32 bit value to SD ram
 *
 * Parameters:
 * 	- uint32_t address:
 * 		address from 0x00 to 0x800000 for 8MBytes
 * 	- uint32_t value:
 * 		value to be saved in SD RAM
 */
extern void TM_SDRAM_Write32(uint32_t address, uint32_t value);

/**
 * Read 32 bit value from SD ram
 *
 * Parameters:
 * 	- uint32_t address
 * 		address to read from ram location
 * Return: value stored at desired location
 */
extern uint32_t TM_SDRAM_Read32(uint32_t address);

/**
 * Write 64 bit value to SD ram
 *
 * Parameters:
 * 	- uint32_t address:
 * 		address from 0x00 to 0x800000 for 8MBytes
 * 	- uint64_t value:
 * 		value to be saved in SD RAM
 */
extern void TM_SDRAM_Write64(uint32_t address, uint64_t value);

/**
 * Read 64 bit value from SD ram
 *
 * Parameters:
 * 	- uint32_t address
 * 		address to read from ram location
 * Return: value stored at desired location
 */
extern uint64_t TM_SDRAM_Read64(uint32_t address);

#endif
