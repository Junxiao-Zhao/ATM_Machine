#include "global.h"

int main()
{
    // generate 10 bank accounts with random passwords
    vector<bankAccount> accounts;
    for (int i = 0; i < 10; i++)
    {
        bankAccount cur_ba(to_string(rand() % 3), 5000);
        accounts.push_back(cur_ba);
    }

    // Login Window
    int accountNo;
    string password;
    while (true)
    {
        cout << "Login Window:" << endl
             << "=============" << endl
             << "Enter Your Account no: ";
        cin >> accountNo;
        cout << "Enter your password: ";
        cin >> password;
        cout << endl;

        // match password
        if (accounts.size() >= accountNo && accountNo > 0 && accounts[accountNo - 1].getPwd().compare(password) == 0)
        {
            break;
        }
    }

    // Main Window
    int input = 0;
    while (input != 5)
    {
        cout << "Main Window" << endl
             << "============" << endl
             << "Choose one of the following options:" << endl
             << "(1) Show balance" << endl
             << "(2) Deposit" << endl
             << "(3) Withdraw" << endl
             << "(4) Show All Transactions" << endl
             << "Enter your choice: ";
        cin >> input;
        cout << endl;

        switch (input)
        {
        case 1:
            showBalance(accounts[accountNo - 1]);
            break;
        case 2:

            break;
        case 3:

            break;
        case 4:

            break;
        }
        cout << endl;
    }
}
