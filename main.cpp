#include <iostream>
#include "List.h"
#include "Position.h"

using namespace std;

int main(){
    List<Position*> *lista = new List<Position*>();
    Position *p1 = new Position(0, 0, PositionType::EMPTY);
    Position *p2 = new Position(1, 2, PositionType::SNAKE_PART);
    Position *p3 = new Position(1, 2, PositionType::UPGRADE);
    lista->add(p1);
    lista->add(p2);
    lista->add(p3);
    cout << lista->getHead()->toString() << endl;
    cout << lista->removeLast()->toString() << endl;
    return 0;
}