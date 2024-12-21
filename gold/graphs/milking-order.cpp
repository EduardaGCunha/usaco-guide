#include <bits/stdc++.h>
using namespace std;

int n, m;
const int MAXN = 5*(1e4)+7;
vector<int> conn[MAXN];
vector<int> toposort;

bool check(int mid){
    toposort.clear();
    priority_queue<int, vector<int>, greater<int>> pq;
    vector<int> indeg(n+1, 0);
    vector<vector<int>> graph(n+1, vector<int>());
    for(int i = 0; i <= mid; i++){
        for(int j = 1; j < conn[i].size(); j++){
            indeg[conn[i][j]]++;
            graph[conn[i][j-1]].push_back(conn[i][j]);
        }
    }
    for(int i = 1; i <= n; i++){
        if(indeg[i] == 0){
            pq.push(i);
        }
    }

    int cnt = 0;
    while(!pq.empty()){
        int v = pq.top(); pq.pop();
        cnt++;
        toposort.push_back(v);
        for(auto u : graph[v]){
            if(--indeg[u] == 0) pq.push(u);
        }
    }

    return (cnt == n);
}

int main(){
    //mais ou menos 15 casos para cada 
    freopen("milkorder.in", "r", stdin);
    freopen("milkorder.out", "w", stdout);
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int t; cin >> t;
        while(t--){
            int a; cin >> a;
            conn[i].push_back(a);
        }
    }

    int l = 0, r = m-1; 
    while(l < r){
        int mid = (l+r)/2;
        if(check(mid)) l = mid+1;
        else r = mid;
    }

    for(int i = 0; i < n; i++){
        cout << toposort[i] << (i!= n-1? " " : "");
    }

}