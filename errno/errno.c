#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <limits.h>

#define RET_SUCCESS    0
#define RET_ERROR      1

int main(int argc, char ** argv)
{
	int ret=RET_SUCCESS;

	if ( argc < 2 )
	{
		fprintf( stderr,
			"error: Too few arguments\n"
			"\n"
			"Usage: %s n[-n] ...\n"
			" n: errno number\n"
			, argv[0] );
		exit(0x4);
	}


	for( int i=1 ; i<argc ; i++ )
	{
		char *end_char;
		long value_begin, value_end;

		errno=0;
		value_begin=strtol( argv[i], &end_char, 10 );
		int strtol_errno=errno;

		value_end=value_begin;

		if( *end_char == '-' && *(end_char+1) != '\0' )		// range (e.g 12-30)
		{
			value_end=strtol( end_char+1, &end_char, 10 );
		}

		if( *end_char )
		{
			fprintf( stderr, "error: Argument %d: non-digit characters detected\n", i);
			fprintf( stderr, "error:   %s\n", argv[i] );
			fprintf( stderr, "error:   %*c\n", (int)(end_char-argv[i])+1, '^' );
			ret=RET_ERROR;
		}
		else
		{
			if ( strtol_errno == ERANGE || value_begin < INT_MIN || value_begin > INT_MAX || value_end < INT_MIN || value_end > INT_MAX )
			{
				fprintf( stderr, "error: Argument %d `%s': numeric value out of range\n", i, argv[i]);
				ret=RET_ERROR;
			}
			else if ( value_begin > value_end )
			{
				fprintf( stderr, "error: First number in range is larger than second: '%s'\n", argv[i] );
			}
			else
			{
				for( long i=value_begin ; i<=value_end ; i++)
					printf( "%3ld --> %s\n", i, strerror((int)i) );
			}
		}
	}

	return ret;
}
