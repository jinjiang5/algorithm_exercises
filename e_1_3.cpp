/*
输入：一个数组a[n]
输出：数组a[n]中相差最小的两个元素的差
1.result = INT_MAX
2.循环变量i从0~n-1,执行下述操作:
    2.1 循环变量j从i+1~n,执行下述操作
        2.1.1   difference = abs(a[i] - a[j]);
        2.1.2   如果difference < result,则result = difference;
        2.1.3   如果result等于0,则结束循环,输出result;
        2.1.4   如果result不等于0,则j=j+1;
    2.2 i=i+1;
3.输出result;
*/

#include <iostream>
#include <cmath>
#include <climits>

using namespace std;

int min_difference(int *array, int len)
{
    int result = INT_MAX;
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; j < len; j++)
        {
            int difference = abs(array[i] - array[j]);
            result = difference < result ? difference : result;
            if (result == 0)
            {
                return result;
            }
        }
    }
    return result;
}

int main()
{
    int a[] = {1, 2, 3, 4, 5, 6};
    int len = sizeof(a) / sizeof(a[0]);
    cout << min_difference(a, len) << endl;
    return 0;
}