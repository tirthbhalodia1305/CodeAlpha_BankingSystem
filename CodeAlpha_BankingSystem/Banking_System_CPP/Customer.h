#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <vector>

class Customer {
private:
    int customerId;
    std::string name;
    std::string phone;
    std::string email;
    std::vector<int> accountNumbers;

public:
    Customer(int id, const std::string& name,
             const std::string& phone,
             const std::string& email);

    int getCustomerId() const;
    std::string getName() const;
    std::string getPhone() const;
    std::string getEmail() const;

    void addAccount(int accountNumber);
    void displayCustomer() const;
};

#endif
