#ifndef __VARDEC_H
#define __VARDEC_H

/* Input ring buffer */
typedef struct ringbuf
{
	int				*buf;	// Actual buffer space
	unsigned int	iptr,	// Pointer to current write location in *buf
					optr,	// Pointer to current read location in *buf
					sz;		// Size of the buffer in (int)'s.
} ringbuf_t;

#define KEY_ARROW_UP	1
#define KEY_ARROW_DOWN	2
#define KEY_ARROW_LEFT	3
#define KEY_ARROW_RIGHT	4
#define KEY_HOME		5
#define KEY_END			6
#define KEY_INS			7
#define KEY_DEL			9

#endif // __VARDEC_H
