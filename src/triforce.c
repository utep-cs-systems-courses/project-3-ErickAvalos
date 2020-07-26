#include <msp430.h>
//#include <libtimer.h>
#include <lcdutils.h>
#include <lcddraw.h>
#include "triforce.h"

void drawTriforce() {
  int i;
  int j = 0;
  for (i = 62; i < 82; i++) {
    drawPixel(i, i-30, COLOR_WHITE);
  }
  for (i = 62; i < 82; i++) {
    drawPixel(i-(j*2), i-30, COLOR_WHITE);
    j++;
  }
  for (i = 42; i < 82; i++) {
    drawPixel(i, 52, COLOR_WHITE);
  }
  j = 0;
  for (i = 82; i < 102; i++) {
    drawPixel(i, i-30, COLOR_WHITE);
  }
  for (i = 82; i < 102; i++) {
    drawPixel(i-(j*2), i-30, COLOR_WHITE);
    j++;
  }
  for (i = 62; i < 102; i++) {
    drawPixel(i, 72, COLOR_WHITE);
  }
  j = 0;
  for (i = 42; i < 62; i++) {
    drawPixel(i, i+10, COLOR_WHITE);
  }
  for (i = 42; i < 62; i++) {
    drawPixel(i-(j*2), i+10, COLOR_WHITE);
    j++;
  }
  for (i = 22; i < 62; i++) {
    drawPixel(i, 72, COLOR_WHITE);
  }
}
