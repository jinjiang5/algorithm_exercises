#include <iostream>

using namespace std;

int alllist(int n){
    int m = 1 << n;
    for(int i = 0; i < m; i++){
        for(int j = 0,k = 1; j < n; j++){
            cout << ((i & k) || 0) << " ";
            k = k << 1;
        }
        cout << endl;
    }
}

int main(){
    int n;
    cout << "input n:";
    cin >> n;
    alllist(n);
    //cout << (1<<1) << endl;
    return 0;
}

