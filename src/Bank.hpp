#include <vector>

#include <Customer.hpp>

#ifndef BANK_HPP
#define BANK_HPP

class Bank{
    public:        
        bool addCustomer(int card_id, int password);
        bool selectCustomer(int card_id, int password);
        Customer* active_customer;

    private:
        std::vector<Customer> customers;
};

#endif