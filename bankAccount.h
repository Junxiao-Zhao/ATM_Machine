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
    bankAccount(string pwd, double b);
    ~bankAccount();

    // Getters
    int getAccNo();
    string getPwd();
    double getBalance();

    // Setters
    void setPwd(string newPwd);
    void addBalance(double add);
    void setBalance(double newB);
    void addTrans(transaction *t);

    // show all transactions
    friend ostream &operator<<(ostream &out, bankAccount &ba);
};

#endif