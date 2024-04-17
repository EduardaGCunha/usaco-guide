#include <bits/stdc++.h>
using namespace std; 

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long

const int MAXN = 200007;

vector<int> graph[MAXN];
int children[MAXN];

void dfs(int v, int p){
    children[v] = 1;
    for(auto a : graph[v]){
        if(a != p){
            dfs(a, v);
        }
        children[v] += children[a];
    }
}

signed main(){
    int n; cin >> n;
    for(int i = 1; i <= n - 1; i++){
        int a; cin >> a; a--;
        graph[a].push_back(i);
    }

    dfs(0, -1);
    for(int i = 0; i < n; i++){
        cout << children[i] - 1 << " ";
    }
    cout << endl;
}