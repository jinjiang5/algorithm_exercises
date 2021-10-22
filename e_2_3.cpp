#include <iostream>
using namespace std;

int func1()
{
    int n = 10;
    int y = 0;
    int count = 0;
    for (int i = 1; i <= n; i++)
    {
        if (2 * i <= n)
        {
            for (int j = 2 * i; j <= n; j++)
            {
                y = y + i * j;
                count++;
            }
        }
    }
    cout << count << endl;
    return 0;
}

int func2(){
    int m = 0;
    int n = 10;
    for (int i = 0; i <=n; i++)
    {
        for (int j = 1; j <= 2*i;j++)
        {
            m = m + 1;
        }
    }
    cout << m << endl;
}

int main()
{
    func2();
}