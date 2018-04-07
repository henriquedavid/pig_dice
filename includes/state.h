/// Informações do jogo

namespace gm{
	struct Estado
	{

		using names = std::string;

		///  Armazena o nome do jogador da partida.
		names jogador_rodada;	

		/// Muda o jogador da rodada.
		/// /param reveeb o jogador da rodada
		void setJogador(pl::Player jogador){
			jogador_rodada = jogador.getNome();
		}

		///  Retorna o jogador da rodada.
		///  /return infoma o jogador da rodada
		names getJogador(){
			return jogador_rodada;
		}

	};
}