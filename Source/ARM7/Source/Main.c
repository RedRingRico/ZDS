#include <nds.h>
#include <dswifi7.h>
#include <maxmod7.h>

volatile bool g_Quit = false;

void VBlankHandler( void )
{
	Wifi_Update( );
}

void VCountHandler( )
{
	inputGetAndSend( );
}

void PowerButtonCB( )
{
	g_Quit = true;
}

int main( void )
{
	readUserSettings( );

	irqInit( );
	initClockIRQ( );
	fifoInit( );

	mmInstall( FIFO_MAXMOD );

	SetYtrigger( 80 );

	installWifiFIFO( );
	installSoundFIFO( );

	installSystemFIFO( );

	irqSet( IRQ_VCOUNT, VCountHandler );
	irqSet( IRQ_VBLANK, VBlankHandler );

	irqEnable( IRQ_VBLANK | IRQ_VCOUNT | IRQ_NETWORK );
	
	setPowerButtonCB( PowerButtonCB );

	while( !g_Quit )
	{
		if ( 0 == ( REG_KEYINPUT &
			( KEY_SELECT | KEY_START | KEY_L | KEY_R ) ) )
		{
			g_Quit = true;
		}
		swiWaitForVBlank( );
	}
	return 0;
}
