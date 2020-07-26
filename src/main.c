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
  configureClocks();
  lcd_init();
  u_char width = screenWidth, height = screenHeight;
  clearScreen(COLOR_BLUE);
  //p2sw_init(15);
  switch_init();
  led_init();
  buzzer_init();

  //enableWDTInterrupts();

  or_sr(0x18);  // CPU off, GIE on
} 
