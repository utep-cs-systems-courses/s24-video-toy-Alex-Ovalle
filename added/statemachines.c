#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"


// ------------------------------------------------
void next_state(int state) {
  leds_off();
  unsigned int newEyeColor;
  unsigned int newFaceColor;

  switch(state) {
  case 1:
    newEyeColor = COLOR_BLUE;
    newFaceColor = COLOR_PINK;
    makeFace(newEyeColor, newFaceColor);
    led_flash(5);
    red_on();
    green_on();
    tloz();
    red_off();
    green_off();

    break;
  case 2:
    red_on();
    tg_intro();
    led_flash(2);
    red_off();
    break;
  case 3:
    led_flash(9);
    break;
  case 4:
    green_on();
    green_off();
    red_on();
    green_on();
    red_off();
    green_off();
    break;
  default:
    green_on();
    break;
  }
  // Green LED showing it's ready for the next step.
  green_on();
}
