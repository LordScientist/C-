#include <iostream>

// For Loop
// int main()
    // {
        // long long number;
        // std::cout << "Enter the number you want to work on!\n" << std::endl;
        // std::cin >> number;
        // for(int i =number -1; i >=1;i--)
            // {
                // number = number * i;
                // 
            // }
        // std::cout << "Factorial: " << number << std::endl;
        // return 0;
    // }




// While loop
// int main()
    // {
        // long long number;
        // std::cout << "Enter the number: \n";
//         // std::cin >> number;

        // int i = number - 1;
        // while(i >1)
            // {
                // number *= i;
                // i--;
            // }
    //     // std::cout << "The factorial is: " << number << std::endl;
    // }

// Do while loop

int main()
    {
        long long number;
        std::cout << "Please enter the number: \n";
        std::cin >> number;
        int i = number - 1;
        do 
        {
            number *= i;
            std::cout << "The factorial is: " << number <<std::endl;
            i --;     
        }
       while(i > 1); 
        
    }