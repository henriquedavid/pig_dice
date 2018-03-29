#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <iterator>

#include "player.h"
#include "state.h"
#include "dice.h"
#include "pontuations.h"
#include "game_status.h"
#include "functions_main.h"

void passUser();
int rollDice();

using names = std::string;
typedef std::string action;

void render( gs::GameState& );
void process_events( gs::GameState& );
void initialize_game( gs::GameState& );
int game_over( gs::GameState& );
void render_welcome_msg( gs::GameState& );
void render_winner( gs::GameState& );
void update( gs::GameState&	 );