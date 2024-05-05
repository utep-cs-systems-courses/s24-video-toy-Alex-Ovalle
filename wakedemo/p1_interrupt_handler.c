#include <msp430.h>
#include "switches.h"

/* Switch on P1 (S2) */

void

__interrupt_vec(PORT1_VECTOR) Port_1(){
  if (P1IFG & S0) {          
    P1IFG &= ~S0;               
    switch_interrupt_handler(); 
  }
}
