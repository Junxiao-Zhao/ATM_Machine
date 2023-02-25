#include "global.h"

// Class counter
int bankAccount::num = 1;

// Constructor
bankAccount::bankAccount(string pwd, double b)
{
    this->account_no = bankAccount::num;
    this->password = pwd;
    this->balance = b;
    bankAccount::num++;
}

// Deconstructor
bankAccount::~bankAccount()
{
    // free each transaction
    for (int i = 0; i < this->trans_array.size(); i++)
    {
        delete this->trans_array[i];
        this->trans_array[i] = nullptr;
    }

    // free the vector
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
void bankAccount::setPwd(string newPwd)
{
    this->password = newPwd;
}

void bankAccount::addBalance(double add)
{
    this->balance += add;
}

void bankAccount::setBalance(double newB)
{
    this->balance += newB;
}

void bankAccount::addTrans(transaction *t)
{
    this->trans_array.push_back(t);
}

// show all transactions
ostream &operator<<(ostream &out, bankAccount &ba)
{
    // header
    out << "Account no: " << ba.account_no << endl
        << broken_line << endl
        << setw(30) << left << "Date"
        << "| " << setw(20) << left << "Type"
        << "| " << setw(10) << left << "Amount" << endl
        << broken_line << endl;

    // body
    for (int i = 0; i < ba.trans_array.size(); i++)
    {
        transaction &cur_tran = *ba.trans_array[i];
        out << cur_tran << endl;
    }

    // tail
    return out << broken_line;
}