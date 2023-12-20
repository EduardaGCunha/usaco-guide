#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("speeding.in", "r", stdin);
    int n, m; cin >> n >> m;
    int s[101], l[101];
    int u = 1, mx = 0;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        while(a--){
            l[u++] = b;
        }
    }

    u = 1;
    for(int i = 0; i < m; i++){
        int c, d; cin >> c >> d;
        while(c--){
            s[u++] = d;
        }
    }

    for(int i = 1; i <= 100; i++){
        if(s[i] > l[i]){
            mx = max(mx, s[i] - l[i]);
        }
    }

    freopen("speeding.out", "w", stdout);
    cout << mx << endl;

}