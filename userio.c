
#include "vars.h"

size_t strlenstrip( const char *str )
{
	uint8_t x, ret;

	ret = 0;
	for( x = 0; x < strlen( str ); x++ )
	{
		if( str[x] == '|' )
		{
			if((( str[x+1] >= '0' && str[x+1] <= '1' ) && ( str[x+2] >= '0' && str[x+2] <= '9' )) || (( str[x+1] == 'b' || str[x+1] == 'B' ) && (( str[x+2] >= '0' && str[x+2] <= '9' ) || (( str[x+2] >= 'a' && str[x+2] <= 'f' ) || ( str[x+2] >= 'A' && str[x+2] <= 'F' )))))

			{
				x += 2;
				continue;
			}
		}
		else if( str[x] == '\n' ) {
			continue;
		}
		ret++;
	}

	return ret;
}

void kprint( const char *str )
{
	uint8_t x, fg = 7, bg = 0;
	uint8_t next_escaped = 0;
	char buf[2];
	
	for( x = 0; x < strlen( str ); x++ )
	{
		if( str[x] == '\\' && !next_escaped )
		{
			next_escaped = 1;
			continue;
		}
		if( str[x] == '|' && !next_escaped )
		{
			buf[0] = 0;
			buf[1] = 0;

			if(( str[x+1] >= '0' && str[x+1] <= '1' ) && ( str[x+2] >= '0' && str[x+2] <= '9' ))
			{
				buf[0] = str[x+1];
				buf[1] = str[x+2];
				fg = atoi( buf );
				setcolor( fg | bg<<4 );
				x += 2;
				continue;
			}
			else if(( str[x+1] == 'B' || str[x+1] == 'b' ) && (( str[x+2] >= '0' && str[x+2] <= '9' ) || ( str[x+2] >= 'a' && str[x+2] <= 'f' ) || ( str[x+2] >= 'A' && str[x+2] <= 'F' ))) {

				if( str[x+2] >= '0' && str[x+2] <= '9' )
					bg = str[x+2] - '0';

				if( str[x+2] >= 'A' && str[x+2] <= 'F' )
					bg = ( str[x+2] - 'A' ) + 10;

				if( str[x+2] >= 'a' && str[x+2] <= 'f' )
					bg = ( str[x+2] - 'a' ) + 10;

				setcolor( fg | bg << 4 );
				x += 2;
				continue;
			}
		}
		next_escaped = 0;
		putchar( str[x] );
	}
}
