#include <iostream>

using namespace std;
void InsertHeap(int r[], int k);
int main()
{
    int r[7] = {35, 32, 20, 28, 18, 12, 37};
    InsertHeap(r,6);
    return 0;
}

void InsertHeap(int r[], int k)
{
    int temp, i = k;
    while (r[i] >= r[(i - 1) / 2] && i > 0)
    {
        temp = r[i];
        r[i] = r[(i - 1) / 2];
        r[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}