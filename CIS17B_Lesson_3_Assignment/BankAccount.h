/* 
 * File:   BankAccount.h
 * Created on March 23, 2025 6:25 PM
 */

// defining the class
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

#include <string> // to allow string variables, etc
#include <iomanip> // standard for text outputs
#include <iostream> // standard lib
#include <stdexcept> // from starter code & for exception handling
#include <memory> // for the smart pointers, etc

using namespace std;

class BankAccount { // Contains variables and member functions for BankAccount
    
    public: // all the functions that will be used within the main program
        BankAccount(); // default constructor
        BankAccount(string accN,double initBal); // constructor
        void deposit(double amount); // deposits money within the account
        void withdraw(double amount); // withdraws from the account
        int getBalance(); // retrieves the private variable balance and returns it
        void closeAcc(); // this will close the account the user is working with
        
        
    private: // all private variables that can be accessed by class member functions
        string accountNumber;
        double balance;
        bool isActive;

};

// ADDED ALL OTHER CLASSES FOR EXCEPTION HANDLING BELOW
class NegativeDepositException : public runtime_error { // Exception Handling for Negative Amounts
    public:
        NegativeDepositException() : runtime_error("System Failure: A Negative Amount was Returned, Action not Possible. \n") {}
};

class OverdrawException : public runtime_error { // Exception Handling for Amounts Greater than User's Bank
    public:
        OverdrawException() : runtime_error("System Failure: Your funds were insufficient, Action not Possible. \n") {}
};

class InvalidAccountOperationException : public runtime_error { // Exception Handling for Closed accounts
    public:
        InvalidAccountOperationException() : runtime_error("System Failure: This account is nonexistent. Actions made to the account were not Possible. \n") {}   
};

#endif /* terminators for the classes */

