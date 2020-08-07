#include <stdlib.h>
#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "triforce.h"

int redrawScreen;

void stateMachine(int state)
{
  clearScreen(COLOR_BLACK);
  switch (state) {
  case 1:
    redrawScreen = 1;
    //state = 0;
    break;
  case 2:
    redrawScreen = 1;
    clearScreen(COLOR_BLACK);
    led_alternate();
    drawTriangle();
    //binary_count();
    state = 0;
    break;
  case 3:
    redrawScreen = 1;
    clearScreen(COLOR_BLACK);
    drawString5x7(40, 60, "5x7 FONT", COLOR_WHITE, COLOR_BLUE);
    drawString8x12(25, 75, "8x12 FONT", COLOR_WHITE, COLOR_BLUE);
    off();
    state = 0;
    break;
  case 4:
    redrawScreen = 1;
    play_song();
    //led_alternate();
    led_dim();
    state = 0;
    break;
  case 0:
    //toggle_led |= LED_RED;
    clearScreen(COLOR_GREEN);
    redrawScreen = 0;
    break;
  default:
    break;
  } 
}
