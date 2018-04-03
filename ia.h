namespace sys{
	struct IA
	{

		using nome = std::string;

		nome IA_name = "John The IA";

		void setName_IA( nome nm ){
			IA_name = nm;
		}

		nome getName_IA(){
			return IA_name;
		}

		nome jogada_IA( pt::Pontos pontos ){

			float media = 1;

			int pontosTotal = pontos.getTotal_points();

			int pontosIA = pontos.getPont_J2();
			int pontosJ1 = pontos.getPont_J1();

			if( pontosTotal == 0 ){
				pontosTotal = 1;
			}
			
			media = (float) (pontosIA / pontosTotal) * 100;
			


			if( media > 90 ){

				if( pontosIA <= ( pontosJ1 - 10 ) && pontosIA >= ( pontosJ1 + 10 ) )
					return "Roll";

				return "Hold";				

			}  else{
				
				return "Roll";
			}

		}
		
	};
}