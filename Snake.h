#include "Position.h"


template <class T>
class Snake : public List <Position*>{
    public:
        Snake(Position* info){ // instantiate with board position
            List<Position*> :: List();
            List<Position*> :: add(info);       
        }

        void move(Position* info){
            Position* tail = List <Position*> :: removeLast();
            tail->setPositionType(PositionType::EMPTY);
            info->setPositionType(PositionType::SNAKE_PART);
            List<Position*> add(info);            
        }

        void grow(){
            
        }
        


};