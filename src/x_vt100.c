#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "x_x.h"
#include "x_vt100.h"
#include "x_memory.h"

size_t len_ = 0;
size_t buffer_len_ = 0;
byte *buffer_ = NULL;

/*
\033[1;2;4;5;7;8;30;40m\033[0m 
*/
#define vt_ascii_code_len 24
#define vt_ascii_code_max ((vt_ascii_code_len + 7) / 8) * 8

#define x_vt_is_inited() \
  ((len_ != 0) && (buffer_ != NULL))

#define x_vt_clear_buffer() \
  if (x_vt_is_inited()) \
    memset(buffer_, 0, len_);

int x_vt_format(const char *string, vt_style style) {
  size_t index, str_len, cpy_len;

  x_assert(x_vt_is_inited());
  x_assert(string);

  str_len = strlen(string);
  if (str_len == 0) {
    return 0;
  }
  cpy_len = x_min(str_len, len_);

  index = 0;

  x_memcpy(buffer_, "\033[", 2);
  index += 2;

  if (x_vt_is_bright(style)) {
    buffer_[index++] = '1';
  }
  if (x_vt_is_dim(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '2';
  }
  if (x_vt_is_underscore(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '4';
  }
  if (x_vt_is_blink(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '5';
  }
  if (x_vt_is_reverse(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '7';
  }
  if (x_vt_is_hidden(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '8';
  }

  if (x_vt_is_fg(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '3';
    buffer_[index] = '0';
    buffer_[index++] += (x_vt_fg_index(style) - 1);
  }

  if (x_vt_is_bg(style)) {
    buffer_[index++] = ';';
    buffer_[index++] = '4';
    buffer_[index] = '0';
    buffer_[index++] += (x_vt_bg_index(style) - 1);
  }

  buffer_[index++] = 'm';

  x_memcpy((buffer_ + index), string, cpy_len);
  index += cpy_len;
  
  x_memcpy((buffer_ + index), "\033[0m", 4);
  index += 4;
  
  return index;
}

void x_vt_cursor_move(size_t x, char c) {
  int str_len = 0;

  x_check(x_vt_is_inited());
  x_check(x < len_);

  x_vt_clear_buffer();

  str_len = snprintf(buffer_, buffer_len_, "\033[%d%c", x, c);
  if (str_len > 0 &&
      str_len <= buffer_len_)
    printf(buffer_);
}

void x_vt_cursor_ctrl(const char* string) {
  x_check(x_vt_is_inited());

  x_check(string);
  x_check(strlen(string) > 0);

  printf(string);
}

bool x_vt_init(size_t len) {
  x_check(len != 0);

  if (x_vt_is_inited()) {
    x_vt_uninit();
  }

  buffer_len_ = len * sizeof(byte) + vt_ascii_code_max;
  buffer_ = x_malloc(buffer_len_);
  if (buffer_ != NULL) {
    len_ = len;
    return true;
  } else {
    len_ = 0;
    buffer_len_ = 0;
    return false;
  }
}

bool x_vt_uninit() {
  if (buffer_ != NULL) {
    x_free(buffer_);
    buffer_ = NULL;    
  }
  len_ = 0;
  buffer_len_ = 0;
}

void x_vt_cursor_home(size_t x, size_t y) {
  int str_len = 0;

  x_check(x_vt_is_inited());
  x_check(x < len_);
  x_check(y < len_);
  
  x_vt_clear_buffer();

  str_len = snprintf(buffer_, buffer_len_, "\033[%d;%dH", x, y);
  if (str_len > 0 &&
      str_len <= buffer_len_)
    printf(buffer_);
}

void x_vt_cursor_up(size_t x) {
  x_vt_cursor_move(x, 'A');
}

void x_vt_cursor_down(size_t x) {
  x_vt_cursor_move(x, 'B');
}

void x_vt_cursor_forward(size_t x) {
  x_vt_cursor_move(x, 'C');
}

void x_vt_cursor_backward(size_t x) {
  x_vt_cursor_move(x, 'D');
}

void x_vt_cursor_save() {
  x_vt_cursor_ctrl("\033[s");
}

void x_vt_cursor_unsave() {
  x_vt_cursor_ctrl("\033[u");
}

void x_vt_printf(const char* string, const vt_style style) {
  x_check(x_vt_is_inited());

  x_vt_clear_buffer();

  if (x_vt_format(string, style) > 0) {
    printf(buffer_);
  }
}
