#include <iostream>

using namespace std;

int Partition(int r[], int first, int end)
{
    int i = first, j = end;
    while (i < j)
    {
        while (i < j && r[i] <= r[j])
            j--;
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i++;
        }
        while (i < j && r[i] <= r[j])
            i++;
        if (i < j)
        {
            int temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            j--;
        }
    }
    return i;
}

void QuickSort(int r[], int first, int end)
{
    int pivot;
    if (first < end)
    {
        pivot = Partition(r, first, end);
        QuickSort(r, first, pivot - 1);
        QuickSort(r, pivot + 1, end);
    }
}

int Closest(int S[], int left, int right)
{
    int d1, d2, d3, d;
    if (right - left == 1)
    {
        return S[right] - S[left];
    }
    if (right - left == 2)
    {
        d1 = S[right] - S[right - 1];
        d2 = S[left + 1] - S[left];
        return d1 < d2 ? d1 : d2;
    }
    int mid = (left + right) / 2;
    d1 = Closest(S, left, mid);
    d2 = Closest(S, mid + 1, right);
    d = d1 < d2 ? d1 : d2;
    d3 = S[mid + 1] - S[mid];
    if (d3 < d)
    {
        d = d3;
    }
    return d;
}

int main()
{
    int S[] = {1, 2, 7, 34, 1, 46, 1, 4, 7, 123};
    QuickSort(S, 0, 9);
    cout << Closest(S, 0, 9) << endl;
    return 0;
}