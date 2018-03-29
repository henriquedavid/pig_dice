namespace pt{
	struct Pontos
	{

		// Alias
		typedef int ponto;
		typedef std::vector<int>  lista;

		// Declaracoes
		lista pontuacoes_jogador1;
		lista pontuacoes_jogador2;

		ponto pontuacao_totalJ1 = 0;
		ponto pontuacao_totalJ2 = 0;

		// Métodos

		//	Adicionar pontuacao ao primeiro jogador
		void addPont_J1( ponto valor ){
			pontuacao_totalJ1 += valor;
		}

		// Receber a quantidade de pontos
		int getPont_J1(){
			return pontuacao_totalJ1;
		}

		// Adicionar pontuacao ao segundo jogador
		void addPont_J2( ponto valor ){
			pontuacao_totalJ2 += valor;
		}

		// Receber a pontuacao do segundo jogador
		int getPont_J2(){
			return pontuacao_totalJ2;
		}

		// Adicionar a pontuacao do jogador 1 em uma lista
		void addPointL1(int valor){
			pontuacoes_jogador1.push_back(valor);
		}

		// Adicionar a pontuacao do jogador 2 em uma lista
		void addPointL2( int valor ){
			pontuacoes_jogador2.push_back(valor);
		}

		// Retornar a lista com a pontuacao do 1º jogador
		lista getL1(){
			return pontuacoes_jogador1;
		}

		// Retorna a lista com a pontuacao do 2º jogador
		lista getL2(){
			return pontuacoes_jogador2;
		}
		
	};
}