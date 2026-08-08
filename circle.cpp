#include <iostream>
#include <cmath>
int main()
    {
        double radius;
        std::cout << "Enter the radius of the circle:" << std::endl;
        std::cin >> radius;
        double radiusSquared = pow(radius,2);
        double compute = M_PI * radiusSquared;
        std::cout << "This is the area of the circle: " << compute << std::endl;
        
        return 0;
    }