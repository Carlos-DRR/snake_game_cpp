#include <iostream>
#include <ctime>
#include <cstdlib>

class Util{

    public:
        static int randomNumber(int max){
            return rand() % max;
        }

};