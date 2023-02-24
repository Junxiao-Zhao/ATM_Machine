#include "global.h"

// Constructor
transaction::transaction(string d, string t, double a)
{
    this->date = d;
    this->type = t;
    this->amount = a;
}

// Getters
string transaction::getDate()
{
    return this->date;
}
string transaction::getType()
{
    return this->type;
}
double transaction::getAmount()
{
    return this->amount;
}

// Setters
void transaction::setDate(string newD)
{
    this->date = newD;
}
void transaction::setType(string newT)
{
    this->type = newT;
}
void transaction::setAmount(double newA)
{
    this->amount = newA;
}

// Show this transaction
ostream &operator<<(ostream &out, transaction &ts)
{
    return out << setw(30) << left << ts.date << "| "
               << setw(20) << left << ts.type << "| "
               << setw(6) << left << ts.amount;
}