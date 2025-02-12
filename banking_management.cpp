#include <iostream>
#include <vector>
#include <iomanip>
 
using namespace std;
 
class Account {
    int acno;
    string name;
    int balance;
    char type;
 
public:
    void createAccount();
    void displayAccount() const;
    void deposit(int);
    void withdraw(int);
    int getAccountNo() const { return acno; }
};
 
void Account::createAccount() {
    cout << "\nEnter Account No: ";
    cin >> acno;
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, name);
    cout << "Enter Account Type (S/C): ";
    cin >> type;
    cout << "Enter Initial Deposit: ";
    cin >> balance;
    cout << "Account Created Successfully!\n";
}
 
void Account::displayAccount() const {
    cout << "\nAccount No: " << acno
<< "\nName: " << name
<< "\nType: " << type
<< "\nBalance: $" << balance << "\n";
}
 
void Account::deposit(int amount) {
    balance += amount;
    cout << "Amount Deposited Successfully!\n";
}
 
void Account::withdraw(int amount) {
    if (balance >= amount) {
        balance -= amount;
        cout << "Amount Withdrawn Successfully!\n";
    } else {
        cout << "Insufficient Balance!\n";
    }
}
 
vector<Account> accounts;
 
void createAccount() {
    Account acc;
    acc.createAccount();
    accounts.push_back(acc);
}
 
void displayAllAccounts() {
    if (accounts.empty()) {
        cout << "No accounts found!\n";
        return;
    }
    for (const auto& acc : accounts) {
        acc.displayAccount();
    }
}
 
void depositAmount() {
    int acno, amount;
    cout << "Enter Account No: ";
    cin >> acno;
    for (auto& acc : accounts) {
        if (acc.getAccountNo() == acno) {
            cout << "Enter Amount to Deposit: ";
            cin >> amount;
            acc.deposit(amount);
            return;
        }
    }
    cout << "Account Not Found!\n";
}
 
void withdrawAmount() {
    int acno, amount;
    cout << "Enter Account No: ";
    cin >> acno;
    for (auto& acc : accounts) {
        if (acc.getAccountNo() == acno) {
            cout << "Enter Amount to Withdraw: ";
            cin >> amount;
            acc.withdraw(amount);
            return;
        }
    }
    cout << "Account Not Found!\n";
}
 
int main() {
    char choice;
    do {
        cout << "\n--- Bank Management System ---\n";
        cout << "1. Create Account\n2. Deposit\n3. Withdraw\n4. View All Accounts\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
 
        switch (choice) {
            case '1': createAccount(); break;
            case '2': depositAmount(); break;
            case '3': withdrawAmount(); break;
            case '4': displayAllAccounts(); break;
            case '5': cout << "Exiting...\n"; break;
            default: cout << "Invalid Choice! Try again.\n";
        }
    } while (choice != '5');
 
    return 0;
}