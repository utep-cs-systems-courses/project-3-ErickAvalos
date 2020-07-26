#include <msp430.h>
#include "switches.h"
#include "led.h"
#include "stateMachine.h"
#include "libTimer.h"

char state, switch_state_down, switch_state_changed; /* effectively boolean */
char sw_one, sw_two, sw_thr, sw_fou, CURRENT_STATE;

static char 
switch_update_interrupt_sense()
{
  char p2val = P2IN;
  /* update switch interrupt to detect changes from current buttons */
  P2IES |= (p2val & SWITCHES);	/* if switch up, sense down */
  P2IES &= (p2val | ~SWITCHES);	/* if switch down, sense up */
  return p2val;
}

void 
switch_init()			/* setup switch */
{  
  P2REN |= SWITCHES;		/* enables resistors for switches */
  P2IE |= SWITCHES;		/* enable interrupts from switches */
  P2OUT |= SWITCHES;		/* pull-ups for switches */
  P2DIR &= ~SWITCHES;		/* set switches' bits for input */
  switch_update_interrupt_sense();
  //led_update();
  switch_interrupt_handler();
}

void
switch_interrupt_handler()
{
  char hold = 0;
  char p2val = switch_update_interrupt_sense();
  //switch_state_down = (p1val & SW1) ? 0 : 1; /* 0 when SW1 is up */
  //switch_state_changed = 1;
  //led_update();
  sw_one = (p2val & SW1) ? 0 : 1;
  sw_two = (p2val & SW2) ? 0 : 1;
  sw_thr = (p2val & SW3) ? 0 : 1;
  sw_fou = (p2val & SW4) ? 0 : 1;
  switch_state_changed = 1;
  if (sw_one) {
    stateMachine(1);
  }
  else if (sw_two) {
    stateMachine(2);
  }
  else if (sw_thr) {
    stateMachine(3);
  }
  else if (sw_fou) {
    stateMachine(4);
  }
}
