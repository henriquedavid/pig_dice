//#include <random>
//#include <iostream>

namespace pd{
	struct Dice{

		

		std::mt19937 gen;
		std::uniform_int_distribution<int> dis;

		void set_dice( size_t n_faces = 2, seed_type_e st = seed_type_e::RANDOM, seed_t seed = 1){
			auto my_seed( seed );

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

		face_t roll( void ){
			return dis( gen );
		}

	};
}
/*
using namespace pd;

int main( void ){
	Dice d6;
	Dice coin;

	d6.set_dice( 6, Dice::seed_type_e::CLIENT_DEFINED, 1);
	coin.set_dice( 2 );

	for( auto i(0) ; i < 10 ; ++i)
		std::cout << " face: " << d6.roll() << "\n";

	return 0;
}*/