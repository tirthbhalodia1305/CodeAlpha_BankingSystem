#include "Transaction.h"
#include <iostream>
#include <iomanip>

using namespace std;

Transaction::Transaction(int id, const string& type,
                         double amount,
                         const string& dateTime,
                         const string& description)
    : transactionId(id), type(type), amount(amount),
      dateTime(dateTime), description(description) {}

void Transaction::display() const {
    cout << left
         << setw(8) << transactionId
         << setw(15) << type
         << setw(12) << fixed << setprecision(2) << amount
         << setw(22) << dateTime
         << description << '\n';
}
