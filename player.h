//#include <iostream>
//#include <string>

int rollDice();

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
/*
using namespace pl;

int main(){

	pl::Player play;

	std::string nome;

	std::cout << "Insira o nome do jogador: " << std::endl;
	std::cin >> nome;

	play.player_info(nome, "Humano");

	auto nome1 = play.getNome();
	auto tipo = play.getTipo();

	std::cout << " ------------------- ------------------------" << std::endl;
	std::cout << "O nome do jogador é " << nome1 << " e ele é " << tipo << std::endl;
	return 0;
}*/