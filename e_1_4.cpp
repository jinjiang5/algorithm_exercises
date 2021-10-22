/*
输入：一个数组a[n]
输出：数组a[n]中一个既不是最大也不是最小的元素
1 m1 = a[0], m2 = a[0];
2 循环变量i从0~n-1,执行下述操作:
    2.1 如果a[i]小于m1:
        2.1.1 如果m1不等于m2,输出 a[i]
        2.1.2 如果m1等于m2,m1 = a[i]
    2.2 如果a[i]大于m1:
        2.2.1 如果m1不等于m2,输出 a[i]与m2中的小者
        2.2.2 如果m1等于m2,m2 = a[i]
*/

#include <iostream>
using namespace std;

int not_min_max(int *array, int len)
{
    int m1 = array[0], m2 = array[0];
    for (int i = 0; i < len; i++)
    {
        if (array[i] < m1)
        {
            if (m1 != m2)
                return array[i];
            else
                m1 = array[i];
        }
        if (array[i] > m1)
        {
            if (m1 != m2)
                return m2 < array[i] ? m2 : array[i];
            else
                m2 = array[i];
        }
    }
    return 0;
}

int main()
{
    int a[] = {1, 1, 1, 0, 4};
    int len = sizeof(a) / sizeof(a[0]);
    cout << not_min_max(a, len) << endl;
    return 0;
}
