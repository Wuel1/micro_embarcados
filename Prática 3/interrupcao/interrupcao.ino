  #define F_CPU 16000000UL
  #include <avr/io.h>
  #include <util/delay.h>

  int i = 0;

  int main (void){

    DDRB = 0b00111111;

    EICRA = (1<<ISC11) | (1<<ISC10) | (1<<ISC01) | (1<<ISC00);
    EIMSK = (1<<INT1) | (1<<INT0);

    sei();


    while(1){

    }

  }

  // Incrementa

  ISR(INT0_vect){
    if(i > 6){
      i = 6;
      return;
    }  
    PORTB ^= (1<<i);
    i++;
  }

  // Decrementa

  ISR(INT1_vect){  
    if(i <= 0){
      i = 0;
      return;
    }

    i--;
    PORTB ^= (1<<i);

  }