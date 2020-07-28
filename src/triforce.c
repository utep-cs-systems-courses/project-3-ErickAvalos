#include <msp430.h>
//#include <libtimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "triforce.h"

static int up, down = 0;

void drawTriangle() {
  int i, j;
  int k = 0, redraw = 0;
  clearScreen(COLOR_WHITE);
  __delay_cycles(5000000);
  clearScreen(COLOR_BLACK);

  for (j = 0; j < 50; j++) {
    for (i = 62; i < 115; i++) {
      drawPixel(i, i-30 + redraw, COLOR_BLUE);
      drawPixel(62-(k++), i-30 + redraw, COLOR_BLUE);
    }
    __delay_cycles(1000000);
    clearScreen(COLOR_BLACK);

    if (redraw > 70) {
	up = 1;
	down = 0;
      } else if (redraw < -10) {
	up = 0;
	down = 1;
      }

      if (down)
	redraw += 5;
      else redraw -= 5;
      k = 0;
  }
}
