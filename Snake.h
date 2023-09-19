#include "Position.h"
#include "List.h"

template <class T>
class Snake : public List <Position*> {
    public:
        Snake(Position* info){ // instantiate with board position
            info->setPositionType(PositionType::SNAKE_PART);
            List<Position*>();
            List<Position*> :: add(info);       
        }

        bool checkCrash(Position* info){
            return info->getPositionType() == PositionType::SNAKE_PART;
        }

        void move(Position* info){
            Position* tail = List <Position*> :: removeLast();
            tail->setPositionType(PositionType::EMPTY);
            info->setPositionType(PositionType::SNAKE_PART);
            List<Position*>::addFirst(info);            
        }

        void grow(Position* info){
            info->setPositionType(PositionType::SNAKE_PART);
            List<Position*>::add(info);
        }

        void print(){
            Node <Position*> *current = head;
            while(current != nullptr){
                std::cout << current->getInfo()->getRow();
                std::cout << ", ";
                std::cout << current->getInfo()->getColumn() << std::endl;
                std::cout << current->getInfo()->toString() << std::endl;
                std::cout << "\n";
                current = current->getNext();
            }
            std::cout << "Snake size: " << List<Position*>::getSize();
            std::cout << "\n";
            delete current;
        }
        
        void printHeadAndTail(){
            std::cout << "HEAD: \n";
            std::cout << head->getInfo()->getRow();
            std::cout << ", ";
            std::cout << head->getInfo()->getColumn() << std::endl;
            std::cout << head->getInfo()->toString() << std::endl;

            std::cout << "TAIL: \n";
            std::cout << tail->getInfo()->getRow();
            std::cout << ", ";
            std::cout << tail->getInfo()->getColumn() << std::endl;
            std::cout << tail->getInfo()->toString() << std::endl;
        }

};