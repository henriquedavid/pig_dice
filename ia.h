// Arquivo relacionado ao funcionamento da IA do jogo.

namespace sys{
	struct IA
	{

		using nome = std::string;

		nome IA_name = "John The IA";

		// Permite ao jogador configurar um nome para a IA
		void setName_IA( nome nm ){
			IA_name = nm;
		}

		// Recebe o nome da IA
		nome getName_IA(){
			return IA_name;
		}

		// Define as jogadas realizada pela IA.
		nome jogada_IA( pt::Pontos pontos ){

			float media = 1;

			// Recebe os pontos totais.
			int pontosTotal = pontos.getTotal_points();

			// Recebe os pontos dos jogadores.
			int pontosIA = pontos.getPont_J2();
			int pontosJ1 = pontos.getPont_J1();

			// verifica se o total não é nulo.
			if( pontosTotal == 0 ){
				pontosTotal = 1;
			}
			
			// Calcula a media dos pontos da IA e dos pontos totais de ambos jogadores.
			media = (pontosIA*100 / pontosTotal);
			

			// Verifica a média e cria uma árvore de decisão
			if( media > 90 ){

				return "Hold";				

			}  else{


				if( pontosIA <= pontosJ1)
					return "Roll";

				if( media <= 20)
					return "Hold";
				
				if( pontosIA >= (pontosJ1 + 15) )
					return "Hold";

				if(pontosIA >= 25)
					return "Hold";
				
				if( ( pontosJ1 - 20 ) <= pontosIA && pontosIA <= ( pontosJ1 + 20 ) )
					return "Roll";
				
				return "Roll";
			}

		}
		
	};
}