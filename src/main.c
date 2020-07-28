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

void main(void) 
{
  P1DIR |= LED_GREEN;
  P1OUT |= LED_GREEN;
  
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  switch_init();
  led_init();
  buzzer_init();
  clearScreen(COLOR_BLUE);

  or_sr(0x18);  // CPU off, GIE on

  while (1) {
    while (!redrawScreen) {
      P1OUT &= ~LED_RED;
      or_sr(0x18);
    }
    P1OUT |= LED_RED;
    __delay_cycles(30000);
    redrawScreen = 0;
  }
}
