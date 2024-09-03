#include <vector>

#include <Account.hpp>

#ifndef CUSTOMER_HPP
#define CUSTOMER_HPP

class Customer{
    public:
        Customer(int card_id, int password);
        int get_card_id();
        
        bool passwordCheck(int password);
        bool setPassword(int old_password, int new_password);

        bool createAccount(int account_id, int balance);
        std::vector<int> getAccountIDs();
        bool selectAccount(int account_id);

        Account* active_account;

    private:
        int card_id;
        int password;
        int password_attempt = 0;
        std::vector<Account> accounts;
};

#endif