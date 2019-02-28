#include <stdint.h>
#include "gpiote.h"
#include "ppi.h"

void gpiote_init(){

	volatile uint32_t maskA = 0;
	maskA |= 1;
	maskA |= (17 << 8);
	maskA |= (2 << 16);

	volatile uint32_t maskB = 0;
	maskB |= 3;
	maskB |= (13 << 8);
	maskB |= (3 << 16);

	volatile uint32_t maskC = 0;
	maskC |= 3;
	maskC |= (14 << 8);
	maskC |= (3 << 16);

	volatile uint32_t maskD = 0;
	maskD |= 3;
	maskD |= (15 << 8);
	maskD |= (3 << 16);

	GPIOTE->CONFIG[0] = maskA;
	GPIOTE->CONFIG[1] = maskB;
	GPIOTE->CONFIG[2] = maskC;
	GPIOTE->CONFIG[3] = maskD;
};

void toggle_LED(){
	PPI->PPI_CH[0].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[0].TEP = (uint32_t)&(GPIOTE->OUT[1]);

	PPI->PPI_CH[1].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[1].TEP = (uint32_t)&(GPIOTE->OUT[2]);

	PPI->PPI_CH[2].EEP = (uint32_t)&(GPIOTE->IN[0]);
	PPI->PPI_CH[2].TEP = (uint32_t)&(GPIOTE->OUT[3]);

	PPI->CHEN = 7;
};
