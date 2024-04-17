#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    int n, q; cin >> n >> q;
    vector<int> h(n+1, 0), j(n+1, 0), g(n+1, 0);
    for(int i = 1; i <= n; i++){
        int a; cin >> a;
        h[i] = h[i-1], g[i] = g[i-1], j[i] = j[i-1];
        if(a == 1) h[i]++;
        else if(a == 2) j[i]++;
        else h[i]++;
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << h[b] - h[a-1] << " ";
        cout << j[b] - j[a-1] << " ";
        cout << g[b] - g[a-1] << endl;
    }
}