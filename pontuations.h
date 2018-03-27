/*#include <iostream>
#include <string>
#include <vector>

#include "player.h"*/

namespace pt{
	struct Pontos
	{

		typedef int ponto;
		typedef std::vector<int>  lista;

		lista pontuacoes_jogador1;
		lista pontuacoes_jogador2;


		void addPoint(pl::Player &player, ponto value){
			player.setPontuacao(value);
		}

		void setPontos(int p_jogador1, int p_jogador2){
			pontuacoes_jogador1.push_back(p_jogador1);
			pontuacoes_jogador2.push_back(p_jogador2);
		}
		
	};
}
/*
int main(){

	pl::Player pl;
	pt::Pontos pntos;

	pl.player_info("Henrique", "Humano");
	pntos.addPoint(pl, 10);

	std::cout << "O nome do jogador 1 é " << pl.getNome() << std::endl
			  << "A pontuacao é " << pl.getPontuacao() << std::endl;



	return 0;
}*/