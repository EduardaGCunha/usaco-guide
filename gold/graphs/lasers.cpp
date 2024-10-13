#include <bits/stdc++.h>
using namespace std;

int main(){
    freopen("lasers.in", "r", stdin);
    freopen("lasers.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> p(n+2); 
    unordered_map<int, vector<int>> mp[2];
    for(int i = 0; i < n+2; i++){
        cin >> p[i].first >> p[i].second;
        mp[0][p[i].first].push_back(i);
        mp[1][p[i].second].push_back(i);
    }

    queue<pair<int, int>> q; 
    q.push({0, 0});
    q.push({0, 1});

    vector<int> dist(n+2, 1e9);
    dist[0] = 0;
    while(!q.empty()){
        auto [c, d] = q.front(); q.pop();
        //cout << c << " " << d << endl;
        int coord = (d ? p[c].first : p[c].second);
        for(auto u : mp[!d][coord]){
            if(dist[u] == 1e9){
                dist[u] = dist[c] + 1;
                q.push({u, !d});
            }
        }
    }

    cout << (dist[1] == 1e9 ? - 1 : dist[1]-1) << endl;

}