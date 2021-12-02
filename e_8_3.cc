#include <iostream>

using namespace std;

int sum(int a[], int b[], int x[], int k)
{
    int atime = 0;
    int btime = 0;
    for (int i = 0; i <= k; i++)
    {
        atime += a[x[i]];
        if (atime >= btime)
        {
            btime = atime + b[x[i]];
        }
        else
        {
            btime += b[x[i]];
        }
    }
    return btime;
}

int func(int a[], int b[], int n)
{
    int x[n];
    for (int i = 0; i < n; i++)
    {
        x[i] = -1;
    }
    int min = 1000;
    int k = 0;
    while (k >= 0)
    {
        x[k] += 1;
        while (x[k] < n)
        {
            int i;
            for (i = 0; i < k; i++)
            {
                if (x[k] == x[i])
                {
                    break;
                }
            }
            if (k == i)
            {
                break;
            }
            x[k] += 1;
        }

        if (x[k] < n && k < n - 1)
        {
            if (sum(a, b, x, k) >= min)
            {
                continue;
            }
            k += 1;
        }
        else if (x[k] <= n - 1 && k == n - 1)
        {
            if (min > sum(a, b, x, k))
            {
                min = sum(a, b, x, k);
            }
            for (int i = 0; i < n; i++)
            {
                cout << x[i] + 1;
            }
            cout << "   " << sum(a, b, x, k) << endl;
        }
        else if (x[k] >= n)
        {
            x[k] = -1;
            k -= 1;
        }
    }
}

int main()
{
    int a[] = {2, 3, 2};
    int b[] = {1, 1, 3};
    func(a, b, 3);
    return 0;
}