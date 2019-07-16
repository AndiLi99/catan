#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "textDisplayObserver.h"
#include "gameState.h"

using namespace std;

TextDisplay::TextDisplay(GameState* gameState): subject{gameState}{
    gameState->attach(this);
}


vector<int> numberGen(){
	vector<int> placeHolder;
	for (int i = 0; i < 19; i++){
		placeHolder.push_back(i);
	}

	return placeHolder;
}

vector<char> charGen(){
	vector <char> placeHolder;
	for (int i = 0; i<19; i++){
		placeHolder.push_back('B');
	}
	return placeHolder;
}
//prints out reference board with fixed co-ordinates and legend for players to use

vector<string> vertexGen(){
	vector <string> placeHolder;
	for (int i = 0; i < 54; i++){
		if (1){
			string temp = "(*)";
			placeHolder.push_back(temp);
		}
		else{
			string temp = "[*]";
			placeHolder.push_back(temp);
		}
	}
	return placeHolder;

}

vector<char> roadGen(){
	vector<char> placeHolder;
	for (int i = 0; i < 72; i++){
		placeHolder.push_back('*');
	}
	return placeHolder;
}

void TextDisplay::printCoordBoard(){
	cout<< "=========================================="<<endl;
	cout<<"            ( )     ( )     ( )                         -------------------------"<<endl;
	cout<<"          / / \\ \\ / / \\ \\ / / \\ \\                       Legend:"<<endl;
	cout<<"        ( )     ( )     ( )     ( )"<<endl;
	cout<<"        | |+0,+2| |+1,+1| |+2,+0| |"<<endl;
	cout<<"        ( )     ( )     ( )     ( )                     *: place holder"<<endl;
	cout<<"      / / \\ \\ / / \\ \\ / / \\ \\ / / \\ \\                   *-* place holder for resource & number Ex. B04 (Brick04)"<<endl;
	cout<<"    ( )     ( )     ( )     ( )     ( )                 (*) place holder for settlement"<<endl;
	cout<<"    | |-1,+2| |+0,+1| |+1,+0| |+2,-1| |                 [*] place holder for city"<<endl;
	cout<<"    ( )     ( )     ( )     ( )     ( )                 ( ) empty spot for settlement"<<endl;
	cout<<"  / / \\ \\ / / \\ \\ / / \\ \\ / / \\ \\ / / \\ \\"<<endl;
	cout<<"( )     ( )     ( )     ( )     ( )     ( )             /*/"<<endl;
	cout<<"| |-2,+2| |-1,+1| |+0,+0| |+1,-1| |+2,-2| |             |*| Place holder for roads"<<endl;
	cout<<"( )     ( )     ( )     ( )     ( )     ( )             \\*\\"<<endl;
	cout<<" \\ \\  / / \\ \\ / / \\ \\ / / \\ \\ / / \\ \\ / /"<<endl;
	cout<<"    ( )     ( )     ( )     ( )     ( )                 / /"<<endl;
	cout<<"    | |-2,+1| |-1,+0| |+0,-1| |+1,-2| |                 | |  Empty roads"<<endl;
	cout<<"    ( )     ( )     ( )     ( )     ( )                 \\ \\"<<endl;
	cout<<"      \\ \\ / / \\ \\ / / \\ \\ / / \\ \\ / /"<<endl;
	cout<<"        ( )     ( )     ( )     ( )                     1, 2, 3, 4 : Player tokens"<<endl;
	cout<<"        | |-2,+0| |-1,-1| |+0,-2| |                     -------------------------"<<endl;
	cout<<"        ( )     ( )     ( )     ( )"<<endl;
	cout<<"          \\ \\ / / \\ \\ / / \\ \\ / /"<<endl;
	cout<<"            ( )     ( )     ( )"<<endl;
	cout<< "=========================================="<<endl;
}

void TextDisplay::printBoard(){
	vector<int> boardNum = numberGen();
	vector<char> Letter = charGen();
	vector<string> vertices = vertexGen();
	vector<char> roads = roadGen();

	cout<< "=========================================="<<endl;
	//
	cout << "            "<<vertices[0]<<"     "<<vertices[1]<<"     "<<vertices[2]<<endl;
	cout << "          /"<<roads[0]<<"/ \\"<<roads[1]<<"\\ /"<<roads[2]<<"/ \\"<<roads[3]<<"\\ /"<<roads[4]<<"/ \\"<<roads[5]<<"\\"<<endl;

	cout << "        "<<vertices[3]<<"     "<<vertices[4]<<"     "<<vertices[5]<<"     "<<vertices[6]<<endl;

	cout << "        |"<<roads[6]<<"| "<<Letter[0]<<setw(2)<<setfill('0')<<boardNum[0]<<" |"<<roads[7]<<"| "
							<<Letter[1]<<setw(2)<<setfill('0')<<boardNum[1]<<" |"<<roads[8]<<"| "
								<<Letter[2]<<setw(2)<<setfill('0')<<boardNum[2]<<" |"<<roads[9]<<"|"<<endl;

	cout << "        "<<vertices[7]<<"     "<<vertices[8]<<"     "<<vertices[9]<<"     "<<vertices[10]<<endl;

	cout << "      /"<<roads[10]<<"/ \\"<<roads[11]<<"\\ /"<<roads[12]<<"/ \\"<<roads[13]<<"\\ /"<<roads[14]<<"/ \\"<<roads[15]<<"\\ /"<<roads[16]<<"/ \\"<<roads[17]<<"\\"<<endl;

	cout << "    "<<vertices[11]<<"     "<<vertices[12]<<"     "<<vertices[13]<<"     "<<vertices[14]<<"     "<<vertices[15]<<endl;

	cout << "    |"<<roads[18]<<"| "<<Letter[3]<<setw(2)<<setfill('0')<<boardNum[3]<<" |"<<roads[19]<<"| "
						<<Letter[4]<<setw(2)<<setfill('0')<<boardNum[4]<<" |"<<roads[20]<<"| "
							<<Letter[5]<<setw(2)<<setfill('0')<<boardNum[5]<<" |"<<roads[21]<<"| "
								<<Letter[6]<<setw(2)<<setfill('0')<<boardNum[6]<<" |"<<roads[22]<<"|"<<endl;

	cout << "    "<<vertices[16]<<"     "<<vertices[17]<<"     "<<vertices[18]<<"     "<<vertices[19]<<"     "<<vertices[20]<<endl;

	cout << "  /"<<roads[23]<<"/ \\"<<roads[24]<<"\\ /"<<roads[25]<<"/ \\"<<roads[26]<<"\\ /"<<roads[27]<<"/ \\"<<roads[28]<<"\\ /"<<roads[29]<<"/ \\"<<roads[30]<<"\\ /"<<roads[31]<<"/ \\"<<roads[32]<<"\\"<<endl;

	cout << ""<<vertices[21]<<"     "<<vertices[22]<<"     "<<vertices[23]<<"     "<<vertices[24]<<"     "<<vertices[25]<<"     "<<vertices[26]<<endl;

	cout << "|"<<roads[33]<<"| "<<Letter[7]<<setw(2)<<setfill('0')<<boardNum[7]<<" |"<<roads[34]<<"| "
					<<Letter[8]<<setw(2)<<setfill('0')<<boardNum[8]<<" |"<<roads[35]<<"| "
						<<Letter[9]<<setw(2)<<setfill('0')<<boardNum[9]<<" |"<<roads[36]<<"| "
							<<Letter[10]<<setw(2)<<setfill('0')<<boardNum[10]<<" |"<<roads[37]<<"| "<<
								Letter[11]<<setw(2)<<setfill('0')<<boardNum[11]<<" |"<<roads[38]<<"|"<<endl;

	cout << ""<<vertices[27]<<"     "<<vertices[28]<<"     "<<vertices[29]<<"     "<<vertices[30]<<"     "<<vertices[31]<<"     "<<vertices[32]<<endl;

	cout << " \\"<<roads[39]<<"\\  /"<<roads[40]<<"/ \\"<<roads[41]<<"\\ /"<<roads[42]<<"/ \\"<<roads[43]<<"\\ /"<<roads[44]<<"/ \\"<<roads[45]<<"\\ /"<<roads[46]<<"/ \\"<<roads[47]<<"\\ /"<<roads[48]<<"/"<<endl;

	cout << "    "<<vertices[33]<<"     "<<vertices[34]<<"     "<<vertices[35]<<"     "<<vertices[36]<<"     "<<vertices[37]<<endl;

	cout << "    |"<<roads[49]<<"| "<<Letter[12]<<setw(2)<<setfill('0')<<boardNum[12]<<" |"<<roads[50]<<"| "
						<<Letter[13]<<setw(2)<<setfill('0')<<boardNum[13]<<" |"<<roads[51]<<"| "
							<<Letter[14]<<setw(2)<<setfill('0')<<boardNum[14]<<" |"<<roads[52]<<"| "
								<<Letter[15]<<setw(2)<<setfill('0')<<boardNum[15]<<" |"<<roads[53]<<"|"<<endl;

	cout << "    "<<vertices[38]<<"     "<<vertices[39]<<"     "<<vertices[40]<<"     "<<vertices[41]<<"     "<<vertices[42]<<endl;

	cout << "      \\"<<roads[54]<<"\\ /"<<roads[55]<<"/ \\"<<roads[56]<<"\\ /"<<roads[57]<<"/ \\"<<roads[58]<<"\\ /"<<roads[59]<<"/ \\"<<roads[60]<<"\\ /"<<roads[61]<<"/"<<endl;

	cout << "        "<<vertices[43]<<"     "<<vertices[44]<<"     "<<vertices[45]<<"     "<<vertices[46]<<endl;

	cout << "        |"<<roads[62]<<"| "<<Letter[16]<<setw(2)<<setfill('0')<<boardNum[16]<<" |"<<roads[63]<<"| "
							<<Letter[17]<<setw(2)<<setfill('0')<<boardNum[17]<<" |"<<roads[64]<<"| "
								<<Letter[18]<<setw(2)<<setfill('0')<<boardNum[18]<<" |"<<roads[65]<<"|"<<endl;

	cout << "        "<<vertices[47]<<"     "<<vertices[48]<<"     "<<vertices[49]<<"     "<<vertices[50]<<endl;

	cout << "          \\"<<roads[66]<<"\\ /"<<roads[67]<<"/ \\"<<roads[68]<<"\\ /"<<roads[69]<<"/ \\"<<roads[70]<<"\\ /"<<roads[71]<<"/"<<endl;

	cout << "            "<<vertices[51]<<"     "<<vertices[52]<<"     "<<vertices[53]<<endl;
	cout<< "=========================================="<<endl;


}
