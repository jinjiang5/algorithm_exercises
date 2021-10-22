#include <iostream>

using namespace std;

void findMode(int a[], int &mode, int &count, int l, int r)
{
    int mid = (l + r) / 2;
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
    if (j - i > count)
    {
        count = j - i;
        mode = a[mid];
    }
    if (i - 1 - l > count)
    {
        findMode(a, mode, count, l, i - 1);
    }
    if (r - j > count)
    {
        findMode(a, mode, count, j, r);
    }
}
int main()
{
    int a[] = {1, 2, 3, 3, 3, 4, 4, 5, 5};
    int len = sizeof(a) / sizeof(a[0]);
    int mode = 0, count = 0;
    findMode(a, mode, count, 0, len);
    cout << "数组a的众数为" << mode << ",出现次数为" << count << endl;
    return 0;
}