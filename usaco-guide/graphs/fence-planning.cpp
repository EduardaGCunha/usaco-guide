#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100000;
vector<int> graph[MAXN], connected[MAXN];
int visited[MAXN];

void dfs(int v, int c){
    visited[v] = 1;
    connected[c].push_back(v);
    for(auto a : graph[v]){
        if(!visited[a]) dfs(a, c);
    }
}

int main(){
    freopen("fenceplan.in", "r", stdin);
    freopen("fenceplan.out", "w", stdout);
    int n, m; cin >> n >> m;
    vector<pair<int, int>> coordinates(n);
    for(int i = 0; i < n; i++){
        int x, y; cin >> x >> y;
        coordinates[i].first = x;
        coordinates[i].second = y;
    }

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    int c = 0;
    for(int i = 0; i < n; i++){
        if(!visited[i]){
            c++;
            dfs(i, c);
        }
    }

    int ans = INT_MAX;
    int i = 1;
    while(!connected[i].empty()){
        int xmin = INT_MAX, ymin = INT_MAX;
        int xmax = INT_MIN, ymax = INT_MIN;
        for(auto comp : connected[i]){
            xmax = max(xmax, coordinates[comp].first);
            xmin = min(xmin, coordinates[comp].first);
            ymin = min(ymin, coordinates[comp].second);
            ymax = max(ymax, coordinates[comp].second);
            //cout << coordinates[comp].first << " " << coordinates[comp].second << endl;
        }
        ans = min(ans, 2*(xmax - xmin) + 2*(ymax - ymin));
        i++;
    }

    cout << ans << endl;

}