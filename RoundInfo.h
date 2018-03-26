namespace ri{
	struct RoundInfo
	{
		
		typedef std::string texto;
		typedef int dice_face;

		texto current_turn;
		texto current_player;
		dice_face current_face;

		texto get_Current_player(){
			return current_player;
		}

	};
}