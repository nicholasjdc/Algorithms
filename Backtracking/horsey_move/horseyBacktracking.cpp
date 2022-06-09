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

bool isValidMove(int ** board, pair<int, int> currentPosition, int length){
    cout<<"START VALIDATION " << currentPosition.first << " ;" << currentPosition.second<<endl;
    if(currentPosition.first <length && currentPosition.first >=0
            && currentPosition.second <length && currentPosition.second >= 0
            && board[currentPosition.first][currentPosition.second] == -1){
                    cout<<"END VALIDATION TRUE"<<endl;

                return true;
    }else{
            cout<<"END VALIDATION FALSE"<<endl;

        return false;
    }
}
void printBoard(int **board, int length){
    for(int x =0; x<length; x++){
        for(int y =0; y<length; y++){
            cout << " " << setw(2) << board[x][y] << " ";
         }
            cout << endl;
    }
}
int **traverseBoard(int **board, int length, int currMove, pair<int, int> currentPosition, vector<pair<int, int>> horseyMoves){
    //Horsey makes a move
    //if the move is valid, mark as such, otherwise ignore
    //
    for(pair<int, int> m: horseyMoves){
        currentPosition.first += m.first;
        currentPosition.second += m.second;
        cout<<"AT VALIDATION"<<endl;

        if(isValidMove(board, currentPosition, length)){
            board[currentPosition.first][currentPosition.second] = currMove;
            currMove +=1;
            board = traverseBoard(board, length, currMove, currentPosition, horseyMoves);
        
        }else{}

    }
    return board;
}

int main(){
    int length;
    vector<pair<int, int>> horseyMoves = {{1,2},{1,-2}, {2,1}, 
    {2,-1}, {-1,2}, {-1,-2}, {-2,-1}, {-2,1}};

    cout << "input length of board: ";
    cin >> length;
    int **board = boardCreation(length);
    printBoard(board, length);
    board = traverseBoard(board, length, 0, {0,0}, horseyMoves);
    printBoard(board, length);
    return 0;
    
}

