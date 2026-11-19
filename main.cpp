
#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>
#include <cmath>

using namespace std;

// Maximum number of bank users
const int MAX_USERS = 5;
const int MAX_ATTEMPTS = 3;

// Parallel arrays to store customer information
string names[MAX_USERS] = {
    "Thabo Mokoena",
    "Lerato Dlamini",
    "John Smith",
    "Aisha Patel"
};

int accountNumbers[MAX_USERS] = {
    1001, 1002, 1003, 1004
};

int pins[MAX_USERS] = {
    1234, 4321, 1111, 2222
};

double balances[MAX_USERS] = {
    5000.00, 2500.50, 10000.00, 750.25
};

int userCount = 4;

// Function declarations
void displayMenu();
int findAccountIndex(int accountNumber);
int login();
int readInt(string message);
double readAmount(string message);
void deposit(int index);
void withdraw(int index);
void sendCash(int senderIndex);
void checkBalance(int index);


// Main function
int main()
{
    cout << "====================================\n";
    cout << "          WELCOME TO GCC BANK       \n";
    cout << "====================================\n";

    int currentUser = login();

    if (currentUser == -1)
    {
        cout << "\nLogin failed. Access denied.\n";
        return 0;
    }

    int choice;

    // Menu repeats until the user chooses Exit
    do
    {
        displayMenu();

        choice = readInt("Enter your choice: ");

        switch (choice)
        {
        case 1:
            deposit(currentUser);
            break;

        case 2:
            withdraw(currentUser);
            break;

        case 3:
            sendCash(currentUser);
            break;

        case 4:
            checkBalance(currentUser);
            break;

        case 5:
            cout << "\nThank you for banking with GCC BANK!\n";
            break;

        default:
            cout << "\nInvalid option. Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}


// Displays the banking menu
void displayMenu()
{
    cout << "\n========== GCC BANK MENU ==========\n";
    cout << "1. Deposit Money\n";
    cout << "2. Withdraw Money\n";
    cout << "3. Send Cash\n";
    cout << "4. Check Balance\n";
    cout << "5. Exit\n";
    cout << "===================================\n";
}


// Searches for an account number
int findAccountIndex(int accountNumber)
{
    for (int i = 0; i < userCount; i++)
    {
        if (accountNumbers[i] == accountNumber)
        {
            return i;
        }
    }

    return -1;
}


// Handles customer login
int login()
{
    int accountNumber;
    int enteredPin;

    for (int attempt = 1; attempt <= MAX_ATTEMPTS; attempt++)
    {
        cout << "\nLogin Attempt " << attempt
            << " of " << MAX_ATTEMPTS << endl;

        accountNumber = readInt("Enter account number: ");
        enteredPin = readInt("Enter your PIN: ");

        int index = findAccountIndex(accountNumber);

        if (index != -1 && pins[index] == enteredPin)
        {
            cout << "\nLogin successful!";
            cout << "\nWelcome, " << names[index] << "!\n";

            return index;
        }

        cout << "\nIncorrect account number or PIN.\n";
    }

    return -1;
}


// Reads and validates integer input
int readInt(string message)
{
    string input;
    int value;
    char extra;

    while (true)
    {
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> value && !(ss >> extra))
        {
            return value;
        }

        cout << "Invalid input. Please enter a whole number.\n";
    }
}


// Reads and validates positive monetary amounts
double readAmount(string message)
{
    string input;
    double amount;
    char extra;

    while (true)
    {
        cout << message;
        getline(cin, input);

        stringstream ss(input);

        if (ss >> amount &&
            !(ss >> extra) &&
            isfinite(amount) &&
            amount > 0)
        {
            return amount;
        }

        cout << "Invalid amount. Enter a number greater than zero.\n";
    }
}


// Deposits money into an account
void deposit(int index)
{
    double amount = readAmount("Enter deposit amount: R");

    balances[index] += amount;

    cout << fixed << setprecision(2);
    cout << "\nDeposit successful!\n";
    cout << "Amount deposited: R" << amount << endl;
    cout << "New balance: R" << balances[index] << endl;
}


// Withdraws money from an account
void withdraw(int index)
{
    double amount = readAmount("Enter withdrawal amount: R");

    if (amount <= balances[index])
    {
        balances[index] -= amount;

        cout << fixed << setprecision(2);
        cout << "\nWithdrawal successful!\n";
        cout << "Amount withdrawn: R" << amount << endl;
        cout << "Remaining balance: R" << balances[index] << endl;
    }
    else
    {
        cout << "\nInsufficient funds. Transaction declined.\n";
    }
}


// Transfers money between bank accounts
void sendCash(int senderIndex)
{
    int recipientAccount;

    recipientAccount = readInt("Enter recipient account number: ");

    int recipientIndex = findAccountIndex(recipientAccount);

    if (recipientIndex == -1)
    {
        cout << "\nRecipient account does not exist.\n";
        return;
    }

    double amount = readAmount("Enter amount to send: R");

    if (amount > balances[senderIndex])
    {
        cout << "\nInsufficient funds. Transfer declined.\n";
        return;
    }

    balances[senderIndex] -= amount;
    balances[recipientIndex] += amount;

    cout << fixed << setprecision(2);
    cout << "\nTransfer successful!\n";
    cout << "Recipient: " << names[recipientIndex] << endl;
    cout << "Amount sent: R" << amount << endl;
    cout << "Your remaining balance: R"
        << balances[senderIndex] << endl;
}


// Displays the customer's account balance
void checkBalance(int index)
{
    cout << fixed << setprecision(2);

    cout << "\n========== ACCOUNT DETAILS ==========\n";
    cout << "Account holder: " << names[index] << endl;
    cout << "Account number: " << accountNumbers[index] << endl;
    cout << "Available balance: R" << balances[index] << endl;
    cout << "=====================================\n";
}
