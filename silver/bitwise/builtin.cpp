#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    cout << (1 << __builtin_ctz(n)) << endl;
    cout << 1 << (32 - __builtin_clz(n-1)) << endl;
}