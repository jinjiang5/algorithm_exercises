#include <iostream>

using namespace std;

typedef struct Range
{
    int len;
    int *data;
} Range;

Range BinSearch(int r[], int n, int a, int b);

int main()
{
    int r[] = {1, 3, 5, 7, 9, 11, 13, 15};
    Range range = BinSearch(r, 8, 13, 15);
    for (int i = 0; i < range.len;i++){
        cout << range.data[i] << " ";
    }
}

Range BinSearch(int r[], int n, int a, int b)
{
    Range range;
    int left, right;
    //判断两个集合是否相交
    if (a > r[n - 1] || b < r[0])
    {
        range.len = 0;
        range.data = NULL;
        return range;
    }
    //查找左界
    if (a <= r[0])    left = 0;
    else
    {
        int low = 1, high = n - 1;
        int mid;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (r[mid] > a)
            {
                if (r[mid - 1] < a)
                {
                    left = mid;
                    break;
                }
                else    high = mid - 1;
            }
            else if (r[mid] < a)
            {
                if (r[mid + 1] > a)
                {
                    left = mid + 1;
                    break;
                }
                else    low = mid + 1;
            }
            else
            {
                left = mid;
                break;
            }
        }
    }
    //查找右界
    if (b >= r[n - 1])    right = n - 1;
    else
    {
        int low = 1, high = n - 1;
        int mid;
        while (low <= high)
        {
            if (r[mid] > b)
            {
                if (r[mid - 1] < b)
                {
                    right = mid - 1;
                    break;
                }
                else    high = mid - 1;
            }
            else if (r[mid < b])
            {
                if (r[mid + 1] > b)
                {
                    right = mid;
                    break;
                }
                else    low = mid + 1;
            }
            else    right = mid;
            
        }
    }
    range.len = right - left + 1;
    range.data = r + left;
    return range;
}