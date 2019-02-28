#include <stdint.h>

#define TWI0 ((NRF_TWI_REG*)0x40003000)
typedef struct {
	volatile uint32_t STARTRX;
	volatile uint32_t RESERVED1;
	volatile uint32_t STARTTX;
	volatile uint32_t RESERVED2[2];
	volatile uint32_t STOP;
	volatile uint32_t RESERVED3;
	volatile uint32_t SUSPEND;
	volatile uint32_t RESUME;
	volatile uint32_t RESERVED4[56];
	volatile uint32_t STOPPED;
	volatile uint32_t RXDREADY;
	volatile uint32_t RESERVED5[4];
	volatile uint32_t TXDSENT;
	volatile uint32_t RESERVED6;
	volatile uint32_t ERROR;
	volatile uint32_t RESERVED7[4];
	volatile uint32_t BB;
	volatile uint32_t RESERVED8[49];
	volatile uint32_t SHORTS;
	volatile uint32_t RESERVED9[63];
	volatile uint32_t INTEN;
	volatile uint32_t INTENSET;
	volatile uint32_t INTENCLR;
	volatile uint32_t RESERVED10[110];
	volatile uint32_t ERRORSRC;
	volatile uint32_t RESERVED11[14];
	volatile uint32_t ENABLE;
	volatile uint32_t RESERVED12;
	volatile uint32_t PSELSCL;
	volatile uint32_t PSELSDA;
	volatile uint32_t RESERVED13[2];
	volatile uint32_t RXD;
	volatile uint32_t TXD;
	volatile uint32_t RESERVED14;
	volatile uint32_t FREQUENCY;
	volatile uint32_t RESERVED15[24];
	volatile uint32_t ADDRESS;
	} NRF_TWI_REG;

void twi_init(){
	unint32_t maskA=0;
	maskA=(3<<2);
	maskA|=(6<<8);
	GPIO->PIN_CNF[0]=maskA;
	GPIO->PIN_CNF[30]=maskA;
	TWIO->PSELSCL=0;
	TWIO->PSELSDA=30;
	TWIO->FREQUENZY=0x01980000;
	TWIO->ERROR=0;
	TWIO->TXDSENT=0;
	TWIO->RXDREADY=0;
}

void twi_multi_read(
	uint8_t slave_address,
	uint8_t start_register,
	int registers_to_read,
	uint8_t * data_buffer){
	TWIO->ADDRESS=slave_address;
	TWIO->STARTTX=1;
	TWIO->TDX=start_register;

}
