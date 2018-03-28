#include <iostream>
#include <string>
#include <vector>
#include <random>
#include <iomanip>
#include <iterator>

void passUser();

using names = std::string;
typedef std::string action;

#include "player.h"
#include "state.h"
#include "dice.h"
#include "pontuations.h"

namespace gs{
	struct GameState
	{

		typedef size_t face_t;
		typedef size_t seed_t;

		enum class seed_type_e : short int { RANDOM = 0, CLIENT_DEFINED};

		pl::Player player1;
		pl::Player player2;

		pd::Dice dice;

		pt::Pontos pontos_game;

		gm::Estado estado_game;


		int state_game = -1;	// 0 - Inicia | 1 - Jogador 1 | 2 - Jogador 2 | 3 - Game Over
		

		// Recebe qual o estado atual do jogo
		void stateGame(){

			int pontA, pontB;

			pontA = pontos_game.getPont_J1();
			pontB = pontos_game.getPont_J2();

			if(pontA < 100 && pontB < 100){
				state_game = 1;
			} else{
				state_game = 3;
			}

		}

		// Modifica o estado do jogo
		void changeState( int estado_muda ){
			state_game = estado_muda;
		}

		// Adiciona pontos a um determinado jogador
		void addPoints(pl::Player &pl, int ponto){
			pontos_game.addPoint(pl, ponto);
		}

		// Adiciona os pontos de cada rodada de todos os 2 jogadores
		void add_pontos_all(int p1, int p2){
			pontos_game.setPontos(p1, p2);
		}

		// Joga o dado.
		int rollDice(){
			return dice.roll();
		}

		// Muda o jogador.
		void passUser(){
			names jog = estado_game.getJogador();

			if(jog == player1.getNome())
				estado_game.setJogador( player2 );
			else
				estado_game.setJogador( player1 );


		}

		// Atribui uma ação, rolar ou passar a vez.
		void action_Game( std::string acao ){
			if(acao == "Roll"){
				int value = rollDice();

				std::cout << "Valor : " << value << std::endl;
				auto nomeJogador = estado_game.getJogador();

				if(nomeJogador == player1.getNome()){
					player1.addPontuacao(value);
				} else{
					player2.addPontuacao(value);
				}

				if(value == 1){
					passUser();
				}

			} else if( acao == "Hold") {

				passUser();

			} else{
				std::cout << "\nA ação não é válida!" << std::endl;
				std::cout <<"Roll or Hold ?" << std::endl;
				std::string valor;
				std::cin >> valor;
				action_Game(valor);
			}
		}

	};
}

void render( gs::GameState &game){
	int tam_total = game.player1.getNome().size() + 22;
	std::cout << "+" << std::setw(tam_total) << std::setfill('-') << "+" << std::endl;
	std::cout << " " << "Jogador" << std::setprecision(10) << std::setw(20) << std::setfill(' ') << "Placar" << std::endl;
	std::cout << " " << game.player1.getNome() << std::setw(17) << std::setfill(' ') << game.pontos_game.getPont_J1() << std::endl;
	std::cout << " " << game.player2.getNome() << std::setw(14) << std::setfill(' ') << game.pontos_game.getPont_J2() << std::endl;
	std::cout << "+" << std::setw(tam_total) << std::setfill('-') << "+" << std::endl;
}

void process_events( gs::GameState &gameStart){
	std::string recebe_acao = "Roll";

	std::cout << std::endl;

	std::cout << "Roll or Hold?" << std::endl;
	
	if( gameStart.estado_game.getJogador() == gameStart.player1.getNome() ){
	
		std::cin >> recebe_acao;
		
	}

	gameStart.action_Game(recebe_acao);

	std::cout << std::endl;

}

void initialize_game( gs::GameState &gameStart){

	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);

	gameStart.dice.set_dice( 6, pd::Dice::seed_type_e::CLIENT_DEFINED, 1);
	gameStart.estado_game.setJogador(gameStart.player1);

	gameStart.changeState( 0 );
}

int game_over( gs::GameState &gameStart){

	gameStart.stateGame();

	return gameStart.state_game;
}

void render_welcome_msg( gs::GameState &gameStart){

	std::cout << " > > > > >   PIG DICE   < < < < < \n" << std::endl;

	std::string nome;

	std::cout << "Insira o nome do primeiro jogador: " << std::endl;
	std::cin >> nome;

	gameStart.player1.player_info(nome, "Humano");
	gameStart.player2.player_info("John The IA", "IA");

	std::cout <<  std::endl;

	std::cout << "# # #		Let the games begin		# # #\n\n";

	std::cout << "INFORMAÇÕES SOBRE O JOGO\n" << std::endl;

	std::cout << "\nJogador 1: " << gameStart.player1.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J1() << "\n\n" 
			  << "Jogador 2: " << gameStart.player2.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J2() << std::endl;


    std::cout << ">>> Jogador " << gameStart.estado_game.getJogador();
}

void render_winner( gs::GameState &gameStart ){
	std::string nomeJWinner;
	nomeJWinner = gameStart.estado_game.getJogador();
	std::cout << "\n\n>>>>>>    TEMOS UM VENCEDOR    <<<<<<\n";
	std::cout << "Vencedor:" << nomeJWinner << std::endl;
	std::cout << "Ganhou com " ;

	if( nomeJWinner == gameStart.player1.getNome())
		std::cout << gameStart.pontos_game.getPont_J1();
	else
		std::cout << gameStart.pontos_game.getPont_J2();

	std::cout << " pontos." << std::endl;

	std::cout << "Valores inseridos por " << gameStart.player1.getNome() << std::endl;
	std::cout << " [ ";
	std::vector<int> v1;
	std::vector<int> v2;
	v1 = gameStart.pontos_game.getL1();
	v2 = gameStart.pontos_game.getL2();
	std::copy( v1.begin(), v1.end(), std::ostream_iterator<int>( std::cout, " "));
	std::cout << "]" << std::endl;

	std::cout << "Valores inseridos por " << gameStart.player2.getNome() << std::endl;	
	std::cout << " [ ";
	std::copy( v2.begin(), v2.end(), std::ostream_iterator<int>( std::cout, " "));
	std::cout << "]" << std::endl;
}

void update( gs::GameState &gameStart){

	int pont_jogador_1 = gameStart.player1.getPontuacao();
	int pont_jogador_2 = gameStart.player2.getPontuacao();

	gameStart.pontos_game.addPont_J1(pont_jogador_1);
	gameStart.pontos_game.addPont_J2(pont_jogador_2);

	gameStart.add_pontos_all(pont_jogador_1, pont_jogador_2);

	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);


}


int main( void ){

	gs::GameState gas;

	initialize_game( gas );

	render_welcome_msg(gas);

	while( game_over( gas ) != 3){
		process_events( gas );
		update( gas );
		render( gas );
	}

	render_winner( gas );

	/*auto estado1 = gas.stateGame();

	std::cout << "O estado atual do jogo é " << estado1 << std::endl
	 	 	  << "O nome do jogador 1 é " << gas.player1.getNome() << std::endl
	 	 	  << "O jogador 2 é " << gas.player2.getNome() << std::endl
	 	 	  << "O primeiro é " << gas.player1.getTipo() << " e o segundo " << gas.player2.getTipo() << std::endl;
	

	for( auto i(0); i < 10; i++){
		std::cout << "Jogador Atual: " << gas.estado_game.getJogador() << std::endl;
		gas.passUser();
	}*/

	return 0;
}