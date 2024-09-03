#include <Bank.hpp>

int main(){
    Bank bank;
    
    // add a bunch of customers
    bank.addCustomer(1234, 1234); // new customer
    bank.addCustomer(1234, 4112); // duplicate customer
    bank.addCustomer(2345, 2345); // new customer

    // select a customer
    bank.selectCustomer(1234, 2432); // wrong password 1
    bank.selectCustomer(1234, 2432); // wrong password 2
    bank.selectCustomer(1234, 2432); // wrong password 3 (account locked)
    bank.selectCustomer(2345, 2345); // correct password

    // create a bunch of accounts
    bank.active_customer->createAccount(1, 1000);
    bank.active_customer->createAccount(2, 2000);

    // select an account
    bank.active_customer->selectAccount(1);

    // deposit and withdraw
    bank.active_customer->active_account->deposit(1000);
    bank.active_customer->active_account->withdraw(500);

    // select another account
    bank.active_customer->selectAccount(2);

    // deposit and withdraw
    bank.active_customer->active_account->deposit(1000);
    bank.active_customer->active_account->withdraw(500);

    return 0;
}