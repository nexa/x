#ifndef x_vt100
#define x_vt100

/* display attribute  */
#define vt_bright     0x00000001
#define vt_dim        0x00000002
#define vt_underscore 0x00000004
#define vt_blink      0x00000008
#define vt_reverse    0x00000010
#define vt_hidden     0x00000020

#define vt_foreground    0x000f0000
#define vt_fg_mask       0xfff0ffff
#define vt_background    0x0f000000
#define vt_bg_mask       0xf0ffffff

#define vt_fg_black      0x00010000
#define vt_fg_red        0x00020000
#define vt_fg_green      0x00030000
#define vt_fg_yellow     0x00040000
#define vt_fg_blue       0x00050000
#define vt_fg_magenta    0x00060000
#define vt_fg_cyan       0x00070000
#define vt_fg_white      0x00080000
#define vt_bg_black      0x01000000
#define vt_bg_red        0x02000000
#define vt_bg_green      0x03000000
#define vt_bg_yellow     0x04000000
#define vt_bg_blue       0x05000000
#define vt_bg_magenta    0x06000000
#define vt_bg_cyan       0x07000000
#define vt_bg_white      0x08000000

typedef unsigned int vt_style;

#define x_vt_style(style, attribute)    (style = style | attribute)
#define x_vt_bright(style)              x_vt_style(style, vt_bright)
#define x_vt_dim(style)                 x_vt_style(style, vt_dim)
#define x_vt_underscore(style)          x_vt_style(style, vt_underscore)
#define x_vt_blink(style)               x_vt_style(style, vt_blink)
#define x_vt_reverse(style)             x_vt_style(style, vt_reverse)
#define x_vt_hidden(style)              x_vt_style(style, vt_hidden)

#define x_vt_is_style(style, attribute) ((style & attribute) == attribute)
#define x_vt_is_bright(style)           x_vt_is_style(style, vt_bright)
#define x_vt_is_dim(style)              x_vt_is_style(style, vt_dim)
#define x_vt_is_underscore(style)       x_vt_is_style(style, vt_underscore)
#define x_vt_is_blink(style)            x_vt_is_style(style, vt_blink)
#define x_vt_is_reverse(style)          x_vt_is_style(style, vt_reverse)
#define x_vt_is_hidden(style)           x_vt_is_style(style, vt_hidden)

#define x_vt_fg_color(style, color) (style = ((style & vt_fg_mask) | color))
#define x_vt_fg_black(style)        x_vt_fg_color(style, vt_fg_black)
#define x_vt_fg_red(style)          x_vt_fg_color(style, vt_fg_red)
#define x_vt_fg_green(style)        x_vt_fg_color(style, vt_fg_green)
#define x_vt_fg_yellow(style)       x_vt_fg_color(style, vt_fg_yellow)
#define x_vt_fg_blue(style)         x_vt_fg_color(style, vt_fg_blue)
#define x_vt_fg_magenta(style)      x_vt_fg_color(style, vt_fg_magenta)
#define x_vt_fg_cyan(style)         x_vt_fg_color(style, vt_fg_cyan)
#define x_vt_fg_white(style)        x_vt_fg_color(style, vt_fg_white)

#define x_vt_bg_color(style, color) (style = ((style & vt_bg_mask) | color))
#define x_vt_bg_black(style)        x_vt_bg_color(style, vt_bg_black)
#define x_vt_bg_red(style)          x_vt_bg_color(style, vt_bg_red)
#define x_vt_bg_green(style)        x_vt_bg_color(style, vt_bg_green)
#define x_vt_bg_yellow(style)       x_vt_bg_color(style, vt_bg_yellow)
#define x_vt_bg_blue(style)         x_vt_bg_color(style, vt_bg_blue)
#define x_vt_bg_magenta(style)      x_vt_bg_color(style, vt_bg_magenta)
#define x_vt_bg_cyan(style)         x_vt_bg_color(style, vt_bg_cyan)
#define x_vt_bg_white(style)        x_vt_bg_color(style, vt_bg_white)

#define x_vt_is_fg(style)           ((style & vt_foreground) != 0)
#define x_vt_is_bg(style)           ((style & vt_background) != 0)
#define x_vt_fg_index(style)        ((style & vt_foreground) >> 16)
#define x_vt_bg_index(style)        ((style & vt_background) >> 24)

#define x_vt_is_fg_black(style)     x_vt_is_style(style, vt_fg_black)
#define x_vt_is_fg_red(style)       x_vt_is_style(style, vt_fg_red)
#define x_vt_is_fg_green(style)     x_vt_is_style(style, vt_fg_green)
#define x_vt_is_fg_yellow(style)    x_vt_is_style(style, vt_fg_yellow)
#define x_vt_is_fg_blue(style)      x_vt_is_style(style, vt_fg_blue)
#define x_vt_is_fg_magenta(style)   x_vt_is_style(style, vt_fg_magenta)
#define x_vt_is_fg_cyan(style)      x_vt_is_style(style, vt_fg_cyan)
#define x_vt_is_fg_white(style)     x_vt_is_style(style, vt_fg_white)
#define x_vt_is_bg_black(style)     x_vt_is_style(style, vt_bg_black)
#define x_vt_is_bg_red(style)       x_vt_is_style(style, vt_bg_red)
#define x_vt_is_bg_green(style)     x_vt_is_style(style, vt_bg_green)
#define x_vt_is_bg_yellow(style)    x_vt_is_style(style, vt_bg_yellow)
#define x_vt_is_bg_blue(style)      x_vt_is_style(style, vt_bg_blue)
#define x_vt_is_bg_magenta(style)   x_vt_is_style(style, vt_bg_magenta)
#define x_vt_is_bg_cyan(style)      x_vt_is_style(style, vt_bg_cyan)
#define x_vt_is_bg_white(style)     x_vt_is_style(style, vt_bg_white)

bool x_vt_init(size_t len);
bool x_vt_uninit();

void x_vt_cursor_home(size_t x, size_t y);
void x_vt_cursor_up(size_t x);
void x_vt_cursor_down(size_t x);
void x_vt_cursor_forward(size_t x);
void x_vt_cursor_backward(size_t x);
void x_vt_cursor_save();
void x_vt_cursor_unsave();
void x_vt_cursor_hide();
void x_vt_cursor_show();
#define x_vt_cursor_position(x, y)  x_vt_cursor_home(x, y)

void x_vt_cls();
void x_vt_cll();

void x_vt_printf(const char* string, const vt_style style);


#endif /* x_vt100 */
