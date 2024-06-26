#include <msp430.h>
#include <stdio.h>
#include <libTimer.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "statemachines.h"
#include "switches.h"
#include "notes.h"
#include "buzzer.h"
#include "wakedemo.h"

extern int redrawScreen;
int redrawScreen = 1;
int eyes_open;
int state;

int main(void){
  configureClocks();
  lcd_init();
  sw_init();
  led_init();
  buzz_init();
  green_on();
  enableWDTInterrupts();
  or_sr(0x8);
  
  while(1){
    if(redrawScreen){
      redrawScreen = 0;
      welcome();
    }
    or_sr(0x10);
  }
}

void wdt_c_handler(){
  static int eyes_time = 0;
  if(eyes_open)
    if(eyes_time++ >= 1000){
      eyes_time = 0;
      state = 0;
      redrawScreen = 1;
	  }
    
}
