#include <nds.h>
#include <stdio.h>

int main( int p_Argc, char **p_ppArgv )
{
	videoSetMode( MODE_0_3D );

	glInit( );

	glClearColor( 4, 0, 4, 31 );
	glClearPolyID( 63 );
	glClearDepth( 0x7FFF );
	
	glViewport( 0, 0, 255, 191 );

	while( 1 )
	{
		scanKeys( );

		if( keysDown( ) & KEY_START )
		{
			break;
		}

		swiWaitForVBlank( );
		glFlush( 0 );
	}

	return 0;
}
