/// Arquivo relacionado as funções principais do jogo

///< Função gera o placar do jogo
void render( gs::GameState &game){

	///< Define o ínicio do placar.
	std::cout << "+" << std::setw(45) << std::setfill('-') << "+" << std::endl;
	
	std::cout << std::setfill(' ');

	std::string nome = game.player1.getNome();

	///< Coloca o cabeçalho no placa
	std::cout << " " << "Jogador" << std::setw(26)  << "Placar" << std::endl;
	///< Coloca as informações do primeiro jogador
	std::cout << " " << game.player1.getNome() << std::setw(31 - nome.size()) << game.pontos_game.getPont_J1() << std::endl;
	///< Coloca as informações do segundo jogador
	std::cout << " " << game.player2.getNome() << std::setw(14) << game.pontos_game.getPont_J2() << std::endl;
	
	///< Define o fim do placar.
	std::cout << "+" << std::setw(45) << std::setfill('-') << "+" << std::endl;
}

///< Permite ao jogador escolher entre jogar ou passar
void process_events( gs::GameState &gameStart){

	///< Recebe qual o jogador atual.
	std::string jogadorAtual = gameStart.estado_game.getJogador();
	///< Infoma qual o jogador que irá jogar.
	std::cout << "JOGADOR ATUAL = " << jogadorAtual << std::endl;

	///< Cria variável que define a ação escolhida pelo jogador.
	std::string recebe_acao = "Roll";

	std::cout << std::endl;

	///< Pergunta ao jogador se ele deseja jogar o dado ou passar a vez
	std::cout << "Roll or Hold?" << std::endl;
	
	///< Verifica se é o jogador ou a IA Jogadora
	if( gameStart.estado_game.getJogador() == gameStart.player1.getNome() ){
	
		///< O usuário ( jogador 1 ) infoma o que ele deseja fazer.
		std::cin >> recebe_acao;
		
		
	} else{

		///< A IA gera a escolha.
		recebe_acao = gameStart.IA_game.jogada_IA(gameStart.pontos_game);
		///< Imprime na tela qual foi a escolha da IA.
		std::cout << recebe_acao << std::endl;
	}

	///< Aplica a acao desejada pelo jogador no jogo.
	gameStart.action_Game(recebe_acao);	

	std::cout << std::endl;	///< Quebra de linha para organização visual.

}


///< Inicializa o jogo
void initialize_game( gs::GameState &gameStart){

	///< Informa que os jogadores começam com a pontuação zerada.
	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);

	gameStart.pontos_game.setPont_B1( gameStart.pontos_game.getPont_J1() );
	gameStart.pontos_game.setPont_B2( gameStart.pontos_game.getPont_J2() );

	gameStart.pontos_game.setPont_B1(0);
	gameStart.pontos_game.setPont_B2(0);

	///< Configura o dado.
	gameStart.dice.set_dice( 6, pd::Dice::seed_type_e::CLIENT_DEFINED, 1);

///< Muda o estado do jogo para verdadeiro / vai começar.
	gameStart.changeState( true );
}

///< Verifica se há um ganhador
bool game_over( gs::GameState &gameStart){

	///< verifica o estado do jogo.
	gameStart.stateGame();

	///< retorna o estado do jogo.
	return gameStart.state_game;
}

///< Tela de confuguracoes iniciais do jogo
void render_welcome_msg( gs::GameState &gameStart){


	std::cout << " > > > > >   PIG DICE   < < < < < \n" << std::endl;

	std::string nome;

	///< Solicita ao usuário para informar o nome.
	std::cout << "Insira o nome do primeiro jogador: " << std::endl;
	std::cin >> nome;

	///< Aplica as informações referentes aos jogadores.
	gameStart.player1.player_info(nome, "Humano");
	gameStart.player2.player_info("Seu gêmeo malvado", "IA");

	///< Configura o primeiro jogador.
	gameStart.estado_game.setJogador(gameStart.player1);

	std::cout <<  std::endl;  ///< Organização visual do jogo.

	///< Informa que agora o jogo irá começar
	std::cout << "# # #		Let the games begin		# # #\n\n";

	///< Apresenta as informações referentes ao jogo (jogadores e pontuacao inicial).
	std::cout << "INFORMAÇÕES SOBRE O JOGO\n" << std::endl;

	std::cout << "\nJogador 1: " << gameStart.player1.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J1() << "\n\n" 
			  << "Jogador 2: " << gameStart.player2.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J2() << "\n" << std::endl;

}

///< Resultado do vencedor
void render_winner( gs::GameState &gameStart ){

	std::string nomeJWinner;
	///< Verifica qual é o jogador que ganhou a partida
	nomeJWinner = gameStart.estado_game.getJogador();

	///< Apresenta quem foi o vencedor
	std::cout << "\n\n>>>>>>    TEMOS UM VENCEDOR    <<<<<<\n";
	std::cout << "Vencedor:  " << nomeJWinner << std::endl;
	std::cout << "Ganhou com " ;

	///< Verifica quantos pontos o jogador ganhou.
	if( nomeJWinner == gameStart.player1.getNome())
		std::cout << gameStart.pontos_game.getPont_J1();
	else
		std::cout << gameStart.pontos_game.getPont_J2();

	std::cout << " pontos." << std::endl;

	///< Informa quais foram os valores que cada jogador recebeu do dado.
	std::cout << "Valores inseridos por " << gameStart.player1.getNome() << std::endl;
	std::cout << " [ ";
	std::vector<int> v1;
	std::vector<int> v2;
	v1 = gameStart.pontos_game.getL1();
	v2 = gameStart.pontos_game.getL2();
	std::copy( v1.begin(), v1.end(), std::ostream_iterator<int>( std::cout, " "));
	std::cout << "]" << std::endl;

	std::cout << "Valores inseridos por " << gameStart.player2.getNome() << std::endl;	
	std::cout << " [ ";
	std::copy( v2.begin(), v2.end(), std::ostream_iterator<int>( std::cout, " "));
	std::cout << "]" << std::endl;
}

///< Atualiza a pontuacao de cada jogador
void update( gs::GameState &gameStart){

	///< Receb qual o jogador da partida.
	std::string nome;
	nome = gameStart.estado_game.getJogador();

	///< Recebe o nome do primeiro jogador.
	std::string jogador1 = gameStart.player1.getNome();

	///< Recebe qual foi o último valor do dado.
	int lastValue = gameStart.get_lastValue();


	///< Só adiciona os pontos se o valor for válido ( diferente de 1 )
	if( lastValue != 1){

		///< Verifica se o jogador da partida era o jogador 1.
		if(nome == jogador1){

			///< Insere os pontos no vetor e no placar individual do jogador 1.
			int pont_jogador_1 = gameStart.player1.getPontuacao();
			gameStart.pontos_game.addPont_J1(pont_jogador_1);
			gameStart.pontos_game.addPointL1( pont_jogador_1 );

		} else{	///< Verifica se o jogador 2 era o jogador da partida.

			///< Insere os pontos no vetor e no placar individual do jogador 2.
			int pont_jogador_2 = gameStart.player2.getPontuacao();
			gameStart.pontos_game.addPont_J2(pont_jogador_2);
			gameStart.pontos_game.addPointL2( pont_jogador_2 );

		}

	} else{

		///< Retorna os valores para antes do jogador;
		if( nome != jogador1 ){
			gameStart.pontos_game.setPont_J1();
		} else{
			gameStart.pontos_game.setPont_J2();
		}
		

		std::cout << "Você acaba de perder pontos da sua rodada!\n" << std::endl;
	}

	///< Configura os valores dos dados do jogadores para 0 novamente.
	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);

	
}