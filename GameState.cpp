#include <iostream>
#include <string>

#include "Player.h"
#include "RoundInfo.h"

namespace gs{
	struct GameState
	{

		pyr::Player player_1;
		pyr::Player player_2;

		ri::RoundInfo round;

		std::vector<Jogada> Log_jogadas;

		Score score_total;

		score_total.score_jogador_1 = 0;
		score_total.score_jogador_2 = 0;

		void pontuar(int face, int pontuacao){
			if(round.get_current_player() == player_1.getName()){
				Log_jogadas.insert(face, player_1);
				score_total.score_jogador_1 += face;
			} else{
				Log_jogadas.insert(face, player_2);
				score_total.score_jogador_2 += face;
			}
		}

		

	};

	struct Jogada
	{
		int face_value;
		pyr::Player jogador;
	};


	struct Score
	{
		int score_jogador_1;
		int score_jogador_2;
	};
}

int main(){



	return 0;
}