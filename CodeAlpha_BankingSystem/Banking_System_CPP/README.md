# 🏦 Banking System in C++

A console-based **Banking System** developed in C++ using Object-Oriented Programming (OOP) concepts.

This project was created as a banking management system that allows users to create customers and accounts, perform transactions, transfer funds, and view account and transaction information.

## ✨ Features

- Create and manage customers
- Create Savings or Current accounts
- Deposit money
- Withdraw money
- Transfer funds between accounts
- Store transaction history
- View recent transactions
- Display account information
- Display customer information
- Input validation for transactions
- Automatic transaction IDs
- Automatic account and customer IDs
- Date and time recorded for every transaction

## 🧱 Project Structure

```text
Banking_System_CPP/
│
├── main.cpp
├── Bank.h
├── Bank.cpp
├── Customer.h
├── Customer.cpp
├── Account.h
├── Account.cpp
├── Transaction.h
├── Transaction.cpp
├── README.md
├── .gitignore
└── sample_output.txt
```

## 🛠️ Technologies Used

- C++
- Object-Oriented Programming
- STL `vector`
- File organization using `.h` and `.cpp` files
- Console-based user interface

## 📚 OOP Concepts Used

### 1. Encapsulation
Customer, Account, Transaction, and Bank classes keep their data private and expose required operations through public methods.

### 2. Classes and Objects
The project uses four main classes:

- `Customer`
- `Account`
- `Transaction`
- `Bank`

### 3. Composition
An Account contains a collection of Transaction objects, while a Customer can have multiple accounts.

### 4. Abstraction
Banking operations such as deposit, withdrawal, and fund transfer are provided through simple functions without exposing internal implementation details.

## ▶️ How to Run

### Using g++

Open a terminal inside the project folder and run:

```bash
g++ main.cpp Bank.cpp Customer.cpp Account.cpp Transaction.cpp -o banking_system
```

Run the program:

### Windows

```bash
banking_system.exe
```

### Linux/macOS

```bash
./banking_system
```

## 💻 Main Menu

```text
========== BANKING SYSTEM ==========
1. Create Customer
2. Create Account
3. Deposit Money
4. Withdraw Money
5. Transfer Funds
6. View Account Information
7. View Recent Transactions
8. View All Customers
9. Exit
====================================
```

## 🔄 Example Workflow

1. Create a customer.
2. Create an account using the customer ID.
3. Deposit money into the account.
4. Withdraw money when required.
5. Create another account/customer.
6. Transfer money between accounts.
7. View account balance and customer details.
8. View recent transaction history.

## ⚠️ Note

This is an educational console project. It does not connect to a real bank database or financial system. Data exists only while the program is running.

## 👨‍💻 Author

**Tirth Bhalodia**

Electronics & Telecommunication Engineering Student

GitHub: `https://github.com/tirthbhalodia1305`

## 📌 Future Improvements

- Add file/database storage
- Add login and authentication
- Add PIN/password protection
- Add transaction search by date
- Add account deletion
- Add interest calculation for savings accounts
- Add monthly bank statements
- Add GUI using Qt or another C++ framework
