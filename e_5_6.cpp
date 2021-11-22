#include <iostream>

using namespace std;
void Delete(int r[], int n, int i);
void SiftHeap(int r[], int k, int n);

int main()
{
    int r[] = {35, 32, 20, 28, 18, 12};
    Delete(r,6,3);
    return 0;
}

void SiftHeap(int r[], int k, int n)
{
    int i, j, temp;
    i = k; j = 2 * i + 1;
    while(j < n) {
        if(j < n -1 && r[j] < r[j + 1]) {
            j++;
        }
        if(r[i] > r[j]){
            break;
        }
        else {
            temp = r[i]; r[i] = r[j]; r[j] = temp;
            i = j; j = 2 * i + 1;
        }
    }
}

void Delete(int r[], int n, int i)
{
    int temp;
    for (int j = i; j > 0;)
    {
        temp = r[j];
        r[j] = r[(j - 1) / 2];
        r[(j - 1) / 2] = temp;
        j = (j - 1) / 2;
    }
    r[0] = r[n-1];
    r[n-1] = -1;//将删除的元素设为-1
    SiftHeap(r, 0, n - 1);
}