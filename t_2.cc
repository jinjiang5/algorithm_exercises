#include <iostream>

#define N 100
using namespace std;
bool visited[N];
int arc[N][N];
int path[N];
int min_path[N];
int depth = 0;
int minlength = 65536;

void DFS(int v, int n)
{
    if (depth == n)
    {
        int temp = 0;
        for (int i = 0; i < n - 1; i++)
        {
            temp += arc[path[i]][path[i + 1]];
        }
        temp += arc[path[0]][path[n - 1]];
        if (temp < minlength)
        {
            minlength = temp;
            for (int i = 0; i < n; i++)
            {
                min_path[i] = path[i];
            }
        }
    }
    for (int i = 0; i < n; i++)
    {
        if (arc[v][i] != 0)
        {
            if (!visited[i])
            {
                visited[i] = true;
                path[depth++] = i;
                DFS(i, n);
                depth--;
                visited[i] = false;
            }
        }
    }
}

int main()
{
    int n;
    cout << "输入顶点个数:";
    cin >> n;
    cout << "输入图的邻接矩阵:" << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arc[i][j];
        }
    }
    for (int i = 0; i < n; i++)
    {
        visited[i] = false;
    }
    visited[0] = true;
    path[depth++] = 0;
    DFS(0, n);
    cout << "最短路径为:";
    for (int i = 0; i < n;i++){
        cout << min_path[i] << " ";
    }
    cout << "   长度:" << minlength << endl;
    return 0;
}