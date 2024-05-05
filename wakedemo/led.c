#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "notes.h"

void led_init(){
  P1DIR |= LEDS;
  P1OUT &= ~GREEN_LED;
  P1OUT &= ~RED_LED;
}

void flash(){
  P1OUT |= GREEN_LED;
  __delay_cycles(1500000);
  P1OUT &= ~RED_LED;
  __delay_cycles(500000);
  P1OUT &= ~GREEN_LED;
  __delay_cycles(500000);
  P1OUT |= RED_LED;
  __delay_cycles(1500000);
}

void green_on(){
  P1OUT ^= GREEN_LED;
  P1OUT &= ~RED_LED;
  __delay_cycles(5000);

}

void red_on(){
  P1OUT ^= RED_LED;
  P1OUT &= ~GREEN_LED;
}

void green_off(){
  P1OUT &= ~GREEN_LED;
  __delay_cycles(500000);

}

void red_off(){
  P1OUT &= ~RED_LED;
  __delay_cycles(500000);
}