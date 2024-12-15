#include <bits/stdc++.h>
#include <thread>
#include <chrono>
#include "utility.h"
using namespace std;

vector<vector<char>> defBoard = {
		{' ', ' ', '|', ' ', ' ', '|', ' ', ' '},
		{'_', '_', '|', '_', '_', '|', '_', '_'},
		{' ', ' ', '|', ' ', ' ', '|', ' ', ' '},
		{'_', '_', '|', '_', '_', '|', '_', '_'},
		{' ', ' ', '|', ' ', ' ', '|', ' ', ' '},
		{' ', ' ', '|', ' ', ' ', '|', ' ', ' '}
	}; // r = 6, c = 8

void printWelcomePage() {
    cout << "----------------TIC-TAC-TOE------------------------\n" << endl;
    cout << "This is a mini tic-tac-toe game for 2-players" << endl;
    cout << "\n-------------------------------------------------" << endl;
}

int main(){
	printWelcomePage();
	vector<pair<int, int>> posX, posO;

	// Taking player inputs
	Player player1, player2;
	inputPlayerDetails(player1);
	inputPlayerDetails(player2);

	//Validating if both players chose different symbols
	if(player1.symbol == player2.symbol){
		cout << "Symbols used by both players cannot be the same!!!" << endl;
		cout << "Exiting program";
		exit(0);
	}

	playGame(player1, player2, posX, posO, defBoard);

	// Displaying the player details
	if(player1.won){
		cout << "-----------------------------------------------\n" << endl;
		cout << player1.name << " has won!!!" << endl;
		cout << "\n-----------------------------------------------" << endl;
	}else if(player2.won){
		cout << "-----------------------------------------------\n" << endl;
		cout << player2.name << " has won!!!" << endl;
		cout << "\n-----------------------------------------------" << endl;
	}else{
		cout << "-----------------------------------------------\n" << endl;
		cout << "The game was a tie" << endl;
		cout << "\n-----------------------------------------------" << endl;
	}
}