#include <msp430.h>
#include <libTimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
//#include <p2switches.h>
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "stateMachine.h"
#include "triforce.h"

//redrawScreen = 1;

void main(void) 
{ 
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  switch_init();
  led_init();
  buzzer_init();
  clearScreen(COLOR_WHITE);
  enableWDTInterrupts();
  or_sr(0x8);  // GIE on
  while (1) {
    while (!redrawScreen) {
      //P1OUT |= LED_RED;
      P1OUT &= ~LED_RED;
      or_sr(0x10);
    }
    //P1OUT &= ~LED_RED;
    P1OUT |= LED_RED;
    //clearScreen(COLOR_GREEN);
    __delay_cycles(30000);
    redrawScreen = 0;
  }
}

void wdt_c_handler()
{
  static char blink_count = 0;
  if (++blink_count == 125) {
    if (state == 1)
      stateMachine(4);
    blink_count = 0;
  }
}
