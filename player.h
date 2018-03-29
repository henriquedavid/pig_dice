namespace pl{
	struct Player
	{
		typedef std::string name;
		typedef size_t pont;
		

		name nome_jogador;
		name tipo_jogador;
		pont pontuacao;

		// Insere informações sobre o jogador
		void player_info(name nome, name tipo){
			nome_jogador = nome;
			tipo_jogador = tipo;
		}

		// Retorna o nome do jogador
		name getNome(){
			return nome_jogador;
		}

		// Retorna o tipo do jogador
		name getTipo(){
			return tipo_jogador;
		}

		// Muda a pontuacao
		void setPontuacao(int valor){
			pontuacao = valor;
		}

		// Adiciona o valor da pontuacao
		void addPontuacao(int valor){
			pontuacao += valor;
		}

		// Retorna a pontuacao
		pont getPontuacao(){
			return pontuacao;
		}

		

	};
}