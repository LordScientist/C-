#include <iostream>
using std::cout;
using std::cin;
using std::endl;

int collatz(int n,int moves)
    {
        moves+=1;

        if (n == 1)
            {
                
                return 0;
            }

        else if (n % 2 == 0)
            {

                collatz(n/2,moves);
                return moves;

            }
        else
            {
                collatz(3*n + 1,moves );
                return moves;
            }
    }



int main()
    {
        int step = 0;
        int value;
        cout << "Enter your value : ";
        cin >> value;
        int result = collatz(value,step);
        cout << "This is the number of steps : " << result << endl;

        return 0;

    }