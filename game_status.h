namespace gs{
	struct GameState
	{

		// Alias
		using names = std::string;
		typedef size_t face_t;
		typedef size_t seed_t;

		enum class seed_type_e : short int { RANDOM = 0, CLIENT_DEFINED};

		// Declaracoes
		pl::Player player1;		// declara um jogador 1
		pl::Player player2;		// declara jogador 2

		pd::Dice dice;		// declara o jogo

		pt::Pontos pontos_game;		// gerar placar

		gm::Estado estado_game;		// gerar os estados do jogo

		sys::IA IA_game;

		int state_game = true;	// 0 - Inicia | 1 - Jogador 1 | 2 - Jogador 2 | 3 - Game Over

		int ultimo_valor = 0;

		// Métodos

		// Retorna o último valor do dado.
		int get_lastValue(){
			return ultimo_valor;
		}
		
		// Recebe qual o estado atual do jogo
		void stateGame(){

			int pontA, pontB;

			// Recebe a pontuação de cada jogador.
			pontA = pontos_game.getPont_J1();
			pontB = pontos_game.getPont_J2();

			// Verifica se algum jogador atigiu mais/igual 100 pontos.
			if(pontA < 100 && pontB < 100){
				state_game = true;
			} else{
				state_game = false;
			}

		}

		// Modifica o estado do jogo
		void changeState( int estado_muda ){
			state_game = estado_muda;
		}

		// Joga o dado.
		int rollDice(){
			return dice.roll();
		}

		// Muda o jogador.
		void passUser(){
			names jog = estado_game.getJogador();

			// Verifica se o jogador da partida é o 1 ou o 2 e muda o jogador.
			if(jog == player1.getNome())
				estado_game.setJogador( player2 );
			else
				estado_game.setJogador( player1 );
		}

		// Atribui uma ação, rolar ou passar a vez.
		void action_Game( std::string acao ){
			
			// Recupera o jogador da partida.
			auto nomeJogador = estado_game.getJogador();
			

			// Verifica se a ação inserida pelo jogador foi Roll ou Hold
			if(acao == "Roll"){
				// Recebe o valor do dado.
				int value = rollDice();
				// Atribui para o último valor.
				ultimo_valor = value;

				// Informa qual foi o valor.
				std::cout << "Valor : " << value << std::endl;

				// Realiza validação se o jogador tirou 1.
				if( value != 1){
					// Aplica a pontuação para o jogador.
					if(nomeJogador == player1.getNome()){
						player1.addPontuacao(value);
					} else{
						player2.addPontuacao(value);
					}

				} else{
					
					// Configura a pontuação para 0;
					player1.setPontuacao(0);
					player2.setPontuacao(0);

					// Muda o jogador.
					passUser();

				}

			} else if( acao == "Hold") {

				// Configura o valor de backup
				if( nomeJogador == player1.getNome() )
					pontos_game.setPont_B1( pontos_game.getPont_J1() );
				else
					pontos_game.setPont_B2( pontos_game.getPont_J2() );

				// Muda o jogador.
				passUser();

			} else{
				// Solicita ao usuário uma escolha válida.
				std::cout << "\nA ação não é válida!" << std::endl;
				std::cout <<"Roll or Hold ?" << std::endl;
				std::string valor;
				std::cin >> valor;
				action_Game(valor);
			}
		}

	};
}