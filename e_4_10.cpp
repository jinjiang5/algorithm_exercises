#include <iostream>
using namespace std;
int mode;

int findMode(int a[], int l, int r)
{
    int t = 0, t1 = 0, t2 = 0, i, j;
    int mid = (l + r) / 2;
    if (r != l)
    {
        t = findMode(a, l, mid);
        t2 = findMode(a, mid + 1, r);
        if (t2 > t)
        {
            t = t2;
        }
    }

    for (i = l; i < mid; i++)
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
    int t3 = j - i;
    if (t3 > t)
    {
        t = t3;
        mode = a[mid];
    }
    return t;
}

int main()
{
    int a[] = {1,2,3,3,3,4,4,5,5};
    int len = sizeof(a) / sizeof(a[0]);
    int count = 0;
    count = findMode(a, 0, len-1);
    cout << "数组a的众数为" << mode << ",出现次数为" << count << endl;
    return 0;
}