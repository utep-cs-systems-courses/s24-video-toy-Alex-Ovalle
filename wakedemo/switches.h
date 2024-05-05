#ifndef switches_included
#define switches_included

#define S0 BIT3
#define S1 BIT0
#define S2 BIT1
#define S3 BIT2
#define S4 BIT3

#define switches (S1 | S2 | S3 | S4)

extern int state_flag;

void sw_init();
char sw_update_interrupt_sense();
char sw_zero_update_interrupt_sense();
void sw_interrupt_handler();


#endif // included
