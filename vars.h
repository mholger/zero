#ifndef __VARS_H
#define __VARS_H

#if !defined(__cplusplus)                                      
#include <stdbool.h> /* C doesn't have booleans by default. */
#endif
#include <stddef.h>
#include <stdint.h>

/* Check if the compiler thinks if we are targeting the wrong operating system. */
#if defined(__linux__)
#error "You are not using a cross-compiler, you will most certainly run into trouble"
#endif

/* This tutorial will only work for the 32-bit ix86 targets. */
#if !defined(__i386__)
#error "This tutorial needs to be compiled with a ix86-elf compiler"
#endif

#include "fcns.h"

static const size_t VGA_WIDTH = 80;
static const size_t VGA_HEIGHT = 25;


#ifdef _DEFINE_GLOBALS_

uint8_t		debuglevel = 9; // Maximum logging level to write to logfile
uint8_t		dopause = 1; // Whether or not we need to pause every screenful
uint32_t	throb_delay = (10*7500); // clocks between throbber updates
uint8_t		kdelay = 0; // uS sleep appended by kbhit()
uint8_t		outdelay = 0; // uS delay introduced in console fd
uint8_t		insert = 1; // Character-editing mode, Ins or Ovr

#define __EXTERN__

#else // _DEFINE_GLOBALS_

extern const size_t VGA_WIDTH;
extern const size_t VGA_HEIGHT;

extern unsigned int debuglevel;
extern unsigned int dopause;
extern unsigned long throb_delay;
extern unsigned int kdelay;
extern unsigned int outdelay;
extern unsigned char insert;

#define __EXTERN__ extern

#endif // _DEFINE_GLOBALS

/* Hardware text mode color constants. */
enum vga_color
{
        COLOR_BLACK = 0,
        COLOR_BLUE = 1,
        COLOR_GREEN = 2,
        COLOR_CYAN = 3,
        COLOR_RED = 4,
        COLOR_MAGENTA = 5,
        COLOR_BROWN = 6,
        COLOR_LIGHT_GREY = 7,
        COLOR_DARK_GREY = 8,
        COLOR_LIGHT_BLUE = 9,
        COLOR_LIGHT_GREEN = 10,
        COLOR_LIGHT_CYAN = 11,
        COLOR_LIGHT_RED = 12,
        COLOR_LIGHT_MAGENTA = 13,
        COLOR_LIGHT_BROWN = 14,
        COLOR_WHITE = 15,
};

__EXTERN__ size_t _term_row;
__EXTERN__ size_t _term_col;
__EXTERN__ uint8_t _term_color;
__EXTERN__ uint16_t* _term_buff;

__EXTERN__ ringbuf_t ring;
//__EXTERN__ userrec_t thisuser;

#endif // __VARS_H
