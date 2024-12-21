#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1e5+7;
vector<pair<int, int>> graph[MAXN];
int hay[MAXN];

int main(){
    int n, m, k; cin >> n >> m >> k;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        graph[a].push_back({b, c});
        graph[b].push_back({a, c});
    }

    for(int i = 0; i < k; i++){
        int a, b; cin >> a >> b;
        hay[a] = b;
    }

    //dist, node
    priority_queue<pair<int, int>> pq;
    for(int i = 1; i < n; i++){
        
    }
}