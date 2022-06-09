#include <vector>
#include <iostream>
#include <iomanip>

using namespace std;



int **boardCreation(int length){
    int** board;
    board = new int*[length];
    for(int i =0; i < length; i++){
        board[i] = new int [length];
    }

    for(int x =0; x<length; x++){
        for(int y =0; y<length; y++){
            board[x][y] = -1;
        }
    }
    return board;

}
void printBoard(int **board, int length){
    for(int x =0; x<length; x++){
        for(int y =0; y<length; y++){
            cout << " " << setw(2) << board[x][y] << " ";
         }
            cout << endl;
    }
}
int traverseBoard(int **board, int length, vector<pair<int, int>> horseyMoves){

}
int main(){
    int length;
    vector<pair<int, int>> horseyMoves = {{1,2},{1,-2}, {2,1}, 
    {2,-1}, {-1,2}, {-1,-2}, {-2,-1}, {-2,1}};

    cout << "input length of board: ";
    cin >> length;
    int **board = boardCreation(length);
    printBoard(board, length);
    return 0;
    
}

