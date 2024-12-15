#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>
using namespace std;

class Player{
public:
    string name;
    bool won;
    char symbol;

    // Default constructor
    Player() : name("Default"), won(false), symbol('X') {}

    // Parameterized constructor
    Player(string name, bool won = false, char symbol = 'X') 
        : name(name), won(won), symbol(symbol) {}

    void setWonStatus(bool wonStatus){
        won = wonStatus;
    }

    void displayDetails(){
        cout << name << " " << symbol << " " << won << endl;
    }
};

void printBoard(vector<vector<char>> defBoard){
    system("cls");
    int n = defBoard.size();
    for(int i = 0; i < n; i++){
        for(int j = 0; j < defBoard[i].size(); j++)
            cout << defBoard[i][j];
        cout << endl;
    }
}

void inputPlayerDetails(Player& player){
    string name;
    char symbol;

    cout << "Enter player name: ";
    cin >> name;

    cout << "Enter symbol of your choice (Either 'X' or 'O'): ";
    cin >> symbol;

    player.name = name;
    player.symbol = symbol;
    cout << "\n";
}

bool checkIfAlreadyOccupied(vector<pair<int, int>> posX, vector<pair<int, int>> posO, pair<int, int> pos){

    //Checking in posX
    for(auto p : posX){
        if(p == pos) return true;
    }

    //Checking in posO
    for(auto p : posO){
        if(p == pos) return true;
    }

    return false;
}

bool checkWin(vector<vector<char>>& board, char symbol) {
    int rows = board.size();
    int cols = board[0].size();

    // Check rows
    for (int i = 0; i < rows; i++) {
        if(board[i][1] == symbol && board[i][4] == symbol && board[i][7] == symbol)
        	return true;
    }

    // Check columns
    for (int i = 0; i < cols; i++) {
        if(board[1][i] == symbol && board[3][i] == symbol && board[5][i] == symbol)
        	return true;
    }

    // Check diagonals
    if(board[1][1] == symbol && board[3][4] == symbol && board[5][7] == symbol)
    	return true;

    if(board[1][7] == symbol && board[3][4] == symbol && board[5][1] == symbol)
    	return true;

    return false;
}

void playGame(Player& player1, Player& player2, vector<pair<int, int>> posX, vector<pair<int, int>> posO, vector<vector<char>>& defBoard){
    int cnt = 1;
    int max_operations = 5;
    cout << "Enter the x and y positions in the range of (0-5) and (0-7) respectively" << endl;
    
    while(true && cnt < 2 * max_operations){
        if(cnt % 2 != 0){
            cout << "\n" << player1.name << "'s turn" << endl;
            pair<int, int> pos;
            cout << "Enter your positions: ";
            cin >> pos.first >> pos.second;

            bool check = checkIfAlreadyOccupied(posX, posO, pos);
            if(!check){
                if(player1.symbol == 'X')
                    posX.push_back(pos);
                else 
                    posO.push_back(pos);
                defBoard[pos.first][pos.second] = player1.symbol;
                cnt += 1;
            }else{
                cout << "The entered positions are already occupied" << endl;
                continue;
            }

            printBoard(defBoard);

            // Checking for a win
	        bool v1 = checkWin(defBoard, player1.symbol);
	        if(v1){
	        	player1.setWonStatus(true);
	        	return;
	        }
        }

        else{
            cout << "\n" << player2.name << "'s turn" << endl;
            pair<int, int> pos;
            cout << "Enter your positions: ";
            cin >> pos.first >> pos.second;

            bool check = checkIfAlreadyOccupied(posX, posO, pos);
            if(!check){
                if(player2.symbol == 'X')
                    posX.push_back(pos);
                else 
                    posO.push_back(pos);
                defBoard[pos.first][pos.second] = player2.symbol;
                cnt += 1;
            }else{
                cout << "The entered positions are already occupied" << endl;
                continue;
            }

            printBoard(defBoard);

            // Checking for a win
	        bool v2 = checkWin(defBoard, player2.symbol);
	        if(v2){
	        	player2.setWonStatus(true);
	        	return;
	        }
        }
    }
}