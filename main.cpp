#include <iostream>
//#include "Snake.h"
//#include "Board.h"
#include "Game.h"
using namespace std;

int main(){
    /*
    Board *b = new Board();
    Snake<Position*> *lista = new Snake<Position*>(b->getBoardPosition(0, 0));
    lista->move(b->getBoardPosition(0, 1));
    cout << "move pra direita:" << endl;
    b->print();
    cout << "move pra direita:" << endl;
    lista->move(b->getBoardPosition(0, 2));
    b->print();
    cout << "move upgrade:" << endl;
    lista->move(b->getBoardPosition(0, 3));
    lista->grow(b->getBoardPosition(0, 3));
    b->print();
    cout << "move pra direita:" << endl;
    lista->move(b->getBoardPosition(0, 4));
    lista->print();
    b->print();
    cout << "move pra direita:" << endl;
    lista->move(b->getBoardPosition(0, 5));
    b->print();
    */
    Game *game = new Game();
    game->update();
    system("pause");
    return 0;
}