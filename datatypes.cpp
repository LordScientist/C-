#include <iostream>

int main()
    {
        double price = 99.99;
        // For float,we add the "F" or "f" to force the compiler to recognise
        float interestRate = 3.67f;
        int number = 677797;
        // We add the "L" or "l" so the compiler recognise;
        long fileSize =  4556779999545L;
        // With char,always use single quotes;
        char letter = 'a';
        bool isValid = true;
        // Auto  keyword lets the compiler decides based the datatype on what is given

        auto price = 99.99;
        // For float,we add the "F" or "f" to force the compiler to recognise
        auto interestRate = 3.67f;
        auto number = 677797;
        // We add the "L" or "l" so the compiler recognise;
        auto fileSize =  4556779999545L;
        // With char,always use single quotes;
        auto letter = 'a';
        auto isValid = true;

        // You can use the brace initialisation.
        int number{}; //This will give you a zero,removing the braces will give you garbage values.
    }