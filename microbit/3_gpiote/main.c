#include "gpio.h"
#include "ppi.h"
#include "gpiote.h"
#include <stdio.h>


int main() {
	for (int i = 4; i <= 12; i++){
		GPIO->DIRSET = (1 << i);
		GPIO->OUTCLR = (1 << i);
	};
	gpiote_init();
	while (1) {
		toggle_LED();
	};
	return 0;
}
