#include <iostream>
using namespace std;
#define N 100000

void sort1(int a[N], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

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

int main()
{
    int a[N];
    for (int i = 0; i < 50000; i++)
    {
        a[i] = rand();
    }
    //sort1(a, 50000);
    QuickSort(a,0,50000);
    for (int i = 0; i < 50000; i++)
    {
    cout << a[i] << " ";
    }
    return 0;
}