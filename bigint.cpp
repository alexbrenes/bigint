#include "bigint.h"
#include <iostream>
BigInt::BigInt()
{
    digits = new vector<short>;
}

BigInt::BigInt(const BigInt &bigInt)
{
    *this->digits = *(bigInt.digits);
}

BigInt::BigInt(const string str)
{
    digits = new vector<short>;
    int n = str.size();
    bool positive = 1;
    int MSD = n - 1; // Most Significant Digit
    for (int i = 0; i < n; ++i)
    {
        if (str[i] <= '9' && str[i] >= '1')
        {
            MSD = i;
            break;
        }
        if (str[i] == '-')
            positive = 0;
    }

    for (int i = n - 1; i > MSD - 1; --i)
        digits->push_back(str[i] - '0');
    if (!positive)
        digits->push_back(0);
}

BigInt &BigInt::addition(const BigInt &a1, const BigInt &a2)
{
    vector<short> *ad;
    vector<short> *bd;

    if (a1.digits->size() > a2.digits->size())
    {
        ad = a1.digits;
        bd = a2.digits;
    }
    else
    {
        ad = a1.digits;
        bd = a2.digits;
    }

    BigInt *c = new BigInt;
    int nb = bd->size();
    int na = ad->size();
    int sum = 0, i = 0;
    for (; i < nb; ++i)
    {
        sum += (*ad)[i] + (*bd)[i];
        c->digits->push_back(sum % 10);
        sum /= 10;
    }

    for (; i < na; ++i)
    {
        sum += (*ad)[i];
        c->digits->push_back(sum % 10);
        sum /= 10;
    }

    while (sum)
    {
        c->digits->push_back(sum % 10);
        sum /= 10;
    }

    return *c;
}

BigInt &BigInt::substract(const BigInt &a1, const BigInt &a2)
{
    // vector<short> *ad;
    // vector<short> *bd;

    // if (a1.digits->size() > a2.digits->size())
    // {
    //     ad = a1.digits;
    //     bd = a2.digits;
    // }
    // else
    // {
    //     ad = a1.digits;
    //     bd = a2.digits;
    // }
    int na = a1.digits->size();
    int nb = a2.digits->size();
    BigInt *c = new BigInt;
    if (!(*a1.digits)[na - 1] && !(*a1.digits)[na - 1]) // Negative or 0
        return addition(a1, a2);

    // int nb = bd->size();
    // int na = ad->size();
    // int sub = 0, i = 0, carry = 0;

    // for (; i < nb; ++i)
    // {
    //     sub = (*a1.digits)[i] - (*a2.digits)[i] - 0;
    //     if (sub < 0)
    //     {
    //         carry = 1;
    //     }
    //     else
    //         carry = 0;
    //     c->digits->push_back(abs(sub));
    // }

    // for (; i < na; ++i)
    // {
    //     sub = (*ad)[i];
    //     if (sub < 0)
    //     {
    //         carry = 1;
    //     }
    //     else
    //         carry = 0;
    //     c->digits->push_back(abs(sub));
    // }
    // If negative add a zero to sign
    // while (sub)
    // {
    //     sub = (*ad)[i] - carry;
    //     if (sub < 0)
    //     {
    //         sub += 10;
    //         carry = 1;
    //     }
    //     else
    //         carry = 0;
    //     if (sub)
    //         c->digits->push_back(sub);
    // }

    return *c;
}

BigInt &BigInt::operator+(const BigInt &b)
{
    return addition(*this, b);
}

BigInt &BigInt::operator-(const BigInt &b)
{
    return substract(*this, b);
}

int BigInt::compare(const BigInt &a, const BigInt &b)
{
    // a < b -> -1
    // a = b ->  0
    // a > b ->  1
    int na = a.digits->size();
    int nb = b.digits->size();

    int negative = 0;
    // Check sign
    if (!(*a.digits)[na - 1] && (*b.digits)[nb - 1])
        return -1;
    else if ((*a.digits)[na - 1] && !(*b.digits)[nb - 1])
        return 1;
    else if (!(*a.digits)[na - 1] && !(*b.digits)[nb - 1])
        negative = 1;

    if (na < nb)
        return -1;
    else if (na > nb)
        return 1;
    else
    {
        for (int i = 0; i < na; ++i)
            if ((*a.digits)[i] < (*b.digits)[i])
                return negative ? 1 : -1;
            else if ((*a.digits)[i] > (*b.digits)[i])
                return negative ? -1 : 1;
        return 0;
    }
}