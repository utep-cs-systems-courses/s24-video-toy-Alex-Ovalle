#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "statemachines.h"

extern int redrawScreen;

void sw_init(){
  P2REN |= switches;
  P2IE |= switches;
  P2OUT |= switches;
  P2DIR &= ~switches;

  P1REN |= S0;
  P1IE |= S0;
  P1OUT |= S0;//side button initialization
  P1DIR &= ~S0;
}

char sw_zero_update_interrupt_sense(){
  char p1Value = P1IN;
  // if switch up/down , sense down/ up 
  P1IES |= (p1Value & S0);
  P1IES &= (p1Value | ~S0);
  return p1Value;
}

char sw_update_interrupt_sense(){
  char p2Value = P2IN;
  // if switch up/down , sense down/ up 
  P2IES |= (p2Value & switches);
  P2IES &= (p2Value | ~switches);
  return p2Value;
}

void sw_interrupt_handler(){
  char p1Value = sw_zero_update_interrupt_sense();
  char p2Value = sw_update_interrupt_sense();
  char button0 = (p1Value & S0) ? 0 : S0;
  char button1 = (p2Value & S1) ? 0 : S1;
  char button2 = (p2Value & S2) ? 0 : S2;
  char button3 = (p2Value & S3) ? 0 : S3;
  char button4 = (p2Value & S4) ? 0 : S4;

  if (button0)
      next_state(0);
  else if (button1)
      next_state(1);
  else if (button2)
      next_state(2);
  else if (button3)
      next_state(3);
  else if(button4)
      next_state(4);
}
