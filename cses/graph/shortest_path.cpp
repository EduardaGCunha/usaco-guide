#include <bits/stdc++.h>
using namespace std;
#define int long long int
int n, m;
vector<pair<int, int>> graph[200005];
vector<int> dist;
const int MAXD = 1e17;
 
void dijsktra(){
    for(int i = 0; i <= n; ++i)
	{
		dist[i] = MAXD;
	}
    dist[1] = 0;
    priority_queue<pair<int,int>, 
	vector<pair<int,int>>, 
	greater<pair<int,int>> > q;
    q.push({0,1});
    while (!q.empty()) {
        int a = q.top().second, b = q.top().first;
        q.pop();
        if(dist[a] < b) continue;
        for (auto u : graph[a]) {
            int e = u.first, f = u.second;
            if (dist[e] >= b + f) {
                dist[e] = b + f;
                q.push({dist[e],e});
            }
        }
    }
}
 
int32_t main(){
    cin >> n >> m;
    dist.resize(n+1);
    for(int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({b, c});
    }
 
    dijsktra();
 
    for(int i = 1; i < n+1; i++){
        cout << dist[i] << " "; 
    }
 
}