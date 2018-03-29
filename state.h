namespace gm{
	struct Estado
	{
		// Alias
		using names = std::string;

		// Declaracoes
		names jogador_rodada;

		// Métodos

		// Muda o jogador da partida.
		void setJogador(pl::Player jogador){
			jogador_rodada = jogador.getNome();
		}

		// Retorna o jogador da rodada.
		names getJogador(){
			return jogador_rodada;
		}

	};
}