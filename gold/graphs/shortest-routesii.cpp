#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 503;
int graph[MAXN][MAXN];
int dist[MAXN][MAXN];

const int INF = 1e13;


signed main(){
    int n, m, q; cin >> n >> m >> q;
    for(int i = 1; i<= n; i++){
        for(int j = 1; j<= n; j++){
            if(i == j) dist[i][j] = 0;
            else dist[i][j] = INF;
        }
    }
    for(int i = 1; i <= m; i++){
        int a, b, c; cin >> a >> b >> c;
        if(dist[a][b] > c) dist[a][b] = dist[b][a] = c; 
    }

    for(int k = 1; k <= n; k++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
            }
        }
    }

    for(int i = 0; i < q; i++){
        int a, b; cin >> a >> b;
        if(dist[a][b] == INF) cout << "-1" << endl;
        else cout << dist[a][b] << endl;
    }


}