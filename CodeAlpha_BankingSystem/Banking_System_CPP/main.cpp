#include <iostream>
#include <limits>
#include "Bank.h"

using namespace std;

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    Bank bank;
    int choice;

    do {
        cout << "\n========== BANKING SYSTEM ==========\n";
        cout << "1. Create Customer\n";
        cout << "2. Create Account\n";
        cout << "3. Deposit Money\n";
        cout << "4. Withdraw Money\n";
        cout << "5. Transfer Funds\n";
        cout << "6. View Account Information\n";
        cout << "7. View Recent Transactions\n";
        cout << "8. View All Customers\n";
        cout << "9. Exit\n";
        cout << "====================================\n";
        cout << "Enter your choice: ";

        if (!(cin >> choice)) {
            clearInput();
            cout << "Invalid input. Please enter a number.\n";
            continue;
        }

        switch (choice) {
            case 1:
                bank.createCustomer();
                break;
            case 2:
                bank.createAccount();
                break;
            case 3:
                bank.depositMoney();
                break;
            case 4:
                bank.withdrawMoney();
                break;
            case 5:
                bank.transferFunds();
                break;
            case 6:
                bank.displayAccountInformation();
                break;
            case 7:
                bank.displayRecentTransactions();
                break;
            case 8:
                bank.displayAllCustomers();
                break;
            case 9:
                cout << "Thank you for using the Banking System!\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 9);

    return 0;
}
