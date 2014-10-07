
#ifndef __FCNS_H
#define __FCNS_H

#include "vardec.h"

/* kernel.c */
void kernel_main();

/* term.c */
uint8_t		make_color( uint8_t fg, uint8_t bg );
uint16_t	make_vgaentry( char c, uint8_t color );
void		terminit( void );
void		setcolor( uint8_t color );
void		putcharxy( char c, uint8_t color, size_t x, size_t y );
void		putchar( char c );

/* userio.c  */
size_t		strlenstrip( const char *str );
void		kprint( const char *str );

/* util.c - utility functions */
uint8_t		atoi( char *str );
size_t		strlen( const char* str );

#endif // __FCNS_H
