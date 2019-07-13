#include <string>
#include "../../include/devCard/devCard.h"
using namespace std;

//constructor 
DevCard::DevCard(){}

//destructor
DevCard::~DevCard(){}

//wrapper method that calls useCard() method,
void DevCard::playCard(){
	//useCard();
}

string DevCard::getName() const{
	return name;
}