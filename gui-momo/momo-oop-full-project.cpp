#include <iostream>
#include <string>
#include <vector>
#include <limits>

using std::string;
using std::cout;
using std::cin;
using std::endl;
using std::vector;

class Account
    {
        protected:
            double balance;

        public:
            Account()
                {
                    balance = 1000.00;
                }

        public:
            bool deposit(double amount)
                {
                    if(amount > 0)
                        {
                            balance += amount;
                            return true;
                        }
                    else
                        {
                            return false;
                        }
                }

            bool withdrawal(double amount)
                {
                    if(amount > 0 && amount <= balance)
                        {
                            balance -= amount;
                            return true;
                        }

                    else 
                        {
                            return false;
                        }
                }

            double getBalance() const
                {
                    return balance;   
                }
    };


class Transaction
            {
                protected:
                    double amount;

                public:
                    Transaction(double amount)
                        {
                            this -> amount = amount;
                        }
                    virtual void display() const = 0;
                    virtual ~Transaction() {};

            };

class Deposit : public Transaction
            {
                public:
                    Deposit(double amount) : Transaction(amount)
                        {
                            
                        }
                    void display() const override;
                      
            };

void Deposit::display() const
            {
                cout << "You have deposited : GHC " << amount;
            }

class Withdrawal : public Transaction
            {
                public:
                    Withdrawal(double amount) : Transaction(amount)
                        {

                        }
                    void display() const override
                        {
                            cout << "You have withdrawn : GHC " << amount;
                        }
            };



class Transfer : public Transaction
        {
            private:
                string counterpartyName;
                bool isOutgoing;
            public:
                Transfer(double amount,string counterpartyName,bool isOutgoing) : Transaction(amount)
                    {
                        this -> counterpartyName = counterpartyName;
                        this -> isOutgoing = isOutgoing;
                    }
                void display() const override
                    {
                        if(isOutgoing)
                            {
                                cout << "Sent GHC " << amount << " to " << counterpartyName;
                            }
                        else
                            {
                                cout << "Received GHC " << amount << " from " << counterpartyName;
                            }
                        
                    }
        };









class User
    {
        private:
            string name;
            string pin;
            string number;
            Account account;
            vector<Transaction*> history;

        public:
            User(string name,string pin,string number)
                {
                    this -> name = name;
                    this -> pin = pin;
                    this -> number = number;
                }

            void addTransaction(Transaction* t)
                {
                    history.push_back(t);
                }

            void printHistory() const
                {
                    for(int i= 0;i< history.size();i++)
                        {
                            history[i] -> display();
                            cout <<endl;
                        }
                }

        public:
            bool verifyPin(string enteredPin) const
                {
                    if(enteredPin == pin)
                        {
                            return true;
                        }

                    else
                        {
                            return false;
                        }
                }

            Account& getAccount()
                {
                    return account;
                }
            string getName() const
                {
                    return name;
                }
            string getNumber() const
                {
                    return number;
                }

    };

User* findUserByNumber(std::vector<User>&users, string number)
            {
                for(int i = 0; i < users.size(); i++)
                    {
                        if(number == users[i].getNumber())
                            {
                                return &users[i];
                            }
                    }
                    
                    return nullptr;
                    
            }


double getValidAmount()
            {
                double value;
                while(!(cin >>  value))
                    {
                        cout << "Invalid input,please enter a number\n";
                        cin.clear();
                        cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
                    }
                return value;
            }




int main()
    {
        string name;
        string pin;
        string number;

        std::vector<User> users;

        int choice;
        do
            {
                cout << "----------\n";
                cout << " ---- Menu ----\n";
                cout << " ----------\n";
                cout << " Input any number of choice to access functionalities\n";
                cout << "1. Register\n";
                cout << "2. Deposit\n";
                cout << "3. Withdraw\n";
                cout << "4. Send Money\n";
                cout << "5. Check Balance\n";
                cout << "6. View Transaction History\n";
                cout << "0. Exit\n";
                cout << "Enter your choice: \n";
                cin >> choice;

                switch(choice)
                    {
                        case 1:
                            {
                                cout << "-----Account Creation-----\n";
                                cout << "Enter your name please:\n";
                                cin >> name;
                                cout << "Enter your telephone number please:\n";
                                cin >> number;
                                cout << "Enter a 4 digit code to create a mobile pin:\n";
                                cin >> pin;
                                users.push_back(User(name,pin,number));
                                cout << "Hurray,you are now part of the family "<< name <<endl;
                                break;
                            }
                        case 2:
                            {
                                string searchNumber;
                                cout << "Enter the number you want to search for\n";
                                cin >> searchNumber;
                                if(searchNumber == "0")
                                        {
                                            cout << "Operation cancelled\n";
                                            break;
                                        }

                                User* found = findUserByNumber(users,searchNumber);

                                    if (found == nullptr)
                                        {
                                            cout << "No such User\n";
                                        }
                                    
                                    else
                                        {
                                            double amount;
                                            cout << "Enter the amount you want to deposit please (or press 0 to cancel):\n";
                                            amount = getValidAmount();

                                            

                                            bool deposit = found -> getAccount().deposit(amount);
                                            if(deposit)
                                                {
                                                    Transaction* t = new Deposit(amount);
                                                    found->addTransaction(t);
                                                    cout << "You have successfully deposited GHC " << amount <<endl;
                                                    cout << "Current balance is : GHC " << found ->getAccount().getBalance();
                                                }            
                                        }  
                                    break;
                            }

                        case 3:
                            {
                                string pin;
                                string number;
                                cout << "Enter your mobile number please:\n";
                                cin >> number;
                                cout << "Enter your MoMo pin please or press 0 to cancel: \n";
                                cin >> pin;
                                if(pin == "0")
                                    {
                                        cout << "Operation cancelled\n";
                                        break;
                                    }
                                User* found = findUserByNumber(users,number);
           
                                if(found == nullptr)
                                    {
                                        cout << "No such user\n";
                                    }

                                else if(!found -> verifyPin(pin))
                                    {
                                        cout << "Incorrect pin please. Transaction denied\n";
                                    }

                                else
                                    {
                                        double amount;
                                        cout << "Enter the amount to be withdrawn\n";
                                        amount = getValidAmount();

                                        bool success =  found ->getAccount().withdrawal(amount);
                                        if(success)
                                            {
                                                Transaction* t = new Withdrawal(amount);
                                                found->addTransaction(t);
                                                cout << "You have successfully withdrawn GHC "<<amount << endl;

                                                cout << "Your current balance is GHC "<< 
                                            
                                                found ->getAccount().getBalance();
                                            } 

                                        else
                                            {
                                                cout << "Withdrawal failed,you cannot withdraw GHC "<<amount<<" from your wallet\n";
                                            }
                                    }       
                                break;
                            }


                        case 4:
                            {
                                string senderNumber;
                                string receipientNumber;
                                cout << "Enter Sender's Number please:\n";
                                cin >> senderNumber;
                                User* sender;
                                User* receipient;
                                User* found = findUserByNumber(users,senderNumber);
                                if (found == nullptr)
                                    {
                                        cout << "No such user\n";
                                    }

                                else
                                    {
                                        sender = found;
                                        cout << "Enter receiver's Number please:\n";
                                        cin >> receipientNumber;
                                        User* found = findUserByNumber(users,receipientNumber);
                                        if (found == nullptr)
                                            {
                                                cout << "No such user please\n";
                                            }

                                        else
                                            {
                                                string pin;
                                                double amount;
                                                receipient = found;
                                                
                                                cout << "Enter a valid amount to be sent to "<< receipient->getName()<<endl;
                                                amount = getValidAmount();

                                                cout << "Enter your pin to proceed or press 0 to cancel: \n";
                                                cin >> pin;
                                                if(pin == "0")
                                                    {
                                                        cout << "Operation cancelled\n";
                                                        break;
                                                    }
                                                bool success = sender->verifyPin(pin);
                                                if(success)
                                                    {
                                                        
                                                        if(sender->getAccount().withdrawal(amount))
                                                            {
                                                                Transaction* t1 = new Transfer(amount,receipient->getName(),true);
                                                                sender->addTransaction(t1);
                                                                if (receipient->getAccount().deposit(amount))
                                                                    {
                                                                        Transaction* t2 = new Transfer(amount,sender->getName(),false);
                                                                        receipient->addTransaction(t2);
                                                                        cout <<"----------\n";
                                                                        cout << "You have successfully sent GHC "<<amount<<" to "<<receipient->getName()<<endl;
                                                                        cout << "Your current balance is GHC "<< sender->getAccount().getBalance();
                                                                        cout <<"----------\n";
                                                                
                                                                    }

                                                                else
                                                                    {
                                                                        cout << "Transaction was unable to complete,please try again later";
                                                                    }
                                                            
                                                            }

                                                        else
                                                            {
                                                                cout << "Enter a valid amount please\n";
                                                            }
                                                        
                                                        
                                                    }

                                                else
                                                    {
                                                        cout << "Your pin was incorrect\n";
                                                    }

                                            }
                                    }
                                
                                break;
                            }

                        

                        case 5:
                            {
                                string number;
                                string pin;
                                cout << "Enter your number please(or select 0 to cancel):\n";
                                cin >> number;
                                if(number == "0")
                                    {
                                        cout << "Operation cancelled\n";
                                        break;
                                    }
                                cout<< "Please enter your MoMo pin to check balance:\n";
                                cin >> pin;
                                User* found = findUserByNumber(users,number);
                                
                                if(found == nullptr)
                                    {
                                        cout << "No such user\n";
                                    }

                                else if(!found -> verifyPin(pin))
                                    {
                                        cout << "Wrong pin entered,Access unathorised\n";
                                    }

                                else
                                    {
                                        
                                        cout << "You have GHC "<<found->getAccount().getBalance()<< " in your wallet\n";
                                    }

                                break;
    
                            }

                        case 6:
                            {
                                string number;
                                string pin;
                                cout << "Enter your number please(or select 0 to cancel):\n";
                                cin >> number;
                                if(number == "0")
                                    {
                                        cout << "Operation cancelled\n";
                                        break;
                                    }
                                cout<< "Please enter your MoMo pin to check balance:\n";
                                cin >> pin;
                                User* found = findUserByNumber(users,number);
                                
                                if(found == nullptr)
                                    {
                                        cout << "No such user\n";
                                    }

                                else if(!found -> verifyPin(pin))
                                    {
                                        cout << "Wrong pin entered,Access unathorised\n";
                                    }

                                else
                                    {
                                        cout << "-----Transaction History-----\n";
                                        found->printHistory();
                                    }
                                break;
                            }


                        case 0:
                            {
                                cout <<"GoodBye then,you can stay in touch anytime\n";
                                break;
                            }

                        default:
                            {
                                cout << "Invalid choice,try again\n";
                                break;
                            }
                
                    }
                                }while(choice != 0);
    
    
    }