#include <iostream>

using namespace std;

int sum(int X[], int Y[], int k)
{
    int sum = 0;
    for (int i = 0; i <= k; i++)
    {
        sum += X[Y[i]];
    }
    return sum;
}


int func(int X[], int n, int y)
{
    int count = 0;
    int Y[n];
    for (int i = 0; i < n; i++)
    {
        Y[i] = 0;
    }
    int k = 0;
    while (k >= 0)
    {
        while (Y[k] < n - 1)
        {
            if (sum(X, Y, k) <= y)
            {
                break;
            }
            else
            {
                Y[k] += 1;
            }
        }

        if (sum(X, Y, k) == y)
        {
            count += 1;
            cout << "解" << count << ": { ";
            for (int i = 0; i <= k; i++)
            {
                cout << X[Y[i]] << " ";
            }
            cout << "}" << endl;
        }
        if (Y[k] < n - 1 && k < n - 1)
        {
            k += 1;
            Y[k] = Y[k - 1] + 1;
        }
        else
        {
            Y[k] = 0;
            k -= 1;
            Y[k] += 1;
        }
    }
    if (count == 0)
    {
        cout << "无解";
    }
}

int main()
{
    int a[100], n, y;
    cout << "输入数的个数:";
    cin >> n;
    cout << "输入" << n << "个正整数:";
    for (int i = 0; i < n; i++){
        cin >> a[i];
    }
    cout << "输入y:";
    cin >> y;
    func(a, n, y);
    return 0;
}