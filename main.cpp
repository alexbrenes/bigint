#include "bigint.h"
#include <iostream>
int main()
{
    cout << "BigInt by alexbrenes\n";
    BigInt a("516498464687965164987946135498794635146354687484");
    BigInt b("656846168413213496879494867948934756836875743876578236");
    // cout << a + b;
    BigInt a1("99");
    BigInt a2("11");
    cout << BigInt::compare(a1, a2);
    return 0;
}