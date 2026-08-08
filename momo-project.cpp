#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

// Withdraws is <= $500 per day
// widraws > $300,charge is 4% of the amount over $300
// If balance is < widraws,give option to widraw at a fee of $25
// If balance = 0 or negative,No widrawal
// If widrawal > $500,inform of the max widraw,i.e $500


class Account()
    {
        protected:
            double balance;
            std::string pin;
            double serviceCharge;

        public:
            Account()
                {
                    cout << "Enter your pin";
                    cin >> pin;
                    balance = 0.00;
                    serviceCharge = 

                }

        public:
            void withdraw(double amount)
                {
                    switch (amount)
                    {
                    case amount > 500:
                        cout << "You cannot withdraw more than $500 a day\n";
                        break;
                    
                    case amount > 300;
                    default:
                        break;
                    } (amount)

                }

    




    }

int main()
    {

    }