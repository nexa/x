#include <stdlib.h>
#include <stdio.h>
#include "x_x.h"
#include "x_vt100.h"

vt_style style;



int main(int argc, char** argv) {

   x_vt_init(1024);

   //x_vt_underscore(style);
   //x_vt_bright(style);

  x_vt_fg_green(style);
  x_vt_bg_red(style);

  //x_vt_printf("Hello World!", style);

  x_vt_blink(style);
  x_vt_dim(style);
  x_vt_bg_cyan(style);

  x_vt_printf("Hello World!", style);

  x_vt_cursor_home(2, 3);
  /*
  printf("\033[2J");
  printf("\033[5;41;36mokdddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd\r\ndddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddddd \033[0m");
  */
  getchar();
  //getchar();

  x_vt_uninit();

  return 0;
} 
