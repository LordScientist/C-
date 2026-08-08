#include <iostream>
using namespace std;

using std::cout;
using std::cin;
using std::endl;

void newVar(int* pointerData)
    {
        cout << "This is the void function that returns the address of anything " << pointerData << endl;
    }

    

int main()
    {
        int myVar = 12;
        cout << "My variable is: " <<myVar << endl;

        int* ptr = &myVar;
        cout << "This is the memory addressed sorted by the ponter "<< ptr << endl;
        cout << "This  one grabs the value the pointer knows the address of: " << *ptr <<endl;
        
        newVar(&myVar);

        void* p = &myVar;
        cout << *(int*)p <<endl;


        int x = 5;
        int* area = &x;
        int* y = &x;
        cout << "This is the memory address of X : " << area << endl;
        cout << "This is the memory address of Y : " << y << endl;

    }

// To return the value of what the pointer knows,use the '*' infront of the pointer variable;
//  To use the memory address of the pointer,use only the variable;