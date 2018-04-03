// Arquivo relacionado as funções principais do jogo

// Função gera o placar do jogo
void render( gs::GameState &game){
	int tam_total = game.player1.getNome().size() + 22;
	std::cout << "+" << std::setw(tam_total) << std::setfill('-') << "+" << std::endl;
	std::cout << " " << "Jogador" << std::setprecision(10) << std::setw(20) << std::setfill(' ') << "Placar" << std::endl;
	std::cout << " " << game.player1.getNome() << std::setw(17) << std::setfill(' ') << game.pontos_game.getPont_J1() << std::endl;
	std::cout << " " << game.player2.getNome() << std::setw(14) << std::setfill(' ') << game.pontos_game.getPont_J2() << std::endl;
	std::cout << "+" << std::setw(tam_total) << std::setfill('-') << "+" << std::endl;
}

//Permite ao jogador escolher entre jogar ou passar
void process_events( gs::GameState &gameStart){

	std::string jogadorAtual = gameStart.estado_game.getJogador();
	std::cout << "JOGADOR ATUAL = " << jogadorAtual << std::endl;

	std::string recebe_acao = "Roll";

	std::cout << std::endl;

	std::cout << "Roll or Hold?" << std::endl;
	
	// Verifica se é o jogador ou a IA Jogadora
	if( gameStart.estado_game.getJogador() == gameStart.player1.getNome() ){
	
		std::cin >> recebe_acao;
		
		
	} else{

		recebe_acao = gameStart.IA_game.jogada_IA(gameStart.pontos_game);
	}

	gameStart.action_Game(recebe_acao);	

	std::cout << std::endl;

}


// Inicializa o jogo
void initialize_game( gs::GameState &gameStart){

	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);

	gameStart.dice.set_dice( 6, pd::Dice::seed_type_e::CLIENT_DEFINED, 1);


	gameStart.estado_game.setJogador(gameStart.player1);

	gameStart.changeState( true );
}

// Verifica se há um ganhador
bool game_over( gs::GameState &gameStart){

	gameStart.stateGame();

	return gameStart.state_game;
}

// Tela de confuguracoes iniciais do jogo
void render_welcome_msg( gs::GameState &gameStart){

	std::cout << " > > > > >   PIG DICE   < < < < < \n" << std::endl;

	std::string nome;

	std::cout << "Insira o nome do primeiro jogador: " << std::endl;
	std::cin >> nome;

	gameStart.player1.player_info(nome, "Humano");
	gameStart.player2.player_info("John The IA", "IA");

	std::cout <<  std::endl;

	std::cout << "# # #		Let the games begin		# # #\n\n";

	std::cout << "INFORMAÇÕES SOBRE O JOGO\n" << std::endl;

	std::cout << "\nJogador 1: " << gameStart.player1.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J1() << "\n\n" 
			  << "Jogador 2: " << gameStart.player2.getNome() << std::endl
			  << "Pontuacao = " << gameStart.pontos_game.getPont_J2() << std::endl;

}

// Resultado do vencedor
void render_winner( gs::GameState &gameStart ){
	std::string nomeJWinner;
	nomeJWinner = gameStart.estado_game.getJogador();
	std::cout << "\n\n>>>>>>    TEMOS UM VENCEDOR    <<<<<<\n";
	std::cout << "Vencedor:  " << nomeJWinner << std::endl;
	std::cout << "Ganhou com " ;

	if( nomeJWinner == gameStart.player1.getNome())
		std::cout << gameStart.pontos_game.getPont_J1();
	else
		std::cout << gameStart.pontos_game.getPont_J2();

	std::cout << " pontos." << std::endl;

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

// Atualiza a pontuacao de cada jogador
void update( gs::GameState &gameStart){

	std::string nome;
	nome = gameStart.estado_game.getJogador();

	std::string jogador1 = gameStart.player1.getNome();

	int lastValue = gameStart.get_lastValue();

	// Só adiciona os pontos se o valor for válido ( diferente de 1 )
	if( lastValue != 1){

		if(nome == jogador1){

			int pont_jogador_1 = gameStart.player1.getPontuacao();
			gameStart.pontos_game.addPont_J1(pont_jogador_1);
			gameStart.pontos_game.addPointL1( pont_jogador_1 );

		} else{

			int pont_jogador_2 = gameStart.player2.getPontuacao();
			gameStart.pontos_game.addPont_J2(pont_jogador_2);
			gameStart.pontos_game.addPointL2( pont_jogador_2 );

		}

	}


	gameStart.player1.setPontuacao(0);
	gameStart.player2.setPontuacao(0);
	
}