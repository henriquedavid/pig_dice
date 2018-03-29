namespace pt{
	struct Pontos
	{

		typedef int ponto;
		typedef std::vector<int>  lista;

		lista pontuacoes_jogador1;
		lista pontuacoes_jogador2;

		ponto pontuacao_totalJ1 = 0;
		ponto pontuacao_totalJ2 = 0;

		void addPont_J1( ponto valor ){
			pontuacao_totalJ1 += valor;
		}

		int getPont_J1(){
			return pontuacao_totalJ1;
		}

		void addPont_J2( ponto valor ){
			pontuacao_totalJ2 += valor;
		}

		int getPont_J2(){
			return pontuacao_totalJ2;
		}


		void addPoint(pl::Player &player, ponto value){
			player.setPontuacao(value);
		}

		/*
		void setPontos(int p_jogador1, int p_jogador2){
			pontuacoes_jogador1.push_back(p_jogador1);
			pontuacoes_jogador2.push_back(p_jogador2);
		}*/

		void addPointL1(int valor){
			pontuacoes_jogador1.push_back(valor);
		}

		void addPointL2( int valor ){
			pontuacoes_jogador2.push_back(valor);
		}

		lista getL1(){
			return pontuacoes_jogador1;
		}

		lista getL2(){
			return pontuacoes_jogador2;
		}
		
	};
}