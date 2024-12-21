#include <bits/stdc++.h>
using namespace std;


void solve(){
        int n, m; cin >> n >> m;
        vector<vector<int>> directed(n);
        vector<vector<int>> undirected(n);
        vector<int> indeg(n, 0);
        for(int i = 0; i < m; i++){
            int a, b, c; cin >> a >> b >> c;
            b--, c--;
            if(a) {
                directed[b].push_back(c);
                indeg[c]++;
            }
            else {
                undirected[b].push_back(c);
                undirected[c].push_back(b);
            }
        }

        queue<int> q;
        for(int i = 0; i < n; i++){
            if(!indeg[i]) q.push(i);
        }

        if(q.empty()){
            cout << "NO" << endl;
            return;
        }

        vector<int> toposort;
        int cnt = 0;
        while(cnt < n && !q.empty()){
            int v = q.front(); q.pop();
            ++cnt;
            toposort.push_back(v);
            for(auto u : directed[v]){
                if(--indeg[u] == 0) q.push(u);
            }
        }

        if(cnt < n){
            cout << "NO" << endl;
            return;
        }
        cout << "YES" << endl;
        vector<int> visited(n, 0);
        for(auto v : toposort){
            visited[v] = 1;
            for(auto u : undirected[v]){
                if(visited[u]) continue;
                cout << v+1 << " " << u+1 << endl;
            }
            for(auto u : directed[v]){
                cout << v+1 << " " << u+1 << endl;
            }
        }
}

int main(){
    int t; cin >> t;
    while(t--){
        solve();
    }
}