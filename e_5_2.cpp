#include <iostream>

using namespace std;

int BinSearch(int r[], int low, int high, int k);

int main()
{
    int r[7] = {1, 2, 3, 4, 5, 6, 7};
    int low = 0;  //在C++中数组下标从0开始
    int high = 6; //第i个元素存储在r[i-1]中
    cout << BinSearch(r, low, high, 5) << endl;
    //若要将第一个元素的序号定义为1,将结果加一即可
    return 0;
}

int BinSearch(int r[], int low, int high, int k)
{
    int mid = (low + high) / 2; //取中间点
    if (low > high)
    {
        return -1; //查询失败返回-1
    }
    if (r[mid] > k)
    {
        return BinSearch(r, low, mid - 1, k);
    }
    else if (r[mid] < k)
    {
        return BinSearch(r, mid + 1, high, k);
    }
    else
    {
        return mid;
    }
}