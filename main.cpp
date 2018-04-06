#include <iostream>

// Inclui todas as bibliotecas e extenções.
#include "funcoes.h"

// Função principal.
int main( )
{
	// Inicia os comendos o jogo.
	gs::GameState gas;

	// Inicia o jogo.
	initialize_game( gas );

	// Apresenta mensagem de boas vindas.
	render_welcome_msg( gas );

	// Cria condição do loop do jogo.
	while( game_over( gas ) ){

		// Processa os eventos informados pelo jogadores.
		process_events( gas );
		// Atualiza as pontuacoes.
		update( gas );
		// Informa o placar do jogo.
		render( gas );
	}

	// Apresenta o jogador do jogo.
	render_winner( gas );

	return 0;
}