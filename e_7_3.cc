#include <iostream>

using namespace std;
#define N 100

typedef struct edge
{
    int value;
    int from;
    int end;
} edge;

int point[N];

int Find(int x)//并查集查找
{

    int root, parent;
    root = x;
    while (point[root] != root)
        root = point[root];
    parent = point[x]; //路径压缩
    while (root != parent)
    {
        point[x] = root;
        x = parent;
        parent = point[x];
    }
    return root;
}
int Union(int a, int b)//并查集合并
{
    int root_a = Find(a);
    int root_b = Find(b);
    point[root_b] = root_a;
    return root_a;
}

int count(int n)//计算连通分量个数
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        if (point[i] == i)
        {
            sum += 1;
        }
    }
    return sum;
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
void sort(T *r, int t, bool (*func)(T, T))//堆排序算法，用C++模板泛型使函数支持多类型参数
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
bool com_edge(edge a, edge b)//边的比较函数
{
    return a.value < b.value;
}

void Kruskal(int arc[N][N], int n)
{

    for (int i = 0; i < n; i++)
    { //初始化并查集
        point[i] = i;
    }
    edge result[n - 1]; //用于保存找到的边
    edge edges[100];    //存储图中所有边
    int t = 0;          //记录边的数量
    int i, j;
    for (i = 0; i < n; i++) //初始化边
        for (j = 0; j <= i - 1; j++)
        {
            edges[t].value = arc[i][j];
            if (i < j)
            {
                edges[t].from = i;
                edges[t].end = j;
            }
            else
            {
                edges[t].from = j;
                edges[t].end = i;
            }
            t++;
        }
    sort(edges, t, com_edge); //用排序算法将边排序
    j = 0;
    for (i = 0; count(n) != 1; i++)
    { //count函数用来判断有几个连通分量
        edge min_edge = edges[i];
        if (min_edge.value != 0)
        {

            if (Find(min_edge.from) != Find(min_edge.end)) //判断边的两点是否属于一个连通分量
            {
                result[j] = min_edge;
                cout << min_edge.from << "---" << min_edge.end << "   长度:" << min_edge.value << endl;
                j += 1;
                Union(min_edge.from, min_edge.end);
            }
        }
    }
    
}

int main()
{
    /*
    int arc[N][N] = {
        {0, 34, 46, 0, 0, 19},
        {34, 0, 0, 0, 12, 0},
        {46, 0, 0, 17, 0, 25},
        {0, 0, 17, 0, 38, 25},
        {0, 12, 0, 38, 0, 26},
        {19, 0, 25, 25, 26, 0}};
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
    Kruskal(arc, n);
    return 0;
}