#include <iostream>

using namespace std;

#define N 100 //设最多有100个顶点
#define MAX 32767

/*
0 1 12 0 0 0
0 0 9 3 0 0
0 0 0 0 5 0
0 0 4 0 13 15
0 0 0 0 0 6
0 0 0 0 0 0
*/

typedef struct point
{
    int value;
    bool know;
    int path;
} point;

int Dijkstra(int arc[N][N], int n, int s, int e);

int main()
{
    int arc[N][N];
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
    int start_point;
    int end_point;
    cout << "输入两个顶点(顶点序号从0开始):" << endl;
    cin >> start_point;
    cin >> end_point;
    int min_path = Dijkstra(arc, n, start_point, end_point);

    return 0;
}

int Dijkstra(int arc[N][N], int n, int s, int e)
{
    point points[n];
    for (int i = 0; i < n; i++)
    {
        points[i].value = MAX;
        points[i].know = false;
    }
    points[s].value = 0;
    int count = n - 1; //记录未知点个数
    while (count >= 0)
    {
        int min = MAX;
        int temp;
        for (int i = 0; i < n; i++) //寻找最小未知点
        {
            if (points[i].value < min && !points[i].know)
            {
                temp = i;
                min = points[i].value;
            }
        }
        points[temp].know = true; //将找到的点设为已知
        count -= 1;
        for (int i = 0; i < n; i++) //寻找邻接点
        {
            if (arc[temp][i] != 0)
            {
                if (arc[temp][i] + points[temp].value < points[i].value)
                {
                    points[i].value = arc[temp][i] + points[temp].value; //更新距离
                    points[i].path = temp;                               //记录路径
                }
            }
        }
    }
    cout << "顶点" << s << "到顶点" << e << "的最短路径为(";
    int k = e;
    while (k != s) //回溯路径
    {
        cout << k << "<--";
        k = points[k].path;
    }
    cout << s;
    cout << "),距离为" << points[e].value << endl;
    return points[e].value;
}