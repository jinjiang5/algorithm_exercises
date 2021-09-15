/*
输入：一个数组a[n]
输出：数组a[n]中一个既不是最大也不是最小的元素
1.初始化P={};
2.循环变量i从0~n-1,执行下述操作:
    2.1 如果a[i]不属于集合P,则P=P+{a[i]};
    2.2 如果P中的元素大于等于3,则结束循环;
    2.3 如果P中的元素小于3,则i=i+1;
3.输出P中的中位数;

*/

#include <iostream>
#include <climits>
using namespace std;

bool is_contain(int *array, int num, int len)
{
    for (int i = 0; i < len; i++)
    {
        if (array[i] == num)
        {
            return true;
        }
    }
    return false;
}

int not_minmax(int *array, int len)
{
    int tmp[] = {INT_MAX, INT_MAX, INT_MAX};
    for (int i = 0, j = 0; i < len && j < 3; i++)
    {
        if (!is_contain(tmp, array[i], 3))
        {
            tmp[j] = array[i];
            j++;
        }
    }
    int m1 = tmp[0] > tmp[1] ? tmp[0] : tmp[1];
    int m2 = tmp[1] > tmp[2] ? tmp[1] : tmp[2];
    return m1 < m2 ? m1 : m2;
}

int main()
{
    int a[] = {1, 1, 2, 3};
    int len = sizeof(a) / sizeof(a[0]);
    cout << not_minmax(a, len) << endl;
    return 0;
}
