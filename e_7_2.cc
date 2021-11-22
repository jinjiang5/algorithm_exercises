#include <iostream>

using namespace std;
#define N 100
typedef struct edge
{
    int value;
    int from;
    int end;
} edge;
int points[N];

int Find(int x)
{

    int root, parent;
    root = x;
    while (points[root] != root)
        root = points[root];
    parent = points[x]; //路径压缩
    while (root != parent)
    {
        points[x] = root;
        x = parent;
        parent = points[x];
    }
    return root;
}
int Union(int a, int b)
{
    int root_a = Find(a);
    int root_b = Find(b);
    points[root_b] = root_a;
    return root_a;
}
bool com_edge(edge a, edge b)
{
    return a.value < b.value;
}
template <typename T>
void SiftHeap(T *r, int k, int n, bool (*func)(T, T))
{
    int i, j;
    T temp;
    i = k;
    j = 2 * i + 1;
    while (j < n)
    {
        if (j < n - 1 && func(r[j], r[j + 1]))
            j++;
        if (func(r[j], r[i]))
        {
            break;
        }
        else
        {
            temp = r[i];
            r[i] = r[j];
            r[j] = temp;
            i = j;
            j = 2 * i + 1;
        }
    }
}
template <typename T>
void sort(T *r, int t, bool (*func)(T, T))
{
    int i;
    T temp;
    for (i = (t - 1) / 2; i >= 0; i--)
    {
        SiftHeap(r, i, t, func);
    }
    for (i = 1; i <= t - 1; i++)
    {
        temp = r[0];
        r[0] = r[t - i];
        r[t - i] = temp;
        SiftHeap(r, 0, t - i, func);
    }
}

int TSP2(int arc[N][N], int n)
{
    for (int i = 0; i < n; i++)
    { //初始化并查集
        points[i] = i;
    }
    int point_set[n];
    for (int i = 0; i < n; i++)
    {
        point_set[i] = 0;
    }
    edge result[n];
    int TSPLength = 0;
    edge edges[(n * n - n) / 2];
    for (int i = 1, count = 0; i < n; i++)
    {
        for (int j = 0; j < i; j++)
        {
            edges[count].value = arc[i][j];
            edges[count].from = i;
            edges[count].end = j;
            count += 1;
        }
    }
    sort(edges, (n * n - n) / 2, com_edge);
    for (int i = 0, count = 0; i < (n * n - n) / 2 && count < n - 1; i++)
    {
        if (Find(edges[i].from) != Find(edges[i].end) && point_set[edges[i].from] < 2 && point_set[edges[i].end] < 2)
        {
            result[count] = edges[i];
            cout << result[count].from << "---" << result[count].end << "     " << result[count].value << endl;
            TSPLength += edges[i].value;
            point_set[edges[i].from] += 1;
            point_set[edges[i].end] += 1;
            Union(edges[i].from, edges[i].end);
            count += 1;
        }
    }
    int last_edge[2];
    for(int i = 0, count = 0; i < n && count < 2; i++){
        if(point_set[i] == 1){
            last_edge[count] = i;
            count += 1;
        }
    }
    result[n].from = last_edge[0];
    result[n].end = last_edge[1];
    result[n].value = arc[result[n].from][result[n].end];
    cout << result[n].from << "---" << result[n].end << "     " << result[n].value << endl;
    TSPLength += result[n].value;
    cout << "最短路径长度为:" << TSPLength << endl;
    return 0;
}

int main()
{
    /*
    int arc[N][N] = {{0, 3, 3, 2, 6},
                     {3, 0, 7, 3, 2},
                     {3, 7, 0, 2, 5},
                     {2, 3, 2, 0, 3},
                     {6, 2, 5, 3, 0}};
                     int arc[N][N];
    */
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
    TSP2(arc, n);
    return 0;
}