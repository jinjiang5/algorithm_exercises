#include <iostream>

using namespace std;
int V[6][11];
int x[6];

int KnapSack(int w[], int v[], int n, int C);
int main()
{
    int w[] = {0, 2, 2, 6, 5, 4};
    int v[] = {0, 6, 3, 5, 4, 6};
    KnapSack(w, v, 5, 10);
    for (int i = 0; i < 6; i++)
    {
        for(int j = 0; j < 11 ; j++){
            cout << V[i][j] << " ";
        }
        cout << endl;
    }
    for(int i = 0; i < 6; i++){
        cout << x[i] << " ";
    }
    return 0;
}
int KnapSack(int w[], int v[], int n, int C)
{
    int i, j;
    for (i = 0; i <= n; i++)
    {
        V[i][0] = 0;
    }
    for (j = 0; j <= C; j++)
    {
        V[0][j] = 0;
    }
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= C; j++)
        {
            if (j < w[i])
                V[i][j] = V[i - 1][j];
            else
                V[i][j] = max(V[i - 1][j], V[i - 1][j - w[i]] + v[i]);
        }
    }
    for (j = C, i = n; i > 0; i--)
    {
        if (V[i][j] > V[i - 1][j])
        {
            x[i] = 1;
            j = j - w[i];
        }
        else
            x[i] = 0;
    }
    return V[n][C];
}