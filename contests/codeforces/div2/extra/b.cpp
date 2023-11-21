#include <bits/stdc++.h>
using namespace std;

int x, y; 

void solve(int n){
    if(n >= 10) solve(n/10);
    x*= 10;
    y*= 10;
    x += (n%10)/2;
    y += (n%10+1)/2;
    if(n&1) swap(x, y);
}

int main(){
    int t; cin >> t;
    while(t--){
        int n; cin >> n;
        x=y=0;
        solve(n);
        cout << x << " " << y << endl;
    }
}