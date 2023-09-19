#include <iostream>

class Util{

    public:
        static int randomNumber(int max){
            return rand() % max;
        }

};