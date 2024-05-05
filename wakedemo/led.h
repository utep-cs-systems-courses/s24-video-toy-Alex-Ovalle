#ifndef led_included
#define led_included
#include <msp430.h>

#define RED_LED BIT0
#define GREEN_LED BIT6
#define LEDS (BIT0 | BIT6)

void led_init();
void flash();
void green_on();
void red_on();
void green_off();
void red_off();

#endif
