#include <stdlib.h>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include "menu.h"
#include "menuController.h"
using namespace std;


int main(){
	MenuController controller;
	Menu menu{&controller};

	menu.printMenu();
	string input;
	while(getline(cin, input)){
		menu.printMenu();
		menu.parse(input);
	}
}
