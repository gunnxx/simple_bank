#include <Account.hpp>

Account::Account(int account_id, int balance){
    this->account_id = account_id;
    this->balance = balance;
}

int Account::get_account_id(){
    return this->account_id;
}

int Account::getBalance(){
    return this->balance;
}

void Account::deposit(int amount){
    this->balance += amount;
}

void Account::withdraw(int amount){
    this->balance -= amount;
}