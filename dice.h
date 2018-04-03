// Arquivo relacionado ao dado.

namespace pd{
	struct Dice{

		// ALIAS
		typedef size_t face_t;
		typedef size_t seed_t;

		enum class seed_type_e : short int { RANDOM = 0, CLIENT_DEFINED};

		std::mt19937 gen;
		std::uniform_int_distribution<int> dis;

		// MÉTODOS
		// Configura o dado
		void set_dice( size_t n_faces = 6, seed_type_e st = seed_type_e::RANDOM, seed_t seed = 1){
			auto my_seed( seed );

			// Verifica se o tipo escolhido é do tipo randomico
			if( st == seed_type_e::RANDOM)
			{
				std::random_device rd;
				gen.seed( rd() );
			}
			else{
				gen.seed( my_seed );
			}

			std::uniform_int_distribution<int>::param_type p( 0, n_faces-1);
			dis.param( p );
		}

		// "Joga" o dado
		face_t roll( void ){
			int value = dis( gen );
			if(value == 0)
				return roll();
			return value;
		}
	};
}