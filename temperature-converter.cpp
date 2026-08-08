#include <iostream>
#include <string>

int main()
    {
        std::string choice;
        std::cout << "Enter 1 or degrees if you want from degrees to Fahrenheit" << std::endl;
        std::cout << "Enter 2 or fahrenheit if you want from Fahrenheit to degrees" << std::endl;
        std::cin >> choice;
        
        if(choice == "1" || choice == "degrees")
            {
                double temperature;

                std::cout << "Enter the temperature in degrees to be converted to Fahrenheit:" << std::endl;

                std::cin >> temperature;

                const double scale = 1.8;

                double converter = (scale * temperature) + 32;

                std::cout << "________________________________________________________" << std::endl;

                std::cout << "This is your temperature in degrees: " << temperature << "C" <<std::endl;

                std::cout << "This is your temperature in Fahrenheit: " << converter <<"F" << std::endl;

                std::cout << "________________________________________________________" << std::endl;    
            }

        else if(choice == "2" || choice == "fahrenheit")
            {
                double temperature;

                std::cout << "Enter the temperature in Fahrenheit to be converted to Degrees:" << std::endl;

                std::cin >> temperature;

                const double scale = 1.8;

                double converter = (temperature - 32) / scale;

                std::cout << "________________________________________________________" << std::endl;

                std::cout << "This is your temperature in Fahrenheit: " << temperature << "F" <<std::endl;

                std::cout << "This is your temperature in Degrees: " << converter <<"C" << std::endl;

                std::cout << "________________________________________________________" << std::endl;    
            }
            return 0;
    }

