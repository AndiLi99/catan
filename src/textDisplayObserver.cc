#include <iostream>
#include <vector>
#include <iomanip>
#include <string>
#include "textDisplayObserver.h"
#include "gameState.h"

using namespace std;

TextDisplay::TextDisplay(GameState* gameState): gameState{gameState}{
	cout << "attaching to gamestate" << endl;
    gameState->attach(this);
    hexPrintOrder = gameState->getHexPrintOrder();
    edgePrintOrder = gameState->getEdgePrintOrder();
    vertexPrintOrder = gameState->getVertexPrintOrder();
}

char TextDisplay::getTileType(Hexagon hex){
    const Tile& tile = gameState->cgetTile(hex);
    switch(tile.getType()){
        case TileType::Desert: return 'D';
        case TileType::Hills: return 'B';
        case TileType::Fields: return 'G';
        case TileType::Pasture: return 'S';
        case TileType::Mountains: return 'O';
        case TileType::Forest: return 'L';
    }
}
string TextDisplay::getTileNum(Hexagon hex){
    const Tile& tile = gameState->cgetTile(hex);
    if (tile.getRollNumber() > 0){
        return std::to_string(tile.getRollNumber());
    } else {
        return "";
    }
}

char TextDisplay::getRoad(Edge edge){
    if (gameState->emptyEdge(edge)){
        return ' ';
    } else {
        const Road& road = gameState->cgetRoad(edge);
        return '0' + road.ownedBy();
    }
}

string TextDisplay::getSettlement(Vertex vert){
    if (gameState->emptyVertex(vert)){
        return "( )";
    } else {
        const Settlement& settlement = gameState->cgetSettlement(vert);
        if (settlement.isCity()){
            return "[" + std::to_string(settlement.ownedBy()) + "]";
        } else {
            return "(" + std::to_string(settlement.ownedBy()) + ")";
        }
    }
}

vector<char> TextDisplay::getTileTypes(){
	std::optional<Hexagon> robber = gameState->getRobber();
	vector<char> ret;
	for (Hexagon hex: hexPrintOrder){
		if (robber == hex)
		{
			ret.push_back('R');
		} 
		else 
		{
			ret.push_back(getTileType(hex));
		}
	}
	return ret;
}

vector<string> TextDisplay::getTileNums(){
	vector<string> ret;
	for (Hexagon hex: hexPrintOrder){
		ret.push_back(getTileNum(hex));
	}
	return ret;
}

vector<string> TextDisplay::getSettlements(){
	vector<string> ret;
	for (Vertex vert: vertexPrintOrder){
		ret.push_back(getSettlement(vert));
	}
	return ret;
}

vector<char> TextDisplay::getRoads(){
	vector<char> ret;
	for (Edge edge: edgePrintOrder){
		ret.push_back(getRoad(edge));
	}
	return ret;
}

TextDisplay::~TextDisplay(){
	gameState->detach(this);
}
void TextDisplay::printLastDiceRoll(){
	int lastDiceRoll = gameState->getLastDiceRoll();
	cout << "Last dice roll was: " << lastDiceRoll << endl;
}
void TextDisplay::printResources(){
	vector<int> resources = gameState->getResources();
	string username = gameState->getUsername();
	vector<int> unbuilt = gameState->getUnbuilt();
	int playerID = gameState->getTurnPlayerID();

	cout << username << "(" << playerID << ") has:" <<endl;
	cout << "===================" <<endl;
	cout << resources[0] << " lumber"<<endl;
	cout << resources[1] << " brick"<<endl;
	cout << resources[2] << " grain"<<endl;
	cout << resources[3] << " wool"<<endl;
	cout << resources[4] << " ore"<<endl;
	cout << unbuilt[0] << " unbuilt roads"<<endl;
	cout << unbuilt[1] << " unbuilt settlements"<<endl;
	cout << unbuilt[2] << " unbuilt cities"<<endl;
	cout << "===================" <<endl;
}

void TextDisplay::printVictoryPoints(){
	string username = gameState->getUsername();
	int victoryPoints = gameState->getVictoryPoints();
	int playerID = gameState->getTurnPlayerID();
	cout << username << "(" << playerID << ") has " << victoryPoints <<" victory points." << endl;

}
void TextDisplay::printGame(){
	printCoordBoard();
	printBoard();
	printResources();
	printVictoryPoints();
	printLastDiceRoll();
}
void TextDisplay::notify(){
	printGame();
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
	cout<<endl;
	cout<< "Coordinate System: "<<endl;
	cout<< "      ( )"<<endl;
	cout<< "  N / / \\ \\ E"<<endl;
	cout<< "  ( )     (R)"<<endl;
	cout<< "W | |     | |"<<endl;
	cout<< "  (L)     ( )"<<endl;
	cout<< "    \\ \\ / /"<<endl;
	cout<< "      ( )"<<endl;
	cout<< "=========================================="<<endl;
}

void TextDisplay::printBoard(){
	vector<string> boardNum = getTileNums();
	vector<char> Letter = getTileTypes();
	vector<string> vertices = getSettlements();
	vector<char> roads = getRoads();

	cout<< "=========================================="<<endl;
	//
	cout << "            "<<vertices[0]<<"     "<<vertices[1]<<"     "<<vertices[2]<<endl;
	cout << "          /"<<roads[0]<<"/ \\"<<roads[1]<<"\\ /"<<roads[2]<<"/ \\"<<roads[3]<<"\\ /"<<roads[4]<<"/ \\"<<roads[5]<<"\\"<<endl;

	cout << "        "<<vertices[3]<<"     "<<vertices[4]<<"     "<<vertices[5]<<"     "<<vertices[6]<<endl;

	cout << "        |"<<roads[6]<<"| "<<Letter[0]<<setw(2)<<boardNum[0]<<" |"<<roads[7]<<"| "
							<<Letter[1]<<setw(2)<<boardNum[1]<<" |"<<roads[8]<<"| "
								<<Letter[2]<<setw(2)<<boardNum[2]<<" |"<<roads[9]<<"|"<<endl;

	cout << "        "<<vertices[7]<<"     "<<vertices[8]<<"     "<<vertices[9]<<"     "<<vertices[10]<<endl;

	cout << "      /"<<roads[10]<<"/ \\"<<roads[11]<<"\\ /"<<roads[12]<<"/ \\"<<roads[13]<<"\\ /"<<roads[14]<<"/ \\"<<roads[15]<<"\\ /"<<roads[16]<<"/ \\"<<roads[17]<<"\\"<<endl;

	cout << "    "<<vertices[11]<<"     "<<vertices[12]<<"     "<<vertices[13]<<"     "<<vertices[14]<<"     "<<vertices[15]<<endl;

	cout << "    |"<<roads[18]<<"| "<<Letter[3]<<setw(2)<<boardNum[3]<<" |"<<roads[19]<<"| "
						<<Letter[4]<<setw(2)<<boardNum[4]<<" |"<<roads[20]<<"| "
							<<Letter[5]<<setw(2)<<boardNum[5]<<" |"<<roads[21]<<"| "
								<<Letter[6]<<setw(2)<<boardNum[6]<<" |"<<roads[22]<<"|"<<endl;

	cout << "    "<<vertices[16]<<"     "<<vertices[17]<<"     "<<vertices[18]<<"     "<<vertices[19]<<"     "<<vertices[20]<<endl;

	cout << "  /"<<roads[23]<<"/ \\"<<roads[24]<<"\\ /"<<roads[25]<<"/ \\"<<roads[26]<<"\\ /"<<roads[27]<<"/ \\"<<roads[28]<<"\\ /"<<roads[29]<<"/ \\"<<roads[30]<<"\\ /"<<roads[31]<<"/ \\"<<roads[32]<<"\\"<<endl;

	cout << ""<<vertices[21]<<"     "<<vertices[22]<<"     "<<vertices[23]<<"     "<<vertices[24]<<"     "<<vertices[25]<<"     "<<vertices[26]<<endl;

	cout << "|"<<roads[33]<<"| "<<Letter[7]<<setw(2)<<boardNum[7]<<" |"<<roads[34]<<"| "
					<<Letter[8]<<setw(2)<<boardNum[8]<<" |"<<roads[35]<<"| "
						<<Letter[9]<<setw(2)<<boardNum[9]<<" |"<<roads[36]<<"| "
							<<Letter[10]<<setw(2)<<boardNum[10]<<" |"<<roads[37]<<"| "<<
								Letter[11]<<setw(2)<<boardNum[11]<<" |"<<roads[38]<<"|"<<endl;

	cout << ""<<vertices[27]<<"     "<<vertices[28]<<"     "<<vertices[29]<<"     "<<vertices[30]<<"     "<<vertices[31]<<"     "<<vertices[32]<<endl;

	cout << " \\"<<roads[39]<<"\\  /"<<roads[40]<<"/ \\"<<roads[41]<<"\\ /"<<roads[42]<<"/ \\"<<roads[43]<<"\\ /"<<roads[44]<<"/ \\"<<roads[45]<<"\\ /"<<roads[46]<<"/ \\"<<roads[47]<<"\\ /"<<roads[48]<<"/"<<endl;

	cout << "    "<<vertices[33]<<"     "<<vertices[34]<<"     "<<vertices[35]<<"     "<<vertices[36]<<"     "<<vertices[37]<<endl;

	cout << "    |"<<roads[49]<<"| "<<Letter[12]<<setw(2)<<boardNum[12]<<" |"<<roads[50]<<"| "
						<<Letter[13]<<setw(2)<<boardNum[13]<<" |"<<roads[51]<<"| "
							<<Letter[14]<<setw(2)<<boardNum[14]<<" |"<<roads[52]<<"| "
								<<Letter[15]<<setw(2)<<boardNum[15]<<" |"<<roads[53]<<"|"<<endl;

	cout << "    "<<vertices[38]<<"     "<<vertices[39]<<"     "<<vertices[40]<<"     "<<vertices[41]<<"     "<<vertices[42]<<endl;

	cout << "      \\"<<roads[54]<<"\\ /"<<roads[55]<<"/ \\"<<roads[56]<<"\\ /"<<roads[57]<<"/ \\"<<roads[58]<<"\\ /"<<roads[59]<<"/ \\"<<roads[60]<<"\\ /"<<roads[61]<<"/"<<endl;

	cout << "        "<<vertices[43]<<"     "<<vertices[44]<<"     "<<vertices[45]<<"     "<<vertices[46]<<endl;

	cout << "        |"<<roads[62]<<"| "<<Letter[16]<<setw(2)<<boardNum[16]<<" |"<<roads[63]<<"| "
							<<Letter[17]<<setw(2)<<boardNum[17]<<" |"<<roads[64]<<"| "
								<<Letter[18]<<setw(2)<<boardNum[18]<<" |"<<roads[65]<<"|"<<endl;

	cout << "        "<<vertices[47]<<"     "<<vertices[48]<<"     "<<vertices[49]<<"     "<<vertices[50]<<endl;

	cout << "          \\"<<roads[66]<<"\\ /"<<roads[67]<<"/ \\"<<roads[68]<<"\\ /"<<roads[69]<<"/ \\"<<roads[70]<<"\\ /"<<roads[71]<<"/"<<endl;

	cout << "            "<<vertices[51]<<"     "<<vertices[52]<<"     "<<vertices[53]<<endl;
	cout<< "=========================================="<<endl;


}
