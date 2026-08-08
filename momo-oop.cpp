#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

class Account
    {
        protected:
            double balance;
            std::string name;
            std::string pin;
            std::string mobileNumber;


        public:
            Account()
                {
                    balance = 400.00;
                    cout << "Enter your name: \n";
                    cin >> name;

                    cout << "Enter your pin: \n";
                    cin >> pin;

                    cout << "Enter your number: \n";
                    cin >> mobileNumber;
                }

        public:
            void deposit(double money)
                {
                    if (money <= 0)
                        {
                            cout << "Invalid deposit\n";
                            cout << "Deposit should be greater than 0";
                        }
                    else
                        {
                            balance += money;
                        }
                    
                }
            
            void withdraw(double money)
                {
                    if (money > balance || money <= 0)
                        {
                            cout << "Insufficient balance to complete withdrawal\n";
                        }

                    else 
                        {
                            balance -= money;
                        }
                    
                }

            void checkBalance()
                {
                    std::string userPin;
                    cout << "Enter your pin please: \n";
                    cin >> userPin;
                    if(userPin == pin)
                        {
                            cout << "Your balance is GHC" << balance << endl;
                        }

                    else
                        {
                            cout << "Invalid pin to proceed.\n";
                        }
                }

            void sendMoney(double money)
                {
                    if (money <= 0 || money > balance)
                        {
                            cout << "Cannot perform such transaction\n";
                        }
                    else
                        {
                            std::string userPin;
                            cout << "Enter your pin\n";
                            cin >> userPin;
                            if (userPin != pin )
                                {
                                    cout << "Invalid Pin. Transaction failed.\n";
                                }
                            else
                                {
                                    std::string receiver;
                                    cout << "Enter receiver's name: ";
                                    cin >> receiver;
                                    balance -= money;
                                    cout << "You have successfully sent GHC" << money << " to " << receiver << endl;
                                    cout << "Your balance now is:GHC" << balance << endl; 
                                }
                        }
                }
            ~Account()
                {
                    cout << "I guess this is where I say goodbye\n";
                }
            
            
    };


 class SavingsAccount : public Account
            {
                protected:
                    double interestRate = 0.05;
                public:
                    void savings(double amount,int years)
                        {
                            if(years >= 1 && amount > 0)
                                {
                                    double interest = (interestRate) * (amount * years);
                                    cout << "You will have interest of:GHC " <<interest << " in " << years << endl;
                                    balance += interest;
                                }
                            else
                                {
                                    cout << "Check your amount and or the years inputted.\n";
                                }
                        }

                    void withdraw(double money)
                        {
                            if (balance - money < 50)
                                {
                                    cout << "You cannot withdraw more than that for a day! \n";
                                }
                            else 
                                {
                                    Account ::withdraw(money);
                                    // cout << "You have withdrawn : GHC"<< money<<endl;
                                }
                        }
            };

int main()
    {

        SavingsAccount user;
        user.withdraw(-6);



    }