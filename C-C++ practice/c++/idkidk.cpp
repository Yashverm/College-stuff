#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string accountHolderName;
    double balance;
    int rewardPoints;

public:

    BankAccount(string name, double initialBalance, int initialRewardPoints) {
        accountHolderName = name;
        balance = initialBalance;
        rewardPoints = initialRewardPoints;
        cout << "Account successfully created!" << endl;
        cout << "------------------------------------" << endl;
    }


    void withdraw() {
        if (balance >= 500 && rewardPoints >= 20) {
            balance -= 500;
            rewardPoints -= 20;
            cout << "Withdrawal Successful!" << endl;
            cout << "  - Deducted: $500 from balance" << endl;
            cout << "  - Deducted: 20 reward points" << endl;
            cout << "------------------------------------" << endl;
        } else if (balance < 500) {
            cout << "Withdrawal Failed! Insufficient balance." << endl;
            cout << "------------------------------------" << endl;
        } else {
            cout << "Withdrawal Failed! Insufficient reward points." << endl;
            cout << "------------------------------------" << endl;
        }
    }


    void displayAccount() {
        cout << "======= Account Details ========" << endl;
        cout << "  Account Holder : " << accountHolderName << endl;
        cout << "  Balance        : $" << balance << endl;
        cout << "  Reward Points  : " << rewardPoints << endl;
        cout << "================================" << endl;
    }
};

int main() {

    BankAccount account("John Doe", 2000.0, 100);


    cout << "--- Initial Account Details ---" << endl;
    account.displayAccount();


    cout << "--- Performing Withdrawal ---" << endl;
    account.withdraw();


    cout << "--- Updated Account Details ---" << endl;
    account.displayAccount();

    return 0;
}