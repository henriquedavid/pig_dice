
#include "../includes/funcoes.h" ///< Inclui todas as bibliotecas e extenções.

int main( )		///< Função principal.
{
	gs::GameState gas;  ///< Inicia as informações do jogo.

	initialize_game( gas );  ///< Inicia o jogo.

	render_welcome_msg( gas );  ///< Apresenta mensagem de boas vindas.

	while( game_over( gas ) ){	///< Cria condição do loop do jogo.

		process_events( gas );  ///< Processa os eventos informados pelo jogadores.
		update( gas );  ///< Atualiza as pontuacoes.
		render( gas );  ///< Informa o placar do jogo.
	}

	render_winner( gas );  ///< Apresenta o jogador do jogo.

	return 0;
}