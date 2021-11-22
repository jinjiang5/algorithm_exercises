#include <iostream>

using namespace std;

int lcm(int, int);
int gcd(int, int);

int main()
{
    cout << lcm(36, 48) << endl;
    return 0;
}

int lcm(int m, int n)
{
    return m * n / gcd(m, n);
}

int gcd(int m, int n)
{
    int r = m % n;
    if (r == 0)
    {
        return n;
    }
    else
    {
        return gcd(n, r);
    }
}