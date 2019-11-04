
/*
* Bellabaci Nazim     04/09/2017
* CodeBlocks
/*

#include <avr/io.h>
#include <util/delay.h>

int main(){

  //Set all pins of port B as output
  DDRB=0xFF;

  while(1){

  //toggle PORTB with 1 second delay
  PORTB=0x00;
  delay(1000);
  PORTB=0xFF;
  delay(1000);
  }
}
