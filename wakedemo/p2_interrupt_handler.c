#include <msp430.h>
#include "switches.h"





/* Switches on P2 */

void __interrupt_vec(PORT2_VECTOR) Port_2(){
  if (P2IFG & switches) {      /* did a button cause this interrupt? */
    P2IFG &= ~switches;      /* clear pending sw interrupts */
    sw_interrupt_handler();/* single handler for all switches */
  }
}
