/// Namespace destina as informações dos pontos dos jogadores.

namespace pt{
	struct Pontos
	{

		typedef int ponto;
		typedef std::vector<int>  lista;

		/// Declaração da lista do primeiro jogador
		lista pontuacoes_jogador1;	

		/// Declaração da lista do segundo jogador
		lista pontuacoes_jogador2;	

		/// Controle de pontuação total do jogador 1
		ponto pontuacao_totalJ1 = 0;	

		/// Controle de pontuação total do jogador 2
		ponto pontuacao_totalJ2 = 0;	

		/// Pontuação de suporte
		ponto pontuacao_totalJ1_backup = 0;		

		/// Pontuação de suporte
		ponto pontuacao_totalJ2_backup = 0;		



		/*! 	Adicionar pontuacao ao primeiro jogador\n
			 	/param valor inserido pelo usuario é somado com o atual
		*/
		void addPont_J1( ponto valor ){
			pontuacao_totalJ1 += valor;
		}

		/// 	Receber a quantidade de pontos\n
		///		return pontuacao total do jogador 1
		ponto getPont_J1(){
			return pontuacao_totalJ1;
		}

		///  Atualiza os pontos de backup quando o jogador passa
		///	/param	modifica o valor da pontuação de backup
		void setPont_B1(ponto value){
			pontuacao_totalJ1_backup = value;
		}

		///  Modifica a pontuacao do jogador 1
		/// Modifica a pontuação para ser o valor de backup
		void setPont_J1(){
			pontuacao_totalJ1 = pontuacao_totalJ1_backup;
		}

		///  Adicionar pontuacao ao segundo jogador
		/// /param soma o ponto com os  pontos já existentes
		void addPont_J2( ponto valor ){
			pontuacao_totalJ2 += valor;
		}

		///  Receber a pontuacao do segundo jogador
		/// /return	 retorna a pontuacao total do jogador 2
		ponto getPont_J2(){
			return pontuacao_totalJ2;
		}

		///  Atualiza os pontos de backup quando o jogador passa
		/// /param atualiza o valor de backup do jogador 2
		void setPont_B2(ponto value){
			pontuacao_totalJ2_backup = value;
		}

		/// Modifica a pontuacao do jogador 2
		/// Atualiza o valor total para ser o valor de backup
		void setPont_J2(){
			pontuacao_totalJ2 = pontuacao_totalJ2_backup;
		}

		///	 Adiciona o valor retirado no dado para a lista do jogador 1.
		/// /param recebe o valor retirado no dado pelo jogador 1
		void addPointL1(ponto valor){
			pontuacoes_jogador1.push_back(valor);
		}

		///  Adicionar a pontuacao do jogador 2 em uma lista
		///  /param	valor retirado no dado pelo jogador 2
		void addPointL2( ponto valor ){
			pontuacoes_jogador2.push_back(valor);
		}

		///  Retornar a lista com a pontuacao do 1º jogador
		///  /return lista com todas as jogadas do jogador 1 
		lista getL1(){
			return pontuacoes_jogador1;
		}

		///  Retorna a lista com a pontuacao do 2º jogador
		///  /return lista com todas as jogadas do jogador 1
		lista getL2(){
			return pontuacoes_jogador2;
		}

		/// Retorna qual a soma das pontuacoes dos jogadores
		/// /return retorna a soma das pontuacoes dos jogadores.
		ponto getTotal_points(){
			ponto soma  = pontuacao_totalJ1 + pontuacao_totalJ2;
			return soma;
		}
		
	};
}