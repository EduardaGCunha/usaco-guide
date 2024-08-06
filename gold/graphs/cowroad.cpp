#include <bits/stdc++.h>
using namespace std;

#define int long long

const int MAXN = 1e3;
const int INF = 1e18;
int grid[MAXN][MAXN];
int dist[MAXN][MAXN][3], visited[MAXN][MAXN][3];

int d1[] = {0, 1, 0, -1};
int d2[] = {1, 0, -1, 0};

signed main(){
    freopen("visitfj.in", "r", stdin);
    freopen("visitfj.out", "w", stdout);
    int n, k; cin >> n >> k;

    //lendo e inicializando dist com INF
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> grid[i][j];
            dist[i][j][0] = INF;
            dist[i][j][1] = INF;
            dist[i][j][2] = INF;
        }
    }

    //nodei, nodej, dist, tempo
    priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
    pq.push({0, 0, 0, 1});
    dist[0][0][0] = k;

    while(!pq.empty()){
        auto [x, y, w, t] = pq.top(); pq.pop();
        for(int i = 0; i < 4; i++){
            int dx = x + d1[i];
            int dy = y + d2[i];
            if(dx < 0 || dx >= n) continue;
            if(dy < 0 || dy >= n) continue;
            int new_cost = (t == 0) * grid[dx][dy] + w + k;
            if(dist[dx][dy][(t+1)%3] > new_cost){
                dist[dx][dy][(t+1)%3] = new_cost;
                pq.push({dx, dy, new_cost, (t+1)%3});
            }
        }
    }

    cout << min({dist[n-1][n-1][0], dist[n-1][n-1][1], dist[n-1][n-1][2]}) << endl;

}