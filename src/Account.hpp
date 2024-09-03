#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

class Account{
    public:
        Account(int account_id, int balance);
        int get_account_id();
        int getBalance();
        void deposit(int amount);
        void withdraw(int amount);

    private:
        int account_id;
        int balance;
};

#endif