#include <iostream>

using namespace std;

double KnapSack(int w[], int v[], int n, int C)
{
    double x[10] = {0};
    double maxValue = 0;
    int i;
    for (i = 0; w[i] < C; i++)
    {
        x[i] = 1;
        maxValue += v[i];
        C -= w[i];
    }
    x[i] = (double)C / w[i];
    maxValue += x[i] * v[i];
    return maxValue;
}

int main()
{
    int w[] = {1, 2, 4, 5, 1, 3, 7};
    int v[] = {6, 10, 18, 15, 3, 5, 7};
    cout << KnapSack(w,v,7,15);
    return 0;
}