/*
输入：一个数组a[n]，一个要删除的数x
输出：删除所有x后的数组a[n]
1.初始化变量a=0
2.循环变量i从0~n-1,执行下述操作:
    2.1如果a[i] != x：
        a[p] = a[i]
        p=p+1
3.循环变量i从p到n-1,执行下述操作:
    3.1 a[i] = -1
*/
#include <iostream>

using namespace std;

void delete_x(int a[], int len, int x)
{
    int p = 0;
    for (int i = 0; i < len; i++)
    {
        if (a[i] != x)
        {
            a[p++] = a[i];
        }
    }
    for (int i = p; i < len; i++)
    {
        a[i] = -1;
    }
}

int main()
{
    int a[] = {1, 2, 3, 1, 2, 3, 1, 2, 3};
    int len = sizeof(a) / sizeof(a[0]);
    delete_x(a, len, 1);
    return 0;
}