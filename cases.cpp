#include "global.h"

string temp;

// get current time
string getTime()
{
     time_t now = time(0);
     string cur_time = ctime(&now);
     cur_time.pop_back(); // remove '\n'
     return cur_time;
}

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

     double amount;
     cin >> amount;
     cin.get();

     // add to balance & transaction if valid
     if (amount > 0)
     {
          account.addBalance(amount);
          account.addTrans(new transaction(getTime(), "deposit", amount));

          cout << broken_line << endl
               << "Well done. This was added to your balance successfully..." << back_main;
     }
     else
     {
          cout << broken_line << endl
               << "Transaction failed..." << back_main;
     }
     getline(cin, temp);
}

// Case 3: withdraw
void withdraw(bankAccount &account)
{
     cout << "Main Window --> Withdraw (Enter the following information)" << endl
          << broken_line_2 << endl
          << "The amount you want to withdraw: ";

     double amount;
     cin >> amount;
     cin.get();

     // withdraw & add transaction if valid
     if (amount > 0 && amount <= account.getBalance())
     {
          account.wdBalance(amount);
          account.addTrans(new transaction(getTime(), "withdraw", amount));

          cout << broken_line << endl
               << "Please take your money then..." << back_main;
     }
     else
     {
          cout << broken_line << endl
               << "Transaction failed..." << back_main;
     }
     getline(cin, temp);
}

// Case 4: show all transactions
void showAllTrans(bankAccount &account)
{
     cout << "Main Window --> Show All Transactions" << endl
          << broken_line_2 << endl
          << endl
          << account << endl
          << back_main;
     getline(cin, temp);
}