
#include "vars.h"

size_t strlen( const char *str )
{
	size_t ret = 0;

	while( str[ret] != 0 )
		ret++;

	return ret;
}

uint8_t atoi( char *str )
{
    uint8_t res = 0;
 
    for ( uint8_t x = 0; str[x] != '\0'; ++x )
        res = res * 10 + str[x] - '0';
 
    return res;
}
