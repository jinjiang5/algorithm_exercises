#include <iostream>
using namespace std;
#define N 100

int main()
{
    int arc[N][N];
    int temp;
    cout << "input n:";
    int n; cin >>n;
    for (int i = 0; i < (n * n + n) / 2; i++)
    {
        for (int j = 0; j < i; j++){
            if(i == j){
                arc[i][j] = 0;
            }
            else {
                temp = rand() % 20 + 5;
                arc[i][j] = temp;
                arc[j][i] = temp;

            }
        }
    }
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            cout << arc[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}