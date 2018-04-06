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

		ponto pontuacao_totalJ1_backup = 0;
		ponto pontuacao_totalJ2_backup = 0;

		// Métodos

		//	Adicionar pontuacao ao primeiro jogador
		void addPont_J1( ponto valor ){
			pontuacao_totalJ1 += valor;
		}

		// Receber a quantidade de pontos
		ponto getPont_J1(){
			return pontuacao_totalJ1;
		}

		// Atualiza os pontos de backup quando o jogador passa
		void setPont_B1(ponto value){
			pontuacao_totalJ1_backup = value;
		}

		// Modifica a pontuacao do jogador 1
		void setPont_J1(){
			pontuacao_totalJ1 = pontuacao_totalJ1_backup;
		}

		// Adicionar pontuacao ao segundo jogador
		void addPont_J2( ponto valor ){
			pontuacao_totalJ2 += valor;
		}

		// Receber a pontuacao do segundo jogador
		ponto getPont_J2(){
			return pontuacao_totalJ2;
		}

		// Atualiza os pontos de backup quando o jogador passa
		void setPont_B2(ponto value){
			pontuacao_totalJ2_backup = value;
		}

		// Modifica a pontuacao do jogador 2
		void setPont_J2(){
			pontuacao_totalJ2 = pontuacao_totalJ2_backup;
		}

		// Adicionar a pontuacao do jogador 1 em uma lista
		void addPointL1(ponto valor){
			pontuacoes_jogador1.push_back(valor);
		}

		// Adicionar a pontuacao do jogador 2 em uma lista
		void addPointL2( ponto valor ){
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

		// Retorna qual a soma das pontuacoes dos jogadores
		ponto getTotal_points(){
			ponto soma  = pontuacao_totalJ1 + pontuacao_totalJ2;
			return soma;
		}
		
	};
}