#ifndef _BANKACCOUNT_H_
#define _BANKACCOUNT_H_

#include "global.h"

class bankAccount
{
private:
    int account_no;
    string password;
    double balance;
    vector<transaction *> trans_array;
    static int num;

public:
    // Constructor & Deconstructor
    bankAccount(string pwd);
    ~bankAccount();

    // Getters
    int getAccNo();
    string getPwd();
    double getBalance();

    // Setters
    void setPed(string newPwd);
    void addTrans(transaction *t);

    // Show all transactions
    friend ostream &operator<<(ostream &out, bankAccount &ba);
};

#endif