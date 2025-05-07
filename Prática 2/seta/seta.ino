#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD = 0b11111111;
  PORTD = 0;

  while(1){

    // Liga os leds
    for(int i=0; i<4; i++){

      // do 0 até o 3
      PORTD ^= (1<<i);

      // do 7 até o 4
      PORTD ^= (1<<7-i);

      _delay_ms(500);
    }
    
    _delay_ms(1000);

    // Desliga os leds
    for(int i=3; i>=0; i--){

      // do 3 até o 0
      PORTD ^= (1<<i);

      // do 4 até o 7
      PORTD ^= (1<<7-i);

      _delay_ms(500);
    }

  }
  
}