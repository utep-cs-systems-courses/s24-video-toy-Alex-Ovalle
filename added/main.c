#include <msp430.h>
#include "libTimer.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include <msp430.h>
#include "lcdutils.h"
#include "lcddraw.h"
#include "statemachines.h"
#include "wakedemo.h"

extern int redrawScreen;
int redrawScreen = 1;
int eyes_open;
int state;

int main(void){
  configureClocks();
  sw_init(); // Initializing Switches
  led_init(); // Initializing LED
  buzz_init(); // Initializing Buzzer

  green_on();
  enableWDTInterrupts();

  or_sr(0x18); // CPU off, GIE on

  state = 1;
  eyes_open = 1;
  while(1) {
    if(redrawScreen)  {
      redrawScreen = 0;
      update_eyes(state);
    }
    or_sr(0x10);
  }
}
