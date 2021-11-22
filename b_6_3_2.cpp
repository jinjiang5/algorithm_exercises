#include <iostream>

using namespace std;
int L[8][8];
int S[8][8];
int CommonOrder(char x[], int m, char y[], int n, char z[]);
int main()
{
    char s1[] = "xzyzzyx";
    char s2[] = "zxyyzxz";
    char s3[10];
    CommonOrder(s1, 7, s2, 7, s3);
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << L[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "----------------" << endl;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            cout << S[i][j] << "\t";
        }
        cout << endl;
    }
    return 0;
}
int CommonOrder(char x[], int m, char y[], int n, char z[])
{
    int i, j, k;
    for (j = 0; j <= n; j++)
    {
        L[0][j] = 0;
    }
    for (i = 0; i <= m; i++)
    {
        L[i][0] = 0;
    }
    for (i = 1; i <= m; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (x[i-1] == y[j-1])
            {
                L[i][j] = L[i - 1][j - 1] + 1;
                S[i][j] = 1;
            }
            else if (L[i][j - 1] >= L[i - 1][j])
            {
                L[i][j] = L[i][j - 1];
                S[i][j] = 2;
            }
            else
            {
                L[i][j] = L[i - 1][j];
                S[i][j] = 3;
            }
        }
    }
    i = m;
    j = n;
    k = L[m][n];
    while (i > 0 && j > 0)
    {
        if (S[i][j] == 1)
        {
            z[k-1] = x[i-1];
            k--;
            i--;
            j--;
        }
        else if (S[i][j] == 2)
            j--;
        else
            i--;
    }
    //cout << L[m][n] << endl;
    for (k = 0; k < L[m][n]; k++)
    {
        cout << z[k];
    }
    cout << endl;
    return L[m][n];
}