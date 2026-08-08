#include <iostream>
using std::cout;
using std::cin;

int fact(int n)
            {
                if (n == 1)
                    return 1;
                else
                    return n * fact(n-1);
                    
            }


int main()
    {
        int value;
        cout << "Enter value your value : \n";
        cin >> value;
        int result = fact(value);
        cout << "The result is : "<< result << std::endl;

        return 0;
    }
