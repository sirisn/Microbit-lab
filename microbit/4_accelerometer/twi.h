#include <stdint.h>

void twi_init();
void twi_multi_read(
	uint8_t slave_address,
	uint8_t start_register,
	int registers_to_read,
	uint8_t * data_buffer
	);
