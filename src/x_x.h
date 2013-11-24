#ifndef _X_X_
#define _X_X_

#define x_dump() __builtin_trap() 

#ifdef XDEBUG
#define x_assert(x)  {if (!(x)) x_dump();} 
#else
#define x_assert(x)
#endif /* XDEBUG */

#define x_check(x) {if (!(x)) x_dump();}

typedef unsigned char byte;

#define bool int
#define true 0x1
#define false 0x0

#define x_max(x, y) ((x > y) ? (x) : (y))
#define x_min(x, y) ((x < y) ? (x) : (y))

#endif /* _X_X_ */
