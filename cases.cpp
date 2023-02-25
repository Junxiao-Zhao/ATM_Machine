#include "global.h"

// Case 1: show balance
void showBalance(bankAccount &account)
{
    cout << "Main Window --> Show Balance" << endl
         << string(64, '=') << endl
         << "Your current balance is: $" << account.getBalance() << endl
         << broken_line << endl
         << "Press enter to go back to the Main Window";
    cin.get();
    cout << endl;
}