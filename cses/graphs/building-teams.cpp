#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 150000;
int graph[MAXN];

signed main(){
    fastio;
    int n, m; cin >> n >> m;
    for(int i = 1; i <= m; i++){
        int a, b; cin >> a >> b;
        graph[a] = 1;
        graph[b] = 2;
    }

    for(int i = 1; i <= n; i++){
        cout << graph[i] << " ";
    }
    cout << endl;
}