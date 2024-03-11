#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)

signed main(){
    fastio;
    int t; cin >> t;
    while(t--){
        int n, m; cin >> n >> m;
        vector<vector<int>> graph(n);
        unordered_set<int> s1, s2;
        for(int i = 0; i < m; i++){
            int a, b; cin >> a >> b;
            a--, b--;
            graph[a].push_back(b);
            graph[b].push_back(a);
        }

        queue<int> q;
        q.push(0);
        vector<int> dist(n, 1e9);
        dist[0] = 0;
        while(!q.empty()){
            int u = q.front(); q.pop();
            for(auto a : graph[u]){
                if(dist[a] == 1e9){
                    dist[a] = dist[u] + 1;
                    q.push(a);
                }
            }
        }

        for(int i = 0; i < n; i++){
           if(dist[i] & 1) s1.insert(i);
           else s2.insert(i);
        }
        if(s1.size() < s2.size()){
            cout << s1.size() << endl;
            for(auto a : s1){
                cout << a+1 << " ";
            }
        }else{
            cout << s2.size() << endl;
            for(auto a : s2){
                cout << a+1 << " ";
            }
        }
        cout << endl;
    }
}