#include "Bank.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <chrono>
#include <ctime>
#include <sstream>

using namespace std;

Bank::Bank()
    : nextCustomerId(1001),
      nextAccountNumber(50001),
      nextTransactionId(1) {}

int Bank::findCustomerIndex(int customerId) const {
    for (int i = 0; i < static_cast<int>(customers.size()); ++i) {
        if (customers[i].getCustomerId() == customerId) {
            return i;
        }
    }
    return -1;
}

int Bank::findAccountIndex(int accountNumber) const {
    for (int i = 0; i < static_cast<int>(accounts.size()); ++i) {
        if (accounts[i].getAccountNumber() == accountNumber) {
            return i;
        }
    }
    return -1;
}

string Bank::getCurrentDateTime() const {
    auto now = chrono::system_clock::now();
    time_t currentTime = chrono::system_clock::to_time_t(now);

    tm localTime{};
#ifdef _WIN32
    localtime_s(&localTime, &currentTime);
#else
    localtime_r(&currentTime, &localTime);
#endif

    stringstream ss;
    ss << put_time(&localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

void Bank::createCustomer() {
    string name, phone, email;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "\nEnter customer name: ";
    getline(cin, name);

    cout << "Enter phone number: ";
    getline(cin, phone);

    cout << "Enter email: ";
    getline(cin, email);

    Customer customer(nextCustomerId, name, phone, email);
    customers.push_back(customer);

    cout << "\nCustomer created successfully!\n";
    cout << "Customer ID: " << nextCustomerId << '\n';

    ++nextCustomerId;
}

void Bank::createAccount() {
    if (customers.empty()) {
        cout << "\nPlease create a customer first.\n";
        return;
    }

    int customerId;
    string accountType;

    cout << "\nEnter Customer ID: ";
    cin >> customerId;

    int customerIndex = findCustomerIndex(customerId);

    if (customerIndex == -1) {
        cout << "Customer not found.\n";
        return;
    }

    cout << "Enter account type (Savings/Current): ";
    cin >> accountType;

    Account account(nextAccountNumber, customerId, accountType);
    accounts.push_back(account);
    customers[customerIndex].addAccount(nextAccountNumber);

    cout << "\nAccount created successfully!\n";
    cout << "Account Number: " << nextAccountNumber << '\n';

    ++nextAccountNumber;
}

void Bank::depositMoney() {
    int accountNumber;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accountNumber);

    if (accountIndex == -1) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter deposit amount: Rs. ";
    cin >> amount;

    if (accounts[accountIndex].deposit(
            amount, nextTransactionId++, getCurrentDateTime(), "Cash deposit")) {
        cout << "Deposit successful.\n";
        cout << "New Balance: Rs. "
             << fixed << setprecision(2)
             << accounts[accountIndex].getBalance() << '\n';
    } else {
        cout << "Invalid deposit amount.\n";
    }
}

void Bank::withdrawMoney() {
    int accountNumber;
    double amount;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accountNumber);

    if (accountIndex == -1) {
        cout << "Account not found.\n";
        return;
    }

    cout << "Enter withdrawal amount: Rs. ";
    cin >> amount;

    if (accounts[accountIndex].withdraw(
            amount, nextTransactionId++, getCurrentDateTime(), "Cash withdrawal")) {
        cout << "Withdrawal successful.\n";
        cout << "New Balance: Rs. "
             << fixed << setprecision(2)
             << accounts[accountIndex].getBalance() << '\n';
    } else {
        cout << "Withdrawal failed. Check amount or available balance.\n";
    }
}

void Bank::transferFunds() {
    int fromAccount, toAccount;
    double amount;

    cout << "\nEnter sender account number: ";
    cin >> fromAccount;

    cout << "Enter receiver account number: ";
    cin >> toAccount;

    if (fromAccount == toAccount) {
        cout << "Sender and receiver accounts must be different.\n";
        return;
    }

    int fromIndex = findAccountIndex(fromAccount);
    int toIndex = findAccountIndex(toAccount);

    if (fromIndex == -1 || toIndex == -1) {
        cout << "One or both accounts were not found.\n";
        return;
    }

    cout << "Enter transfer amount: Rs. ";
    cin >> amount;

    if (amount <= 0 || amount > accounts[fromIndex].getBalance()) {
        cout << "Transfer failed. Invalid amount or insufficient balance.\n";
        return;
    }

    string dateTime = getCurrentDateTime();
    int debitId = nextTransactionId++;
    int creditId = nextTransactionId++;

    bool withdrawn = accounts[fromIndex].withdraw(
        amount, debitId, dateTime,
        "Transfer to A/C " + to_string(toAccount)
    );

    if (!withdrawn) {
        cout << "Transfer failed.\n";
        return;
    }

    bool deposited = accounts[toIndex].deposit(
        amount, creditId, dateTime,
        "Transfer from A/C " + to_string(fromAccount)
    );

    if (!deposited) {
        // Rollback is intentionally avoided by design because validation
        // happens before the withdrawal. This branch should not be reached.
        cout << "Transfer failed unexpectedly.\n";
        return;
    }

    cout << "Transfer successful!\n";
    cout << "Rs. " << fixed << setprecision(2) << amount
         << " transferred from " << fromAccount
         << " to " << toAccount << ".\n";
}

void Bank::displayAccountInformation() {
    int accountNumber;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accountNumber);

    if (accountIndex == -1) {
        cout << "Account not found.\n";
        return;
    }

    accounts[accountIndex].displayAccountInfo();

    int customerIndex =
        findCustomerIndex(accounts[accountIndex].getCustomerId());

    if (customerIndex != -1) {
        customers[customerIndex].displayCustomer();
    }
}

void Bank::displayRecentTransactions() {
    int accountNumber, count;

    cout << "\nEnter Account Number: ";
    cin >> accountNumber;

    int accountIndex = findAccountIndex(accountNumber);

    if (accountIndex == -1) {
        cout << "Account not found.\n";
        return;
    }

    cout << "How many recent transactions? ";
    cin >> count;

    if (count <= 0) {
        cout << "Invalid number of transactions.\n";
        return;
    }

    accounts[accountIndex].displayRecentTransactions(count);
}

void Bank::displayAllCustomers() {
    cout << "\n========== ALL CUSTOMERS ==========\n";

    if (customers.empty()) {
        cout << "No customers registered.\n";
        return;
    }

    for (const Customer& customer : customers) {
        customer.displayCustomer();
        cout << "-----------------------------------\n";
    }
}
