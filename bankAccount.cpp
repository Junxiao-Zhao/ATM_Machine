#include "global.h"

// Class counter
int bankAccount::num = 0;

// Constructor
bankAccount::bankAccount(string pwd)
{
    this->account_no = bankAccount::num;
    this->password = pwd;
    this->balance = 5000;
    bankAccount::num++;
}

// Deconstructor
bankAccount::~bankAccount()
{
    for (int i = 0; i < this->trans_array.size(); i++)
    {
        delete this->trans_array[i];
    }
    this->trans_array.clear();
    vector<transaction *>().swap(this->trans_array);
}

// Getters
int bankAccount::getAccNo()
{
    return this->account_no;
}

string bankAccount::getPwd()
{
    return this->password;
}

double bankAccount::getBalance()
{
    return this->balance;
}

// Setters
void bankAccount::setPed(string newPwd)
{
    this->password = newPwd;
}

void bankAccount::addTrans(transaction *t)
{
    this->trans_array.push_back(t);
}

// Show all transactions
ostream &operator<<(ostream &out, bankAccount &ba)
{
    // header
    out << "Account no: " << ba.account_no << endl
        << string(60, '-') << endl
        << setw(30) << left << "Date"
        << "| " << setw(20) << left << "Type"
        << "| " << setw(6) << left << "Amount" << endl
        << string(60, '-') << endl;

    // body
    for (int i = 0; i < ba.trans_array.size(); i++)
    {
        transaction &cur_tran = *ba.trans_array[i];
        out << cur_tran << endl;
    }

    // tail
    return out << string(60, '-');
}