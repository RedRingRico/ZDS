#include <nds.h>
#include <stdio.h>

int main( void )
{
	touchPosition touch;

	consoleDemoInit( );

	iprintf( "\n\n\tZDS Ver. 0.0.0.1\n");

	while( 1 )
	{
		swiWaitForVBlank( );
		scanKeys( );

		if( keysDown( ) & KEY_START )
		{
			break;
		}
	}

	return 0;
}
