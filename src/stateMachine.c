#include <stdlib.h>
#include <msp430.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "stateMachine.h"
#include "led.h"
#include "switches.h"
#include "buzzer.h"
#include "triforce.h"
//#include "lcdutils.h"
//#include "lcddraw.h"

void stateMachine(int state)
{
  int col = 0;
  int dummy = col;

  clearScreen(COLOR_GREEN);

  //int state = 0;
  //while (1) {
    /* if ((P2IN & BIT0) == 1) */
    /*   state = 1; */
    /* else if ((P2IN & BIT1) == 0) */
    /*   state = 2; */
    /* else if ((P2IN & BIT2) == 0) */
    /*   state = 3; */
    /* else if ((P2IN & BIT3) == 0) */
    /*   state = 4; */
    /* else */
    /*   state = 0; */
    
    switch (state) {
    case 1:
      led_dim();
      state = 0;
      break;
    case 2:
      clearScreen(COLOR_BLACK);
      drawTriforce();
      binary_count();
      state = 0;
      break;
    case 3:
      led_alternate();
      state = 0;
      break;
    case 4:
      play_song();
      state = 0;
      break;
    default:
      break;
    }
    //}

  /* switch (state) { */
  /* case 1: */
  /*   led_dim(); */
  /*   state = 0; */
  /*   break; */
  /* case 2: */
  /*   binary_count(); */
  /*   state = 0; */
  /*   break; */
  /* case 3: */
  /*   led_alternate(); */
  /*   state = 0; */
  /*   break; */
  /* case 4: */
  /*   play_song(); */
  /*   state = 0; */
  /*   break; */
  /* default: */
  /*   break; */
  /* } */ 
}
