#include <iostream>
#include "Snake.h"
#include "Board.h"
#include <conio.h>
#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

class Game{
    private:
        bool gameOver;
        Board *board;
        Snake<Position*> *snake;
        char lastInput = ' ';
    public:
        Game(){
            board = new Board();
            spawnSnake();
            gameOver = false;
        }

        void spawnSnake(){
            int row = Util::randomNumber(BOARD_SIZE);
            int col = Util::randomNumber(BOARD_SIZE);
            while(board->getBoardPosition(row, col)->getPositionType() == PositionType::UPGRADE){
                row = Util::randomNumber(BOARD_SIZE);
                col = Util::randomNumber(BOARD_SIZE);
            }
            snake = new Snake<Position*>(board->getBoardPosition(row, col));
        }

        Position *getNextPosition(){
            if(kbhit()){
                char c = getch();
                switch(c){
                    case 'w':{
                        lastInput = 'w';
                        return board->getBoardPosition(snake->getHead()->getRow() - 1, snake->getHead()->getColumn());
                        break;
                    }
                    case 's':{
                        lastInput = 's';
                        return board->getBoardPosition(snake->getHead()->getRow() + 1, snake->getHead()->getColumn());
                        break;
                    }
                    case 'a':{
                        lastInput = 'a';
                        return board->getBoardPosition(snake->getHead()->getRow(), snake->getHead()->getColumn() - 1);
                        break;
                    }
                    case 'd':{
                        lastInput = 'd';
                        return board->getBoardPosition(snake->getHead()->getRow(), snake->getHead()->getColumn() + 1);
                        break;
                    }
                    default :{
                        return snake->getHead();
                    }
                }
            }else if(lastInput != ' '){
                    switch(lastInput){
                        case 'w':{
                            lastInput = 'w';
                            return board->getBoardPosition(snake->getHead()->getRow() - 1, snake->getHead()->getColumn());
                            break;
                        }
                        case 's':{
                            lastInput = 's';
                            return board->getBoardPosition(snake->getHead()->getRow() + 1, snake->getHead()->getColumn());
                            break;
                        }
                        case 'a':{
                            lastInput = 'a';
                            return board->getBoardPosition(snake->getHead()->getRow(), snake->getHead()->getColumn() - 1);
                            break;
                        }
                        case 'd':{
                            lastInput = 'd';
                            return board->getBoardPosition(snake->getHead()->getRow(), snake->getHead()->getColumn() + 1);
                            break;
                        }
                        default :{
                            return snake->getHead();
                        }
                    }
            }
            
            return snake->getHead();
        }

        void start(){
            while(!gameOver){ 
                board->print(snake->getSize() - 1);
                Sleep(75);
                try{
                    Position *nextPosition = getNextPosition();
                    if(nextPosition != snake->getHead()){
                        if(!snake->checkCrash(nextPosition)){
                            if(nextPosition->getPositionType() == PositionType::UPGRADE){
                                snake->grow(nextPosition);
                                board->randomPositionUpgrade();
                            }
                            snake->move(nextPosition);

                        }else gameOver = true;   
                    }
                }
                catch(int e){
                    if(e == 1) gameOver = true; 
                }
            }
            cout << "GAME OVER" << endl;
        }
};