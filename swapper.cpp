#include <iostream>
using namespace std;

int main()
    {
        int first;
        int second;
        cout << "What is the first value?\n" << endl;
        cin >> first;
        cout << "What is the second value?\n" << endl;
        cin >> second;
        cout << "First value: " << first << endl;
        cout << "Second value: " << second << endl;
        int temp = first;
        first = second;
        second = temp;
        cout << "--------------\n" << endl;
        cout << "Swapped values\n"<< endl;
        cout << "First: " << first << endl;
        cout << "Second: " << second << endl;
        cout << "---------------";
        return 0;
    }
