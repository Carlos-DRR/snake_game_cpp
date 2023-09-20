#include "Util.h"
#include "Position.h"
#include <iostream>
#define BOARD_SIZE 25

using namespace std;

class Board{
    private:
        Position *board[BOARD_SIZE][BOARD_SIZE];
    public:
        Board(){
            initializeBoard();
        }

        void initializeBoard(){
            for(int i = 0; i < BOARD_SIZE; i++){
                for(int j = 0; j < BOARD_SIZE; j++){
                    board[i][j] = new Position(i, j, PositionType::EMPTY);
                }
            }
            randomPositionUpgrade();
        }

        void randomPositionUpgrade(){
            int randRow = Util::randomNumber(10);
            int randCol = Util::randomNumber(10);
            while(board[randRow][randCol]->getPositionType() == PositionType::SNAKE_PART){
                randRow = Util::randomNumber(10);
                randCol = Util::randomNumber(10);
            }
            board[randRow][randCol]->setPositionType(PositionType::UPGRADE);
        }

        void print(){
            system("cls");
            for(int i = 0; i < BOARD_SIZE; i++){
                for(int j = 0; j < BOARD_SIZE; j++){
                    cout << board[i][j]->toString();
                    cout << " ";
                }
                cout << "\n";
            }
        }
        void print(int score){
            system("cls");
            cout << "SCORE: " << score;
            cout << "\n";
            for(int i = 0; i < BOARD_SIZE; i++){
                for(int j = 0; j < BOARD_SIZE; j++){
                    cout << board[i][j]->toString();
                    cout << " ";
                }
                cout << "\n";
            }
        }
        Position *getBoardPosition(int row, int col){
            if(row > BOARD_SIZE - 1 || row < 0 || col > BOARD_SIZE - 1 || col < 0) throw 1;
            return board[row][col];
        }
};