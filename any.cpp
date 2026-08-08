#include <iostream>
using std::cout;
using std::cin;



int main()
    {
        int array[5];
        int value;
        for (int i = 0;i < 5;i++)
            {
                cout << "Enter what you want to be stored!\n";
                cin >> value ;
                array[i] = value;
            }
        cout << "______________________________\n";
        for (int i = 0;i < 5;i++)
            {
                cout << array[i] <<"\n";
            }
        cout << "______________________________\n";
    }