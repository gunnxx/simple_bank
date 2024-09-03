#include <iostream>

#include <Account.hpp>
#include <Customer.hpp>


Customer::Customer(int card_id, int password){
    this->card_id = card_id;
    this->password = password;
}

int Customer::get_card_id(){
    return this->card_id;
}

bool Customer::passwordCheck(int password){
    if(this->password == password && this->password_attempt < 3){
        this->password_attempt = 0;
        return true;
    }
    else{
        this->password_attempt++;
        if (this->password_attempt >= 3){
            std::cout << "Too many failed password attempts. Card locked." << std::endl;
            return false;
        }
        return false;
    }
}

bool Customer::setPassword(int old_password, int new_password){
    if(this->password == old_password && this->password_attempt < 3){
        this->password = new_password;
        this->password_attempt = 0;
        std::cout << "Password changed." << std::endl;
        return true;
    }
    else{
        this->password_attempt++;
        if (this->password_attempt >= 3)
            std::cout << "Too many failed password attempts. Card locked." << std::endl;
        else
            std::cout << "Incorrect password." << std::endl;
        return false;
    }
}

bool Customer::createAccount(int account_id, int balance){
    // check if account already exists
    for (Account account : this->accounts){
        if (account.get_account_id() == account_id){
            std::cout << "Account already exists." << std::endl;
            return false;
        }
    }

    // create new account
    Account new_account(account_id, balance);
    this->accounts.push_back(new_account);
    return true;
}

std::vector<int> Customer::getAccountIDs(){
    std::vector<int> account_ids;
    for (Account account : this->accounts){
        account_ids.push_back(account.get_account_id());
    }
    return account_ids;
}


bool Customer::selectAccount(int account_id){
    for (int i=0; i<this->accounts.size(); i++){
        if (this->accounts[i].get_account_id() == account_id){
            this->active_account = &this->accounts[i];
            std::cout << "Account selected." << std::endl;
            return true;
        }
    }
    std::cout << "Account not found." << std::endl;
    return false;
}