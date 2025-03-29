/* banking_system.cpp */
#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

class Account {
private:
    string name;
    long accountNumber;
    double balance;
    
public:
    Account(string n, long accNum, double bal) : name(n), accountNumber(accNum), balance(bal) {}
    
    void deposit(double amount) {
        balance += amount;
        cout << "Deposit successful. New balance: $" << fixed << setprecision(2) << balance << endl;
    }
    
    void withdraw(double amount) {
        if (amount > balance) {
            cout << "Insufficient funds!" << endl;
        } else {
            balance -= amount;
            cout << "Withdrawal successful. New balance: $" << fixed << setprecision(2) << balance << endl;
        }
    }
    
    void display() const {
        cout << "\nAccount Details:" << endl;
        cout << "Name: " << name << endl;
        cout << "Account Number: " << accountNumber << endl;
        cout << "Balance: $" << fixed << setprecision(2) << balance << endl;
    }
    
    long getAccountNumber() const { return accountNumber; }
};

int main() {
    vector<Account> accounts;
    int choice;
    long accNum;
    double amount;
    string name;
    
    cout << "Banking System\n";
    cout << "--------------\n";
    
    while (true) {
        cout << "\n1. Create Account\n2. Deposit\n3. Withdraw\n4. Display Account\n5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1: {
                cout << "Enter name: ";
                cin.ignore();
                getline(cin, name);
                cout << "Enter initial deposit: $";
                cin >> amount;
                Account newAccount(name, 1000 + accounts.size(), amount);
                accounts.push_back(newAccount);
                cout << "Account created! Account Number: " << newAccount.getAccountNumber() << endl;
                break;
            }
            case 2: {
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to deposit: $";
                cin >> amount;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.deposit(amount);
                        break;
                    }
                }
                break;
            }
            case 3: {
                cout << "Enter account number: ";
                cin >> accNum;
                cout << "Enter amount to withdraw: $";
                cin >> amount;
                for (auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.withdraw(amount);
                        break;
                    }
                }
                break;
            }
            case 4: {
                cout << "Enter account number: ";
                cin >> accNum;
                for (const auto &acc : accounts) {
                    if (acc.getAccountNumber() == accNum) {
                        acc.display();
                        break;
                    }
                }
                break;
            }
            case 5: exit(0);
            default: cout << "Invalid choice!" << endl;
        }
    }
    
    return 0;
}