#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <string>

class Transaction {
private:
    int transactionId;
    std::string type;
    double amount;
    std::string dateTime;
    std::string description;

public:
    Transaction(int id, const std::string& type,
                double amount,
                const std::string& dateTime,
                const std::string& description);

    void display() const;
};

#endif
