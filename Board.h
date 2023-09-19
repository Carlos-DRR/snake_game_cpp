#include "Util.h"
#include "Position.h"
#include <iostream>


using namespace std;

class Board{
    private:
        Position *board[10][10];
    public:
        Board(){
            initializeBoard();
        }

        void initializeBoard(){
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
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
            for(int i = 0; i < 10; i++){
                for(int j = 0; j < 10; j++){
                    cout << board[i][j]->toString();
                    cout << " ";
                }
                cout << "\n";
            }
        }

        Position *getBoardPosition(int row, int col){
            return board[row][col];
        }
};