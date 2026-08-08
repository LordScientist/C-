#include <iostream>
#include <string>
using std::cout;
using std::cin;
using std::endl;

int menu()
    {
        int user;
        cout << "Enter 1 to proceed or enter 0 to exit:\n";
        cin >> user;
        if (user == 0)
            {
                cout << "Dial anytime for any information. Thank you!\n";
            }
        else if(user == 1)
            {
                cout << "Press 1 to send Money\n";
                cout << "Press 2 to check your balance\n";
                cout << "Press 3 to buy data or bundle\n";  
                cout << "Press 4 to allow cashout\n";
                cin >> user;
                
            }

        else 
            {
                cout << "Enter a valid number or code to proceed!\n";
            }
            return user;
    }


// int user_request()
    // {
        // int user;
        // if (user == 0)
            // {
                // cout << "Press 1 to send Money\n";
                // cout << "Press 2 to check your balance\n";
                // cout << "Press 3 to buy data or bundle\n";  
                // cout << "Press 4 to allow cashout\n";
                // cin >> user;                
            // }
        // 
        // return user;
    // }


int sendMoney(int secret)
    {
        
        double amount;
        int entered_pin;
        std::string receiver;
        cout << "Enter amount to be sent: \n";
        cin  >> amount;
        
        cout << "Enter receiver's name:\n";
        cin>> receiver;

        cout << "Enter pin please\n";
        cin >> entered_pin;
        
        if (entered_pin == secret)

        {
            cout << "__________________________________________________________\n";
            cout << "You have sent " << amount << "cedis to " << receiver << " successfully\n";
            cout << "__________________________________________________________\n";
        }
        else
            {
                cout << "Incorrect pin,transaction failed.\n";
            }

        int back;
        cout << "Press 0 to go back\n";
        cin >> back;
        if (back == 0)
            {
                menu();
            }

        else
            {
                cout << "See you next time!\n";
            }
        
        
        return 0;
    }

int balance(int secret)
    {
        cout << "Enter pin to check balance please.\n";
        int entered_pin;
        cin >> entered_pin;
        if (entered_pin == secret)
            {
                cout << "__________________________________________________________\n";
                cout << "You have GHC 100\n";
                cout << "You are broke as hell,find a job,motherfucker💀🤦🫵\n";
                cout << "Your friendly neighbour MTN,motherfucker😹😹😹\n";
                cout << "__________________________________________________________\n";
            }

        else 
            {
                cout << "Enter the correct pin please.\n";
            }

        int back;
        cout << "Press 0 to go back\n";
        cin >> back;
        if (back == 0)
            {
                menu();
            }

        else
            {
                cout << "See you next time!\n";
            }
            return 0;
    }

int data()
    {
        double bundle;
        cout << "Enter the amount in cedis you want to buy:\n";
        cin >> bundle;
        cout << "__________________________________________________________\n";
        cout << "You have successfully bought " << bundle << "MB\n";
        cout << "Enjoy whilst it last,little one. Your friendly neighbour MTN,motherfucker😹😹\n"; 
        cout << "__________________________________________________________\n";

        int back;
        cout << "Press 0 to go back\n";
        cin >> back;
        if (back == 0)
            {
                menu();
            }

        else
            {
                cout << "See you next time!\n";
            }
        return 0;
    }

void cashout()
    {
        cout << "__________________________________________________________\n";
        cout <<"Cashout has been allowed,go broke again motherfucker😹😹\n";
        cout << "__________________________________________________________\n";

        int back;
        cout << "Press 0 to go back\n";
        cin >> back;
        if (back == 0)
            {
                menu();
            }

        else
            {
                cout << "See you next time!\n";
            }
    }

int main()
    {
        
        int pin;
        cout << "Enter your pin to save for the session.\n";
        cin >> pin;
       
        int user = menu();


        switch(user)
            {
                case 1:
                sendMoney(pin);
                break;

                case 2:
                balance(pin);
                break;

                case 3:
                data();
                break;

                case 4:
                cashout();
                break;
            }

    }



