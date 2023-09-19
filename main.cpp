#include <iostream>
#include "Snake.h"

using namespace std;

int main(){
    Position *p1 = new Position(0, 0, PositionType::EMPTY);
    Position *p2 = new Position(0, 1, PositionType::EMPTY);
    Position *p3 = new Position(0, 2, PositionType::EMPTY);
    Position *p4 = new Position(0, 3, PositionType::UPGRADE);
    Position *p5 = new Position(0, 4, PositionType::EMPTY);
    Position *p6 = new Position(0, 5, PositionType::EMPTY);
    Snake<Position*> *lista = new Snake<Position*>(p1);
    lista->move(p2);
    cout << "move pra direita:" << endl;
    lista->print();
    lista->printHeadAndTail();
    cout << "move pra direita:" << endl;
    lista->move(p3);
    lista->print();
    lista->printHeadAndTail();
    cout << "move upgrade:" << endl;
    lista->move(p4);
    lista->grow(p4);
    lista->print();
    lista->printHeadAndTail();
    cout << "move pra direita:" << endl;
    lista->move(p5);
    lista->print();
    lista->printHeadAndTail();
    cout << "move pra direita:" << endl;
    lista->move(p6);
    lista->print();
    cout << p4->toString();
    return 0;
}