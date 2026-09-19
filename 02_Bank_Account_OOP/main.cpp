#include <iostream>
#include <string>
#include <iomanip>
using namespace std;

class BankAccount {
private:
    string holderName;
    int accountNumber;
    double balance;

public:
    BankAccount(const string& name, int number, double initialBalance = 0.0)
        : holderName(name), accountNumber(number), balance(initialBalance) {}

    void deposit(double amount) {
        if (amount <= 0) {
            cout << "Deposit amount must be positive.\n";
            return;
        }
        balance += amount;
        cout << "Deposit successful.\n";
    }

    void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Withdrawal amount must be positive.\n";
        } else if (amount > balance) {
            cout << "Insufficient balance.\n";
        } else {
            balance -= amount;
            cout << "Withdrawal successful.\n";
        }
    }

    void display() const {
        cout << fixed << setprecision(2);
        cout << "\nAccount Holder: " << holderName
             << "\nAccount Number: " << accountNumber
             << "\nBalance: " << balance << "\n";
    }
};

int main() {
    string name;
    int number;
    double initialBalance;

    cout << "Enter account holder name: ";
    getline(cin, name);
    cout << "Enter account number: ";
    cin >> number;
    cout << "Enter initial balance: ";
    cin >> initialBalance;

    BankAccount account(name, number, initialBalance);

    int choice;
    do {
        cout << "\n--- Banking Menu ---\n";
        cout << "1. Deposit\n2. Withdraw\n3. Display Account\n4. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
            double amount;
            cout << "Enter deposit amount: ";
            cin >> amount;
            account.deposit(amount);
        } else if (choice == 2) {
            double amount;
            cout << "Enter withdrawal amount: ";
            cin >> amount;
            account.withdraw(amount);
        } else if (choice == 3) {
            account.display();
        } else if (choice != 4) {
            cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}
