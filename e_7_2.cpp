#include <stdio.h>
#include <cstring>
using namespace std;
#define N 50
typedef struct edge
{
    int value;
    int from;
    int end;
} edge;

template<typename T>
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
template<typename T>
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
int edge_set[N];
int radio[N];
edge result[N];
int Find(int x)
{

    int root, parent;
    root = x;
    while (edge_set[root] != root)
        root = edge_set[root];
    parent = edge_set[x]; //路径压缩
    while (root != parent)
    {
        edge_set[x] = root;
        x = parent;
        parent = edge_set[x];
    }
    return root;
}
int Union(int a, int b)
{
    int root_a = Find(a);
    int root_b = Find(b);
    edge_set[root_b] = root_a;
    return root_a;
}
bool com_edge(edge a, edge b)
{
    return a.value < b.value;
}
int TSP_Short(int dis[][N], int n, edge edge[])
{
    int temp = (n * (n - 1)) / 2; // 边的个数
    int i;
    int count = 0;
    int k = 0;
    for (i = 0; i < temp; i++)
        if (edge[i].value != 0)
        {
            if ((Find(edge[i].from) != Find(edge[i].end)) && radio[edge[i].from] != 2 && radio[edge[i].end] != 2)
            {
                count += edge[i].value;
                radio[edge[i].from]++;
                radio[edge[i].end]++;
                result[k].value = edge[i].value;
                result[k].from = edge[i].from;
                result[k].end = edge[i].end;
                Union(edge[i].from, edge[i].end);
                k++;
                if (k == n - 1)
                    break;
            }
        }
    return count;
}
int main()
{
    int n;
    printf("请输入顶点个数：");
    scanf("%d", &n);
    int i, j;
    int dis[N][N];
    printf("输入%d阶对称矩阵：\n", n);
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            scanf("%d", &dis[i][j]);
    edge edge[N];
    int cost = 0;
    int t = 0;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= i - 1; j++)
        {
            edge[t].value = dis[i][j];
            if (i < j)
            {
                edge[t].from = i;
                edge[t].end = j;
            }
            else
            {
                edge[t].from = j;
                edge[t].end = i;
            }
            t++;
        }
    sort(edge, t, com_edge);
    for (i = 1; i <= n; i++)
        edge_set[i] = i;
    memset(radio, 0, sizeof(radio));
    cost = TSP_Short(dis, n, edge);
    int end[2];
    int x = 0;
    for (i = 1; i <= n; i++)
    {
        if (radio[i] == 1)
            end[x++] = i;
    }
    printf("边的两个顶点：");
    for (i = 0; i < n - 1; i++)
        printf("v%d--v%d\t%d\n", result[i].from, result[i].end, result[i].value);
    printf("v%d--v%d\t%d\n", end[0], end[1], dis[end[0]][end[1]]);
    printf("%d\n", cost + dis[end[0]][end[1]]);
    return 0;
}