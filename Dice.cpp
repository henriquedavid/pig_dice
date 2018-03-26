

namespace pd{
	struct Dice
	{
		
		typedef size_t face_t;

		enum seed_e {RANDOM = 0, FIXED_SEED};
		typedef int seed_t;

		std::mt19937 gen;
		std::uniform_int_distribution<int> dis;

		size_t n_faces;

		set_dice(size_t n_faces = 2, seed_e seed_type = RANDOM, seed_t seed = 1){

			auto my_seed( seed );

			if(seed_type == RANDOM){
				std::random_device rd;
				gen.seed( rd() );
			} else{
				gen.seed( my_seed );
			}

			std::uniform_int_distribution<int>::param_type p(0, n_faces - 1);
			dis.param(param_type);
		}

		face_t roll( void ){
			return dis( gen );
		}
	};
}

using namespace pd;

int main(){

	Dice d6;
	d6.set_dice(6, FIXED, 100);

	for(auto i(0) ; i < 10 ; ++i){
		std::cout << "Face: " << d6.roll() << "\n";
	}

	return 0;
}