#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "statemachines.h"


char stateDown;

void sw_init() {
  P2REN |= switches;
  P2IE |= switches;
  P2OUT |= switches;
  P2DIR &= ~switches;
  sw_update_interrupt_sense();
  sw_interrupt_handler();
  led_update();

}


char sw_update_interrupt_sense() {
  char p2Value = P2IN;
  P2IES |= (p2Value & switches);/* if switch up, sense down */
  P2IES &= (p2Value | ~switches);/* if switch down, sense up */
  return p2Value;
}

char sw_zero_update_interrupt_sense(){
  char p1Value = P1IN;
  // update switch interrupt to detect changes from current buttons
  // sense down/up if switch up/down
  P1IES |= (p1Value & S0); 
  P1IES &= (p1Value | ~S0);

  return p1Value;
} 


void sw_interrupt_handler() {
  char p1Value = sw_zero_update_interrupt_sense();
  char p2Value = sw_update_interrupt_sense();
  char button1 = (p2Value & S1) ? 0 : S1;
  char button2 = (p2Value & S2) ? 0 : S2;
  char button3 = (p2Value & S3) ? 0 : S3;
  char button4 = (p2Value & S4) ? 0 : S4;

  if (button1)
    {
      next_state(1);
      stateDown = 1;
    }
  else if (button2)
    {
      next_state(2);
      stateDown = 1;
    }
  else if (button3)
    {
      next_state(3);
      stateDown = 1;
    }

  else if (button4)
    {
      next_state(4);
      stateDown = 1;
    }
}