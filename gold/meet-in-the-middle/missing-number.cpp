#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int val = 0;
    for(int i = 0; i < n-1; i++){
        int x; cin >> x;
        val ^= x;
    }
    int val2= 0;
    for(int i = 1; i <= n; i++){
        val2 ^=i;
    }
    cout << (val^val2) << endl;
}