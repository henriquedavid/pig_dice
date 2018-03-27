#include <random>
#include <iostream>

#include "pig_dice.h"

using namespace pd;

int main( void )
{
	pd::GameState gs;

	initialize_game( gs );
	render_welcome_msg( gs );

	while( game_over( gs ) != 3 ){
		process_events( gs );
		update( gs );
		render( gs );
	}

	render_winner( gs );

	return 0;
}