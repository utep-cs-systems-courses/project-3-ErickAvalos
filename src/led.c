#include <msp430.h>
#include "led.h"
#include "switches.h"
#include "stateMachine.h"

unsigned char red_on = 0, green_on = 0;

void led_init()
{
  P1DIR |= LEDS;		// bits attached to leds are output
  switch_state_changed = 1;
}

void led_update()
{
  if (switch_state_changed) {
    char ledFlags = 0;
    ledFlags |= switch_state_down ? LED_GREEN : 0;
    ledFlags |= switch_state_down ? LED_RED : 0;
    P1OUT &= (0xff - LEDS) | ledFlags; // clear bit for off leds
    P1OUT |= ledFlags;		     // set bit for on leds
  }
  switch_state_changed = 0;
}

void off() {
  if (green_on) {
    //P1OUT |= LED_RED;
    P1OUT |= LED_GREEN;
  }
  else {
    //P1OUT &= !LED_RED;
    P1OUT &= !LED_GREEN;
  }
  toggle_red();
}

// written in assembly.s //

/* char toggle_red() { */
/*   static char states = 0; */
/*   switch (states) { */
/*   case 0: */
/*     red_on = 1; */
/*     green_on = 1;
/*     states = 1; */
/*     break; */
/*   case 1: */
/*     red_on = 0; */
/*     green_on = 0; */
/*     states = 0; */
/*     break; */
/*   } */
/*   return 1; */
/* } */

void led_dim()
{
  for (int i = 0; i < 200; i++) {
    //P1OUT = LED_RED;
    __delay_cycles(100000);
    P1OUT = LED_GREEN;
    __delay_cycles(100000);
    //P1OUT = !LED_RED;
    __delay_cycles(100000);
    P1OUT = !LED_GREEN;
    __delay_cycles(100000);
  }
}

void binary_count()
{
  P1OUT = !LED_GREEN;
  __delay_cycles(10000000);
  P1OUT = !LED_RED;
  __delay_cycles(10000000);
  P1OUT = !LED_GREEN;
  __delay_cycles(10000000);
  P1OUT = LED_RED;
  __delay_cycles(10000000);
  P1OUT = LED_GREEN;
  __delay_cycles(10000000);
  P1OUT = !LED_RED;
  __delay_cycles(10000000);
  P1OUT = LEDS;
  __delay_cycles(10000000);
}

void led_alternate()
{
  for (int i = 0; i < 20; i++) {
    P1OUT = LED_GREEN;
    __delay_cycles(500000);
    //P1OUT = !LED_RED;
    __delay_cycles(2500000);
    P1OUT = !LED_GREEN;
    __delay_cycles(500000);
    //P1OUT = LED_RED;
    __delay_cycles(2500000);
  }
}
