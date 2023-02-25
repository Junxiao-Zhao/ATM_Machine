#ifndef _TRANSACTION_H_
#define _TRANSACTION_H_

#include "global.h"

class transaction
{
private:
    string date;
    string type;
    double amount;

public:
    // Constructor
    transaction(string d, string t, double a);

    // Getters
    string getDate();
    string getType();
    double getAmount();

    // Setters
    void setDate(string newD);
    void setType(string newT);
    void setAmount(double newA);

    // show this transaction
    friend ostream &operator<<(ostream &out, transaction &ts);
};

#endif