#include <iostream>
using namespace std;

int find_max(int a[], int l, int r)
{
    if (l == r)
        return a[l];
    else
    {
        int m = (l + r) / 2;
        int t1 = find_max(a, l, m);
        int t2 = find_max(a, m + 1, r);
        return t1 < t2 ? t2 : t1;
    }
}

int main()
{
    int a[] = {1, 456, 12, 567, 1234, 83, 146, 842354};
    cout << find_max(a, 0, 7) << endl;
}