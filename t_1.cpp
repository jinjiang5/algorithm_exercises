#include <iostream>

using namespace std;
//int points[5];

int Find(int x)
{
    int points[5]={3,4,3,4,4};
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
int main(int argc, char **argv)
{
    Find(2);
    return 0;
}