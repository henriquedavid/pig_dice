namespace pyr{
	struct Player
	{
		typedef std::string texto;
		typedef std::string action_t;

		texto name;
		texto tipo;

		action_t action(action_t jogada){		// Roll or Holl

			if(jogada == "Roll"){

			} else{

			}

			return jogada;
		}

		void addInfo(texto nome, texto tipo_jogador){
			name = nome;
			tipo = tipo_jogador;
		}

		texto getName(){
			return name;
		}
	};
}