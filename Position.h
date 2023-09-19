#include "PositionType.h"
#include <string>
#include <iostream>
class Position{
    private:
        int row;
        int column;
        PositionType positionType;
    public:
        Position(int row, int column, PositionType positionType){
            this->row = row;
            this->column = column;
            this->positionType = positionType;
        }

        int getRow(){
            return row;
        }

        int getColumn(){
            return column;
        }

        PositionType getPositionType(){
            return positionType;
        }

        void setPositionType(PositionType positionType){
            this->positionType = positionType;
        }

        std::string toString(){
            if(positionType == PositionType::EMPTY) return "-";
            else if (positionType == PositionType::SNAKE_PART) return "@";
            else return "+";
        }

};