/* 
 * File:   BankAccount.cpp
 * Purpose: Class that holds the user's information
 * Created on March 23, 2025 6:25 PM
 */

#include "BankAccount.h"


BankAccount::BankAccount(){ // default constructor
    accountNumber = "12345";
    balance = 0;
}

BankAccount::BankAccount(string accN, double initBal) { // initializing account
    accountNumber = accN;
    balance = initBal;
    isActive = true;
    cout << "Bank Account Created: #" << accountNumber << "\n";
}

void BankAccount::deposit(double amount){ // deposit money into the account
    if(!isActive){ // if there's an existing account
        throw InvalidAccountOperationException();
    }
    if(amount<0){ // if the entered amount is less than 0
        throw NegativeDepositException();
    }
    balance += amount;
    cout<<"Depositing $"<<amount<<"...\n"; // aftercare message!
}

void BankAccount::withdraw(double amount){ // withdraw money into the account
    if(!isActive){
        throw InvalidAccountOperationException();
    }
    if(balance<amount){
        throw OverdrawException();
    }
    balance -= amount;
    cout<<"Withdrawing $"<<amount<<"...\n";
}

int BankAccount::getBalance(){ // get money total from the account
    if(!isActive){
        throw InvalidAccountOperationException();
    }
    return balance;
}

void BankAccount::closeAcc(){ // closing the existing account
    isActive = false;
    cout<<"Closing the Account...\n";
}



