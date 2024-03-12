#include <bits/stdc++.h>
using namespace std;


int main(){
    freopen("moocast.in", "r", stdin);
    freopen("moocast.out", "w", stdout);
    int n; cin >> n;
    vector<pair<int, int>> coord(n);
    int radius[n+1];
    for(int i = 0; i < n; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        coord[i].first = a;
        coord[i].second = b;
        radius[i] = c;
    }

    vector<vector<int>> graph(n);
    for(int i = 0; i < n; i++){
        int x1 = coord[i].first, y1 = coord[i].second;
        for(int j = i+1; j < n; j++){
            int x2 = coord[j].first, y2 = coord[j].second;
            double res = sqrt((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));
            if(res <= radius[i]){
                graph[i].push_back(j);
            }else if(res <= radius[j]){
                graph[j].push_back(i);
            }
        }
    }

    int res = 0;
    for(int i = 0; i < n; i++){
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(i);
        int cnt = 0;
        while(!q.empty()){
            int v = q.front(); q.pop();
            visited[v] = true;
            cnt++;
            for(auto u : graph[v]){
                if(!visited[u]) q.push(u);
            }
        }
        res = max(res, cnt);
    }
    cout << res << endl;
}