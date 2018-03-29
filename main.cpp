#include <iostream>

#include "funcoes.h"

int main( )
{
	gs::GameState gas;

	initialize_game( gas );
	render_welcome_msg( gas );

	while( game_over( gas ) != 3 ){
		process_events( gas );
		update( gas );
		render( gas );
	}

	render_winner( gas );

	return 0;
}