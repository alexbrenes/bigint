#ifndef BIGINT_H
#define BIGINT_H
#define MAX 2e31 - 1
#include <vector>
#include <string>
#include <ostream>
using namespace std;

class BigInt
{
private:
    vector<short> *digits;
    BigInt &addition(const BigInt &, const BigInt &);
    BigInt &substract(const BigInt &, const BigInt &);
    BigInt operator[](int);
    static int compare(const BigInt &, const BigInt &);

public:
    BigInt();
    BigInt(const string);
    BigInt(const BigInt &);
    BigInt operator=(const BigInt &);
    friend ostream &operator<<(ostream &output, const BigInt &bigInt)
    {
        int n = bigInt.digits->size();
        int i = n - 1;
        if (n > 1 && !(*bigInt.digits)[i])
        {
            output << "-";
            --i;
        }
        for (; i >= 0; --i)
            output << (*bigInt.digits)[i];
        return output;
    }
    BigInt &operator+(const BigInt &);
    BigInt &operator-(const BigInt &);
};

BigInt operator*(const BigInt &, const BigInt &);
BigInt operator/(const BigInt &, const BigInt &);

// ostream &operator<<(ostream &output, const BigInt &bigInt)
// {
//     int n = bigInt.digits->size();
//     if (n > 1 && !(*bigInt.digits)[n - 1])
//         output << "-";
//     for (int i = n - 2; i >= 0; --i)
//         output << (*bigInt.digits)[i];
//     return output;
// }

#endif