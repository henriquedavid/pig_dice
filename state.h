//#include <iostream>

namespace gm{
	struct Estado
	{
		using names = std::string;

		names jogador_rodada;

		void setJogador(pl::Player jogador){
			jogador_rodada = jogador.getNome();
		}

		names getJogador(){
			return jogador_rodada;
		}


	};
}
/*

int main(){

	gm::Estado estado;



	return 0;
}*/