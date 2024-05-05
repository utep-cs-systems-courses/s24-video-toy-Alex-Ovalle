#include <msp430.h>
#include "libTimer.h"
#include "buzzer.h"
#include "notes.h"

void buzz_init(){
  timerAUpmode();
  P2SEL2 &= ~(BIT6 | BIT7);
  P2SEL &= ~BIT7;
  P2SEL |= BIT6;
  P2DIR = BIT6; // enable output to speaker
}


void buzzer_set_period(short cycles){
  CCR0 = cycles;
  CCR1 = cycles >> 1;
}

void tloz() {
  int melody[] = {  
    AS4,-2,  F4,8,  F4,8,  AS4,8,
    GS4,16,  FS4,16,  GS4,-2,
    AS4,-2,  FS4,8,  FS4,8,  AS4,8,
    A4,16,  G4,16,  A4,-2,
    AS4,4,  F4,-4,  AS4,8,  AS4,16,  C5,16, D5,16, DS5,16,
    F5,2,  F5,8,  F5,8,  F5,8,  FS5,16, GS5,16,
    AS5,-2,  AS5,8,  AS5,8,  GS5,8,  FS5,16,
    GS5,-8,  FS5,16,  F5,2,  F5,4, 
    DS5,-8, F5,16, FS5,2, F5,8, DS5,8,
    CS5,-8, DS5,16, F5,2, DS5,8, CS5,8,
    C5,-8, D5,16, E5,2, G5,8, 
    F5,16, F4,16, F4,16, F4,16,F4,16,F4,16,F4,16,F4,16,F4,8, F4,16,F4,8};
  int total_notes = sizeof(melody) / sizeof(melody[0]);

  for(int i = 0; i < 32; i++){
      buzzer_set_period(melody[i]);
      __delay_cycles(2500000);
      buzzer_set_period(0);
      __delay_cycles(250000);
    }
  buzzer_set_period(0);
}


void keyboard_cat() {
  int melody[] = {
    C4,4, E4,4, G4,4, E4,4, 
    C4,4, E4,8, G4,-4, E4,4,
    A3,4, C4,4, E4,4, C4,4,
    A3,4, C4,8, E4,-4, C4,4,
    G3,4, B3,4, D4,4, B3,4,
    G3,4, B3,8, D4,-4, B3,4,
  };

  int total_notes = sizeof(melody) / sizeof(melody[0]);

  for (int i = 0; i < total_notes; i++) {
    buzzer_set_period(melody[i]);
    __delay_cycles(2500000);
    buzzer_set_period(0);
    __delay_cycles(100000);
  }
  buzzer_set_period(0);
}
