#define F_CPU 16000000UL //definindo clock de 16Mhz 
#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD = 0b00111100;
  PORTD = 0b00000001;

  while(1){
    for(int i = 2; i<6; i++){
      PORTD = (1 << i);
      _delay_ms(100);
    }
    
    for(int i = 5; i>1; i--){
      PORTD = (1 << i);
      _delay_ms(100);
    }
  }
}