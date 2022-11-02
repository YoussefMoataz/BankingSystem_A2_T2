//
// Created by Youssef Moataz on 10/27/2022.
//
#include "BankingSystemHeader.h"

// Youssef
BankApplication::BankApplication() {

    bool validMenuOption = false;
    string selectedMenuOption;
    
    while (!validMenuOption) {

        cout << "Welcome to FCAI Banking Application " << endl <<
             "1. Create a New Account " << endl <<
             "2. List Clients and Accounts " << endl <<
             "3. Withdraw Money " << endl <<
             "4. Deposit Money" << endl <<
             "5. Exit" << endl <<
             "Please Enter Choice =========> ";

        cin >> selectedMenuOption;

        if (selectedMenuOption == "1") {
            // create new account

string      clientName;
            cout << "Please Enter Client Name =========> ";
            cin >> clientName;

            string clientAddress;
            cout << "Please Enter Client Address =======> ";
            cin >> clientAddress;

            string clientPhone;
            cout << "Please Enter Client Phone =======> ";
            cin >> clientPhone;

            string clientAccountType;
            cout << "What Type of Account Do You Like? (1) Basic (2) Saving - Type 1 or 2 =========> ";
            cin >> clientAccountType;

            string clientStartingBalance;
            cout << "Please Enter the Starting Balance =========> ";
            cin >> clientStartingBalance;

            BankAccount bankAccount = SavingBankAccount(stod(clientStartingBalance));
            
            cout << "An account was created with ID " << bankAccount.getID() << 
            " and Starting Balance " << bankAccount.getBalance() << " L.E." << endl;


        } else if (selectedMenuOption == "2") {
            // show all clients and accounts



        } else if (selectedMenuOption == "3") {
            // withdraw

        } else if (selectedMenuOption == "4") {
            // deposit

        } else if (selectedMenuOption == "5") {
            // exit
            exit(0);
        } else {
            // invalid option
            cout << endl << "Enter a valid option !" << endl;
        }

    }


}

// // Youssef
// bool BankApplication::addClient() {

// }

// Youssef
Client::Client(string name, string address, string phone) {

    this->Name = name;
    this->Address = address;
    this->Phone = phone;

}

// mohamed 
// constructors
BankAccount::BankAccount() 
{
    counter++;
    AccountID = "FCAI-" + to_string(counter);
    Balance = 0;
}
BankAccount::BankAccount(double Balance)
{
    counter++;
    AccountID = "FCAI-" + to_string(counter);
    this->Balance = Balance;
}

// withdraw and deposit
int BankAccount::withdraw(double amount) 
{
    if (Balance >= amount)
    {
        Balance -= amount;
        return 1;
    }
    else
    {
        return 0;
    }
}
int BankAccount::deposit(double amount) 
{
    Balance += amount;
    return 1;
}

// getters and setters
double BankAccount::getBalance()
{
    return Balance;
}
string BankAccount::getID()
{
    return AccountID;
}
void BankAccount::setBalance(double Balance)
{
    this->Balance = Balance;
}

SavingBankAccount::SavingBankAccount(double Balance):BankAccount(Balance) {
    while (Balance<MinimumBalance){
        cout<<"saving accounts require a minimum starting balance of"<<MinimumBalance<<endl;
        cout<<"Please enter valid starting balance:";
        cin>>Balance;
    }
    this->Balance = Balance;
    
}

int SavingBankAccount::withdraw(double amount) {
    if((amount-Balance)<MinimumBalance){
        return 0;
    }
    else{
        Balance-=amount;
        return 1;
    }

}

int SavingBankAccount::deposit(double amount) {
    if(amount>=100){
        Balance+=amount;
        return 1;
    }
    else{
        return 0;
    }
}

void SavingBankAccount::setMinimumBalance(){

}

// Youssef
void printDashes() {
    cout << string(20, '-') << endl;
}

// End of the file