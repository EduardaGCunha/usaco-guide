#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl '\n'

const int INF = 1e18;
const int MAXN = 1e5;
pair<int, int> arestas[MAXN]; 
vector<pair<int, int>> graph[MAXN];
int w[MAXN], d[MAXN], visited[MAXN], n, m;

bool bellmanford(int s){
    for(int i = 0; i < MAXN; i++) d[i] = INF;
    d[s] = 0;

    for(int i = 0; i <= n; i++){
        for(int j = 0; j < m; j++){
            auto [a, b] = arestas[j];
            if(d[b] > d[a] + w[j]){
                if(i == n) return 1;
                d[b] = d[a] + w[j];
            }
        }
    }
    return 0;
}
vector<int> grafo;
bool dfs(int v, int s){
    //cout << v+1 << endl;
    visited[v] = 1;
    if(v == s){
        grafo.push_back(v);
        return true;
    }
    for(auto [u, p] : graph[v]){
        //cout << u+1 << " " << v+1 << " " << d[u] << " " << d[v] << " " << d[v] + p << endl;
        if(!visited[u] && d[u] > d[v] + p){
            d[u] = d[v] + p;
            if(dfs(u, s)){
                grafo.push_back(v);
                return true;
            }
        }
    }
    return false;
}

signed main(){
	fastio;
	cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, weight; cin >> a >> b >> weight;
        a--, b--;
        w[i] = weight;
        arestas[i] = {a, b};
        graph[a].push_back({b, weight});
    }

    if(bellmanford(0)){
        cout << "YES\n";
        for(int i = 0; i < m; i++){
            auto [a, b] = arestas[i];
            if(d[b] > d[a] + w[i]){
                d[b] = d[a]+w[i];
                if(dfs(b, a)){
                    grafo.push_back(a);
                    break;
                }
            }
        }
        reverse(grafo.begin(), grafo.end());
        for(auto u : grafo) cout << u+1 << " ";
        cout << endl;
    }else cout << "NO\n";
}
