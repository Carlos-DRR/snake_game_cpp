#include <iostream>
#include "Snake.h"
#include "Board.h"

class Game{
    private:
        bool gameOver = false;
        Board *board;
        Snake<Position*> *snake;
        int direction = 0;

    public:
        Game(){
            board = new Board();
            spawnSnake();
            
        }

        void spawnSnake(){
            int row = Util::randomNumber(10);
            int col = Util::randomNumber(10);
            while(board->getBoardPosition(row, col)->getPositionType() == PositionType::UPGRADE){
                row = Util::randomNumber(10);
                col = Util::randomNumber(10);
            }
            snake = new Snake<Position*>(board->getBoardPosition(row, col));
        }

        Position *getNextPosition(){
            return nullptr; // implement
        }

        void update(){
            snake->move(board->getBoardPosition(0, 1));
            cout << "move pra direita:" << endl;
            board->print();
            cout << "move pra direita:" << endl;
            snake->move(board->getBoardPosition(0, 2));
            board->print();
            cout << "move upgrade:" << endl;
            snake->move(board->getBoardPosition(0, 3));
            snake->grow(board->getBoardPosition(0, 3));
            board->print();
            cout << "move pra direita:" << endl;
            snake->move(board->getBoardPosition(0, 4));
            snake->print();
            board->print();
            cout << "move pra direita:" << endl;
            snake->move(board->getBoardPosition(0, 5));
            board->print();
        }
};