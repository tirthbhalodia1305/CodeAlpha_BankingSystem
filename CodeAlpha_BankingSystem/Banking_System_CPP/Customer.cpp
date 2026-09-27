#include "Customer.h"
#include <iostream>

using namespace std;

Customer::Customer(int id, const string& name,
                   const string& phone,
                   const string& email)
    : customerId(id), name(name), phone(phone), email(email) {}

int Customer::getCustomerId() const {
    return customerId;
}

string Customer::getName() const {
    return name;
}

string Customer::getPhone() const {
    return phone;
}

string Customer::getEmail() const {
    return email;
}

void Customer::addAccount(int accountNumber) {
    accountNumbers.push_back(accountNumber);
}

void Customer::displayCustomer() const {
    cout << "\nCustomer ID : " << customerId << '\n';
    cout << "Name        : " << name << '\n';
    cout << "Phone       : " << phone << '\n';
    cout << "Email       : " << email << '\n';
    cout << "Accounts    : ";

    if (accountNumbers.empty()) {
        cout << "No accounts";
    } else {
        for (int account : accountNumbers) {
            cout << account << " ";
        }
    }
    cout << '\n';
}
