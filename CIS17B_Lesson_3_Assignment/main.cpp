/* 
 * File:   main.cpp
 * Author: Emma Wuysang
 * Creator Notes: Works as required. V2 from our first program
 * Created on March 23, 2025 6:25 PM
 * Purpose: Develop a Simple Banking System V2
 */

//System Libraries
#include <iostream> //Input-Output Library
#include <string> // to utilize the strings
#include <memory> // for the smart pointers, etc
#include <limits>  // For numeric_limits
#include "BankAccount.h" // to access the other class BankAccount
using namespace std;

//Program Execution Begins Here
int main() {
    
    // Variables
    int slctn; // selection tool for menu
    double initialB; // initial balance
    double amount; // amount to deposit
    bool validInput = false; // for beginning balance
    
    // Beginning & Menu
    try{
        cout<<"Welcome to V2 Simple Bank System\n";
        while(!validInput){
            cout<<"Enter an initial balance: "; // prompts user for an account balance
            cin>>initialB;
            if (cin.fail() || initialB < 0){ // USER INPUT HANDLING.
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "That was not a valid input. The input must be a number above 0 \n";
                }
            else{
                validInput = true; // user entered a valid number
            }
        }
        // initializing the first account using smart pointers
        auto account = make_unique<BankAccount>("654321",initialB);
        
        while(slctn!=5){
            // menu for banking program
            cout << "1. Deposit Money\n"
            << "2. Withdraw Money\n"
            << "3. Check Balance\n"
            << "4. Close Account\n"
            << "5. Exit\n\n"
            << "Enter your choice: ";
            cin>>slctn; // selection

            if (cin.fail()){ // USER INPUT HANDLING.
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "That was not a number. OPTIONS (1-5) \n";
            }
            
            try {
                switch (slctn){

                    case 1: // DEPOSIT
                        cout << "Enter amount to deposit: ";
                            cin>>amount; //deposit amount
                            account->deposit(amount);
                            cout <<"System Update: Deposit successfully went through! New Balance: $"<<account->getBalance()<<endl;
                            break; // end of case 1


                    case 2: // WITHDRAW
                        cout << "Enter amount to withdraw: ";
                            cin>>amount; //deposit amount
                            account->withdraw(amount);
                            cout<<"System Update: Withdrawal successfully went through! New Balance: $"<<account->getBalance()<<endl;
                            break; // end of case 2


                    case 3: // CHECK BALANCES
                        cout<<"Balance: $"<<account->getBalance()<<endl;
                        break; // end of case 3


                    case 4: // CLOSE ACCOUNT
                        account->closeAcc();
                        cout << "System Update: Your account has been closed. No changes made to the account will be processed anymore.\n";
                        break; // end of case 4

                    case 5: cout<<"Thank you for using V2 Simple Bank System!\n"; break; // exiting the menu

                    default: cout << "Oh no! You choose an invalid choice, please try again. \n\n"; // if the user enters a non-numerical value.
                } 
            }
            catch (const exception& e) {
            cerr << "Error: " << e.what() << endl;
            }
        } 
    }catch (const exception& e){
        cerr << "Error: " << e.what() << endl;
    }
            
    
    //Exit the program
    return 0;
}