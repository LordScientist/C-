#include <iostream>

int main()
    {
        int sales;
        double stateTaxRate = 0.04;
        double countyTaxRate = 0.02;
        std::cout << "Enter your sales" << std::endl;
        std::cin >> sales;
        double stateTax = stateTaxRate * sales;
        double countyTax = countyTaxRate * sales;
        double result = sales - (stateTax + countyTax);
        std::cout << "---------------------------------------" << std::endl;
        std::cout << "Your State Tax is : $" << stateTax << std::endl;
        std::cout << "Your County Tax is : $" << countyTax << std::endl;
        std::cout << "Your total sales currently is : $" << result << std::endl;
        std::cout << "---------------------------------------";
    }
