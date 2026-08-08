#include <iostream>
#include <ctime>
#include <cstdlib>


int main ()
    {
        srand(time(nullptr));
        short dice = 6;
        short zeroCorrection = 1;
        short random = (rand() % dice ) + zeroCorrection;
        std::cout << random << std::endl;
    } 