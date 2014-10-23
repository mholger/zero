#include "vars.h"

void create_descriptor( uint32_t base, uint32_t limit, uint16_t flag )
{
	uint64_t descriptor;

	// Set high 32b of segment
	descriptor  =  limit		& 0x000F0000;	// set limit 19:16
	descriptor |= (flag << 8)	& 0x00F0FF00;	// set type, p, dpl, s, g, d/b, l, avl
	descriptor |= (base >> 16)	& 0x000000FF;	// set base 23:16
	descriptor |=  base			& 0xFF000000;	// set base 31:24

	// Shift by 32 to allow for low segment
	descriptor <<= 32;

	// Set low 32b of segment
	descriptor |= base  << 16;					// set base 15:0
	descriptor |= limit  & 0x0000FFFF;			// set limit 15:0
}
