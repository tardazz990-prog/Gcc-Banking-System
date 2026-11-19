# GCC Banking System

**C++ Banking System – Gauteng City College (GCC)**

## 1. Project Overview

The GCC Banking System is a command-line banking application developed using C++ for the Introduction to Programming NQF Level 4 assignment.

The system allows customers to log in using their account number and PIN, perform basic banking transactions, and view their account balances.

## 2. Features

- Customer login with account number and PIN.
- Three login attempts before access is denied.
- Deposit money into an account.
- Withdraw money with insufficient-funds validation.
- Transfer money between registered accounts.
- Check account balance.
- Menu-driven interface.
- Input validation.
- Exit option.

## 3. Programming Concepts Used

The project demonstrates the following C++ programming concepts:

- **Variables and data types:** Used to store account information, PINs and balances.
- **Arrays:** Used to store multiple customers' information.
- **Functions:** Used to separate banking operations into manageable sections.
- **Loops:** Used for login attempts, account searching and menu repetition.
- **Decision making:** Uses `if`, `else` and `switch` statements.
- **Input validation:** Prevents invalid amounts and incorrect transactions.

## 4. Sample Test Accounts

| Account holder | Account number | PIN |
|---|---:|---:|
| Thabo Mokoena | 1001 | 1234 |
| Lerato Dlamini | 1002 | 4321 |
| John Smith | 1003 | 1111 |
| Aisha Patel | 1004 | 2222 |

*These are demonstration accounts for testing purposes only.*

## 5. How to Run the Program

1. Download or clone this repository.
2. Open `main.cpp` in a C++ development environment.
3. Compile the source code using a C++ compiler.
4. Run the generated application.
5. Log in using one of the sample accounts.

### Compile using GCC

```bash
g++ -std=c++17 main.cpp -o gcc_bank
```

Run on Windows:

```bash
gcc_bank.exe
```

## 6. Project File Structure

```text
Gcc-Banking-System/
│
├── main.cpp
└── README.md
```

## 7. Developer Information

**Institution:** Gauteng City College

**Qualification level:** NQF Level 4

**Subject:** Introduction to Programming

**Project:** GCC Banking System

**Language:** C++

## 8. Purpose of the Project

The purpose of this project is to demonstrate an understanding of fundamental programming principles by developing a functional banking application using C++.

---

**GCC Banking System – Introduction to Programming NQF 4**
