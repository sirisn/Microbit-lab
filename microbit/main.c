#include <stdint.h>
#include <stdlib.h>
#include "uart.h"
#include "twi.h"
#include "utility.h"
#include "accel.h"
#include "ubit_led_matrix.h"
#include "gpio.h"

int main(){
	uart_init();
    ubit_led_matrix_init();

	twi_init();
    accel_init();

    int data_buffer[3];
    int x_dot, y_dot;

    while(1)
    {
        accel_read_x_y_z(data_buffer);

        x_dot = data_buffer[0] / 50;
        y_dot = data_buffer[1] / 50;

        ubit_led_matrix_light_only_at(x_dot, y_dot);

        utility_print(
            &uart_send,
            "X: %6d Y: %6d Z: %6d\n\r",
            data_buffer[0],
            data_buffer[1],
            data_buffer[2]
        );
    }


/*
	uint8_t * data_buffer;
	data_buffer = (uint8_t * )malloc(8 * sizeof(uint8_t));
	twi_multi_read(	0x19, 0x0f, 1, data_buffer);
	if (!*data_buffer == 0x5A){
		int i;
		for(i = 4; i <= 12; i++){
  			GPIO->OUTCLR = (1 << i);

		}
		for(i = 13; i <= 15; i++){
			GPIO->OUTSET = (1 << i);
		}
	}
	free(data_buffer);
*/
	return 0;
}
