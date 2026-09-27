#include "Account.h"
#include <iostream>
#include <iomanip>
#include <algorithm>

using namespace std;

Account::Account(int accountNumber, int customerId,
                 const string& accountType)
    : accountNumber(accountNumber), customerId(customerId),
      accountType(accountType), balance(0.0) {}

int Account::getAccountNumber() const {
    return accountNumber;
}

int Account::getCustomerId() const {
    return customerId;
}

double Account::getBalance() const {
    return balance;
}

bool Account::deposit(double amount, int transactionId,
                      const string& dateTime,
                      const string& description) {
    if (amount <= 0) {
        return false;
    }

    balance += amount;
    transactions.emplace_back(
        transactionId, "DEPOSIT", amount, dateTime, description
    );
    return true;
}

bool Account::withdraw(double amount, int transactionId,
                       const string& dateTime,
                       const string& description) {
    if (amount <= 0 || amount > balance) {
        return false;
    }

    balance -= amount;
    transactions.emplace_back(
        transactionId, "WITHDRAW", amount, dateTime, description
    );
    return true;
}

void Account::addTransaction(const Transaction& transaction) {
    transactions.push_back(transaction);
}

void Account::displayAccountInfo() const {
    cout << "\n========== ACCOUNT INFORMATION ==========\n";
    cout << "Account Number : " << accountNumber << '\n';
    cout << "Customer ID    : " << customerId << '\n';
    cout << "Account Type   : " << accountType << '\n';
    cout << "Balance        : Rs. " << fixed << setprecision(2)
         << balance << '\n';
    cout << "=========================================\n";
}

void Account::displayRecentTransactions(int count) const {
    cout << "\n================ RECENT TRANSACTIONS ================\n";

    if (transactions.empty()) {
        cout << "No transactions found.\n";
        return;
    }

    cout << left
         << setw(8) << "ID"
         << setw(15) << "TYPE"
         << setw(12) << "AMOUNT"
         << setw(22) << "DATE/TIME"
         << "DESCRIPTION\n";

    int start = max(0, static_cast<int>(transactions.size()) - count);

    for (int i = start; i < static_cast<int>(transactions.size()); ++i) {
        transactions[i].display();
    }
}
