#include "global.h"

string temp;

// Case 1: show balance
void showBalance(bankAccount &account)
{
     cout << "Main Window --> Show Balance" << endl
          << broken_line_2 << endl
          << "Your current balance is: $" << setiosflags(ios::fixed) << setprecision(2) << account.getBalance() << endl
          << broken_line << endl
          << back_main;
     getline(cin, temp);
}

// Case 2: deposit
void deposit(bankAccount &account)
{
     cout << "Main Window --> Deposit (Enter the following information)" << endl
          << broken_line_2 << endl
          << "The amount you want to deposit: ";

     // add to balance
     double amount;
     cin >> amount;
     cin.get();
     account.addBalance(amount);

     // add to transaction
     time_t now = time(0);
     char *cur_time = ctime(&now);
     account.addTrans(new transaction(cur_time, "deposit", amount));

     cout << broken_line << endl
          << "Well done. This was added to your balance successfully..."
          << back_main;
     getline(cin, temp);
}