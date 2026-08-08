#include <iostream>
#include <cmath>
#include <ranges>
#include <ctime>
using std::cout;
using std::cin;
using std::endl;




int main()
    {
        double guess;
        int user_guess;

        srand(time(nullptr));
        guess = rand() % 100;

        do
            {
               
                cout << "There is a magic number,can you guess it?\n";
                cin >> user_guess;
                if (user_guess == guess)
                    {
                        cout << "Hurray! You got it,you guessed it!\n";
                    }
                
                else if (fabs(user_guess - guess) >= 1 && fabs(user_guess - guess) <= 5 )
                    {
                        cout << "Wow,you were so close,try again!!\n";
                    }
                    
                else if (fabs(user_guess - guess) >= 6 && fabs(user_guess - guess) <= 20)
                    {
                        cout << "You are quite a bit off,your guess is off by close to a margin of 10\n";
                    }

                else if (fabs(user_guess - guess) >= 21 && fabs(user_guess - guess) <= 50)
                    {
                        cout << "You are not close at all,sorry little one\n";
                    }

                else 
                    {
                        cout << "You are not close at all\n";
                    }

                // cout << guess << endl;
            }
            while(user_guess != guess);

            return 0;
    }