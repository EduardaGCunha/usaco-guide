#include <bits/stdc++.h>
using namespace std;

int main(){
    int n; cin >> n;
    int x = 0;
    for(int i = 0; i < n; i++){
        int a; cin >> a;
        x |= (1<<a);
    }
    cout << __builtin_popcount(x) << '\n';
}