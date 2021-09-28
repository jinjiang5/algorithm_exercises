#include <iostream>
#include <string.h>

using namespace std;

void printchars(char ch[], int len)
{
    for (int i = 0; i < len; i++)
    {
        cout << ch[i] << " ";
    }
    cout << endl;
}

int BF(char S[], char T[])
{
    int index = 0;
    int i = 0, j = 0;
    while ((S[i] != '\0') && (T[j] != '\0'))
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            printchars(S, strlen(S));
            for (int o = 0; o < index; o++)
            {
                cout << "  ";
            }
            printchars(T, j + 1);
            cout << "第" << index + 1 << "趟匹配，i = " << i << ", j = " << j << "失败，i回溯到" << index + 1 << "，j回溯到0" << endl;
            cout << "------------------------------------" << endl;
            index++;
            i = index;
            j = 0;
        }
    }
    if (T[j] == '\0')
    {
        printchars(S, strlen(S));
        for (int o = 0; o < index; o++)
        {
            cout << "  ";
        }
        printchars(T, j + 1);
        cout << "第" << index + 1 << "趟匹配，i = " << i << "，j = " << j << "，匹配成功" << endl;
        return index + 1;
    }

    else
        return 0;
}

void GetNext(char T[], int next[])
{
    next[0] = -1;
    for (int j = 1; j < strlen(T); j++)
    {
        int len;
        for (len = j - 1; len > 0; len--)
        {
            int i;
            for (i = 0; i < len; i++)
            {
                if (T[i] != T[j - len + i])
                {
                    break;
                }
            }
            if (i == len)
            {
                next[j] = len;
                break;
            }
        }
        if (len < 1)
        {
            next[j] = 0;
        }
    }
}

int KMP(char S[], char T[])
{
    int count = 0;
    int next[80];
    GetNext(T, next);
    int i = 0, j = 0;
    while (S[i] != '\0' && T[j] != '\0')
    {
        if (S[i] == T[j])
        {
            i++;
            j++;
        }
        else
        {
            count++;
            printchars(S, strlen(S));
            for (int o = 0; o < i - j; o++)
            {
                cout << "  ";
            }
            printchars(T, j + 1);
            cout << "第趟" << count << "匹配，i = " << i << ", j = " << j << "失败，";
            //
            j = next[j];
            if (j == -1)
            {
                i++;
                j++;
                cout << "i变为" << i << "，j回溯到" << j << endl;
            }
            else
            {
                cout << "i不变，j回溯到" << j << endl;
            }
            cout << "------------------------------------" << endl;
        }
    }
    if (T[j] == '\0')
    {
        printchars(S, strlen(S));
        for (int o = 0; o < i - j; o++)
        {
            cout << "  ";
        }
        printchars(T, j + 1);
        cout << "第趟" << count + 1 << "匹配，i = " << i << ", j = " << j << "，匹配成功" << endl;
        return i - j + 1;
    }
    return 0;
}

int main()
{
    char s1[] = "ababcabccabcacbab";
    char s2[] = "abcac";
    KMP(s1, s2);
    return 0;
}