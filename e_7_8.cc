#include <iostream>

using namespace std;
#define N 100
int Especial_zero_one_knapsack(int w[],int v[], int n, int C);

int main(){
    int w[N];
    int v[N], n, C;
    cout << "输入物品个数:";cin >> n;
    cout << "输入背包容量:";cin >> C;
    cout << "依次输入物品重量:";
    for(int i=0; i<n; i++){
        cin >> w[i];
    }
    cout << "依次输入物品价值:";
    for(int i=0; i<n; i++){
        cin >> v[i];
    }
    Especial_zero_one_knapsack(w, v, n, C);
    return 0;
}

int Especial_zero_one_knapsack(int w[],int v[], int n, int C){
    int result = 0;
    cout << "将物品"; 
    for(int i=0;w[i] <= C && i < n;i++)
    {
        result += v[i];
        cout << i << ",";
        C -= w[i];
    }
    cout << "放入背包获得最优解" << result << endl;
    return result;
}