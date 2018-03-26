#include <iostream>
#include <cstdlib>
#include <random>
#include <string>

#include "Dice.h"
#include "Player.h"
#include "GameState.h"

int main( void ){

	pd::GameStatus gs;

	initialize_game( gs );

	render_welcome_msg( gs );

	while( not gameover( gs ) ){

		process_events( gs );

		update( gs );

		render( gs );

	}

	render_winner( gs );

	return 0;
}