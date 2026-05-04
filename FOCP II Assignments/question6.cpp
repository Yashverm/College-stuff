#include <iostream>
#include <vector>
#include <string>

using namespace std;

class AccountInfo
{
public:
    string userId;
    long long balance;

    AccountInfo(string id, long long initialAmount)
    {
        userId = id;
        balance = initialAmount;
    }
};

class Bank
{
private:
    vector<AccountInfo> userList;

    int findAccountIndex(string id)
    {
        for (int i = 0; i < userList.size(); i++)
        {
            if (userList[i].userId == id)
            {
                return i;
            }
        }
        return -1;
    }

public:
    void createAccount(string id, long long amount)
    {
        int index = findAccountIndex(id);
        if (index == -1)
        {
            AccountInfo newAccount(id, amount);
            userList.push_back(newAccount);
            cout << "true" << endl;
        }
        else
        {
            userList[index].balance += amount;
            cout << "false" << endl;
        }
    }

    void debitMoney(string id, long long amount)
    {
        int index = findAccountIndex(id);
        if (index != -1 && userList[index].balance >= amount)
        {
            userList[index].balance -= amount;
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    void creditMoney(string id, long long amount)
    {
        int index = findAccountIndex(id);
        if (index != -1)
        {
            userList[index].balance += amount;
            cout << "true" << endl;
        }
        else
        {
            cout << "false" << endl;
        }
    }

    void checkBalance(string id)
    {
        int index = findAccountIndex(id);
        if (index != -1)
        {
            cout << userList[index].balance << endl;
        }
        else
        {
            cout << -1 << endl;
        }
    }
};

int main()
{
    int queryCount;
    if (!(cin >> queryCount))
        return 0;

    Bank myBank;

    for (int i = 0; i < queryCount; i++)
    {
        string operation;
        cin >> operation;

        if (operation == "CREATE")
        {
            string x;
            long long y;
            cin >> x >> y;
            myBank.createAccount(x, y);
        }
        else if (operation == "DEBIT")
        {
            string x;
            long long y;
            cin >> x >> y;
            myBank.debitMoney(x, y);
        }
        else if (operation == "CREDIT")
        {
            string x;
            long long y;
            cin >> x >> y;
            myBank.creditMoney(x, y);
        }
        else if (operation == "BALANCE")
        {
            string x;
            cin >> x;
            myBank.checkBalance(x);
        }
    }

    return 0;
}