#include <iostream>
#include <string>


using std::cout;
using std::cin;
using std::endl;
using std::string;



class Account
    {
        protected:
            double balance;
            string name;
            string number;
            string pin;

        public:
            Account()
                {
                    balance = 1000.00;
                    cout << "Enter your name\n";
                    cin >> name;
                    cout << "Enter your mobile number\n";
                    cin >> number;
                    cout << "Enter you pin\n";
                    cin >> pin;
                }

        public:
            double withdraw()
                {
                    string withdraw_pin;
                    double withdraw_balance;
                    cout << "----------Money Withdrawal----------\n";
                    cout << "Enter your mobile pin please\n";
                    cin >> withdraw_pin;
                    if(withdraw_pin == pin)
                        {
                            cout << "Enter the amount you want to withdraw please\n";
                            cin >> withdraw_balance;

                        } 
                    else
                        {
                            cout << "Invalid pin,transaction dissallowed\n";
                        }

                    if(withdraw_balance <= balance && withdraw_balance > 0)
                        {
                            balance -= withdraw_balance;
                            cout <<"---------------\n";
                            cout << "You have successfully withdrawn GHC "<< withdraw_balance << endl;
                            cout << "Your current balance is GHC " <<balance <<endl;
                            cout << "---------------\n";
                        }

                    else
                        {
                            cout << "You cannot withdraw GHC "<< withdraw_balance <<"While your balance is :GHC "<< balance <<endl;
                        }
                    return 0;

                }
        
            double sendMoney()
                {
                    string receipient_number;
                    double money;
                    string send_pin;
                    cout << "----------Sending Money----------\n";
                    cout << "Please enter your pin\n";
                    cin >> send_pin;
                    
                    if(send_pin == pin)
                        {
                            cout << "Please enter the amount you want to send \n";
                            cin >> money;
                        }

                    else
                        {
                            cout << "Invalid pin please,transaction disallowed\n";
                        }

                    if(money > 0 && money <= balance)
                        {
                            cout << "Enter the reciepient number please\n";
                            cin >> receipient_number;
                            balance -= money;
                            cout <<"---------------\n";
                            cout << "You have successfully sent GHC "<< money << " to "<< receipient_number << endl;
                            cout << "Your current balance is GHC " << balance <<endl;
                            cout <<"---------------\n";

                        }

                    else
                        {
                            cout << "You cannot send GHC "<< money <<"While your balance is :GHC "<< balance <<endl;
                        }
                    return 0;
                }

            double deposit()
                {
                    double amount;
                    cout << "----------Depositing Money----------\n";
                    cout << "How much do you want to deposit please?\n";
                    cin >> amount;
                    if(amount > 0)
                        {
                            balance += amount;
                            cout <<"---------------\n";
                            cout << "You have successfully deposited GHC "<< amount << endl;
                            cout << "You balance now is GHC "<< balance << endl;
                            cout <<"---------------\n";

                        }
                    
                    else
                        {
                            cout << "Please enter an amount greater than GHC 0\n";
                        }

                    return 0;
                }


    };


class User
    {
        private:
        
    };



int main()
    {
        Account user;
        user.withdraw();
        user.deposit();
        user.sendMoney();
        return 0;

    }