#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>
#include "Transaction.h"

class Account {
private:
    int accountNumber;
    int customerId;
    std::string accountType;
    double balance;
    std::vector<Transaction> transactions;

public:
    Account(int accountNumber, int customerId,
            const std::string& accountType);

    int getAccountNumber() const;
    int getCustomerId() const;
    double getBalance() const;

    bool deposit(double amount, int transactionId,
                 const std::string& dateTime,
                 const std::string& description);

    bool withdraw(double amount, int transactionId,
                  const std::string& dateTime,
                  const std::string& description);

    void addTransaction(const Transaction& transaction);
    void displayAccountInfo() const;
    void displayRecentTransactions(int count = 5) const;
};

#endif
