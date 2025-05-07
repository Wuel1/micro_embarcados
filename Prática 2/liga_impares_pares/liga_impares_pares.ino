#define F_CPU 16000000UL
#include <avr/io.h>
#include <util/delay.h>

int main(void){
  DDRD = 0b11111111;
  PORTD = 0;

  while(1){

    //Ligar os impares
    for(int i=0; i<8; i++){
      if( i % 2 == 1){
        PORTD ^= (1 << i);
        _delay_ms(500);
      }
    }

    // Intervalo de 1 segundo
    _delay_ms(500);
    PORTD = 0;

    //Ligar os pares
    for(int i=0; i<8; i++){
      if( i % 2 == 0){
        PORTD ^= (1 << i);
        _delay_ms(500);
      }
    }
    
    // Intervalo de 1 segundo
    _delay_ms(500);
    PORTD = 0;

  }
  
}