#include <iostream>

using namespace std;

int BatchJob(int a[], int b[], int n)
{
    int i, k;
    int x[10], sum1[10], sum2[10];
    int bestTime = 1000;
    for (i = 1; i <= n; i++)
    {
        x[i] = -1; 
        sum1[i] = 0;
        sum2[i] = 0;
    }
    x[0] = -1;
    sum1[0] = 0;
    sum2[0] = 0;
    k = 1;
    while (k >= 1)
    {
        x[k] = x[k] + 1;
        while (x[k] < n)
        {
            for (i = 0; i < k; i++)
            {
                if (x[i] == x[k])
                    break;
            }
            if (i == k)
            {
                sum1[k] = sum1[k - 1] + a[x[k]];
                if (sum1[k] > sum2[k - 1])
                {
                    sum2[k] = sum1[k] + b[x[k]];
                }
                else
                {
                    sum2[k] = sum2[k - 1] + b[x[k]];
                }
                if (sum2[k] < bestTime)
                    break;
                else
                    x[k] = x[k] + 1;
            }
            else
                x[k] = x[k] + 1;
        }
        if (x[k] < n -1 && k < n - 1)
        {
            k += 1;
        }
        else
        {
            if (k == n - 1)
            {
                if (bestTime > sum2[k])
                {
                    bestTime = sum2[k];
                    cout << "curr:";
                    for (int j = 1; j <= n; j++)
                    {
                        cout << x[j] + 1 << " ";
                    }

                    cout << "best:" << bestTime << endl;
                }
                x[k] = -1;
                k -= 1;
            }
            
        }
    }
    return bestTime;
}

int main()
{
    int a[] = {2,3,2};
    int b[] = {1,1,3};
    BatchJob(a,b,3);
    return 0;
}