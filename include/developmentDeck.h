#ifndef DEVELOPEMENT_DECK
#define DEVELOPEMENT_DECK

//need to fix to account for three types of progress cards

class developmentDeck{
	//private fields
	int knight;//constant to keep track of  knight cards
	int yearOfPlenty;//constant to keep track of year of plenty cards
	int monopoly; //constant to keep track of monopoly cards
	int roadBuilding;
	int vicPoint;//constant to kee track ofvictory point cards

	int cardGenerator();//generate a value 1-3 corresponding to each of the cards
	bool isCardInDeck(int);//checks to see if card draw is valid
	public:
		developmentDeck(int, int, int, int, int);
		~developmentDeck();
		void drawCard();
};

#endif