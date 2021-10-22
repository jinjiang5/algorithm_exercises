#include <iostream>

using namespace std;

int getMaxCnt(int a[], int l, int r)
{
    int mid = (l + r) / 2;
    int MaxCnt = 0;
    int i, j;
    for (i = 0; i < mid; i++)
    {
        if (a[i] == a[mid])
        {
            break;
        }
    }
    for (j = mid; j < r; j++)
    {
        if (a[j] != a[mid])
        {
            break;
        }
    }
    if (j - i > MaxCnt)
    {
        MaxCnt = j - i;
    }
    int temp;
    if (i - 1 - l > MaxCnt)
    {
        temp = getMaxCnt(a, l, i - 1);
        if (temp > MaxCnt)
        {
            MaxCnt = temp;
        }
    }
    if (r - j > MaxCnt)
    {
        temp = getMaxCnt(a, j, r);
        if (temp > MaxCnt)
        {
            MaxCnt = temp;
        }
    }

    return MaxCnt;
}
int main()
{
    int a[] = {1, 2, 3, 4, 4, 4, 6, 6, 6, 6, 6};
    cout << getMaxCnt(a, 0, 11) << endl;
    return 0;
}