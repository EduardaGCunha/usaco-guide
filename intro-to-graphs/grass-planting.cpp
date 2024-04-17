#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("planting.in", "r", stdin);
    freopen("planting.out", "w", stdout);
    int n; cin >> n;
   
    vector<int> connections(n-1);
    for(int i = 0; i < n - 1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        connections[a]++, connections[b]++;
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        res = max(res, connections[i]);
    }

    cout << res + 1 << endl;
}