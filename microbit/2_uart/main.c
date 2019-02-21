#include "uart.h"
#include "gpio.h"

int main(){
  // Configure LED Matrix
  for(int i = 4; i <= 15; i++){
    GPIO->DIRSET = (1 << i);
    GPIO->OUTCLR = (1 << i);
  }

  int a = 0;
  int *p = &a;

  uart_init();
  GPIO->PIN_CNF[17] = 0;
  GPIO->PIN_CNF[26] = 0;
  uint32_t maskB = (1 << 26);
  uint32_t maskA = (1 << 17);

  while(1) {
    if (!(maskB&GPIO->IN)){
      uart_send('B');
    }
    else if (!(maskA&GPIO->IN)){
      uart_send('A');
    };
    led_matrix(p);
  };
  //uart_send('s');
  //uart_read();
  return 0;
};
