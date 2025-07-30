#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int MAXN = 2e5+7;
int d = 0, dist = 0;
vector<int> graph1[MAXN], graph2[MAXN];

void dfs(int v, int p, int dis, int g){
    if(!g){
        for(auto u : graph1[v]){
            if(u == p) continue;
            dfs(u, v, dis+1, g);
        }
 
    }else{
        for(auto u : graph2[v]){
            if(u == p) continue;
            dfs(u, v, dis+1, g);
        }
    }

    if(dis > dist){
        d = v;
        dist = dis;
    }
}


signed main(){
	//fastio;
	int n; cin >> n;
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph1[a].push_back(b);
        graph1[b].push_back(a);
    }
    //cout << "passou da leitura do grafo\n";
    dist = 0, d = -1;
    dfs(0, 0, 0, 0);
    int d1 = d;
    dist = 0, d = -1;
    dfs(d1, -1, 0, 0);
    //int d2 = d;
    int ans = dist;
    //cout << "diam1: " << d1+1 << " diam2: " << d2+1 << endl;

    int m; cin >> m;
    for(int i = 0; i < m-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph2[a].push_back(b);
        graph2[b].push_back(a);
    }

    dist = 0, d = -1;
    dfs(0, 0, 0, 1);
    int d3 = d;
    dist = 0, d = -1;
    dfs(d3, -1, 0, 1);
    ans = max({ans, dist, (ans+1)/2 + (dist+1)/2 + 1});
    cout << ans << endl;
}