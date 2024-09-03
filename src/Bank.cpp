#include <iostream>

#include <Bank.hpp>

bool Bank::addCustomer(int card_id, int password){
    // check if customer already exists
    for (Customer customer : this->customers){
        if (customer.get_card_id() == card_id){
            std::cout << "Customer already exists." << std::endl;
            return false;
        }
    }

    // create new customer
    Customer new_customer(card_id, password);
    this->customers.push_back(new_customer);
    std::cout << "New customer added with ID " << card_id << " is created!" << std::endl;
    return true;
}

bool Bank::selectCustomer(int card_id, int password){
    for (int i=0; i<this->customers.size(); i++){
        if (this->customers[i].get_card_id() == card_id){
            if (this->customers[i].passwordCheck(password)){
                this->active_customer = &this->customers[i];
                std::cout << "Customer selected." << std::endl;
                return true;
            }
            else{
                std::cout << "Incorrect password." << std::endl;
                return false;
            }
        }
    }
    std::cout << "Customer not found." << std::endl;
    return false;
}