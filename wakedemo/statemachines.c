#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "statemachines.h"
#include "buzzer.h"
#include "lcdutils.h"
#include "lcddraw.h"
#include "wakedemo.h"

void next_state(int state) {
  unsigned int newEyeColor;
  unsigned int newFaceColor;
  switch(state) {

  case 1:
    newFaceColor = COLOR_PINK;
    newEyeColor = COLOR_BLUE;
    drawCatFaceEmoji(newFaceColor, newEyeColor);
    keyboard_cat();
    break;
  
  case 2:
    newFaceColor = COLOR_BLUE;
    newEyeColor = COLOR_PINK;
    drawCatFaceEmoji(newFaceColor, newEyeColor);
    flash(5);
    jigglypuff();
    green_on();
    green_off();
    red_off();
    break;

  case 3:
    newFaceColor = BLACK;
    newEyeColor = COLOR_RED;
    drawCatFaceEmoji(newFaceColor, newEyeColor);
    green_on();
    red_on();
    red_off();
    green_off();
    break;

  case 4:
    drawString5x7((screenHeight/2),(screenWidth/2)-10, "meow", COLOR_ORANGE, COLOR_BLACK);
    drawUnderlineAssembly(15, screenHeight - 15, 83, COLOR_RED);
    green_on();
    red_on();
    break;

  default:
    red_on();
    green_on();
    break;
  }

  // green led to show ready
  green_on();

}
