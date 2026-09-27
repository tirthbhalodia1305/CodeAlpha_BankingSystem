#ifndef BANK_H
#define BANK_H

#include <vector>
#include "Customer.h"
#include "Account.h"

class Bank {
private:
    std::vector<Customer> customers;
    std::vector<Account> accounts;

    int nextCustomerId;
    int nextAccountNumber;
    int nextTransactionId;

    int findCustomerIndex(int customerId) const;
    int findAccountIndex(int accountNumber) const;
    std::string getCurrentDateTime() const;

public:
    Bank();

    void createCustomer();
    void createAccount();
    void depositMoney();
    void withdrawMoney();
    void transferFunds();
    void displayAccountInformation();
    void displayRecentTransactions();
    void displayAllCustomers();
};

#endif
