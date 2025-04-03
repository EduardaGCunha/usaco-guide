#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"
#define int long long

const int MAXL = 10;
const int MAXN = 1001;
int conn[MAXN];
vector<int> graph[MAXN];
int depth[MAXN];
int anc[MAXN][MAXL];

struct fence{
    int r, a, b;
    bool operator<(const fence &other){
        return r < other.r;
    }
};

int dist(int x1, int y1, int x2, int y2){
    return (x1-x2)*(x1-x2) + (y1-y2)*(y1-y2);
}

void dfs(int v, int p){
    depth[v] = depth[p] + 1;
    anc[v][0] = p;
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }

    for(auto u : graph[v]) if(u != p) dfs(u, v);
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = MAXL-1; i >= 0; i--){
        if(k&(1<<i)){
            a = anc[a][i];
        }
    }
    
    if(a == b) return a;
    for(int i = MAXL-1; i >= 0; i--){
        if(anc[a][i] != anc[b][i]){
            a = anc[a][i];
            b = anc[b][i];
        }
    }
    return anc[a][0];
}


signed main(){
    int n, m, k; cin >> n >> m >> k;

    vector<pair<int, int>> points;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        points.push_back({a, b});
    }

    vector<fence> fences;
    for(int i = 0; i < m; i++){
        fence a; cin >> a.r >> a.a >> a.b;
        fences.push_back(a);
    }

    sort(fences.begin(), fences.end());

    //p/ cada vertice, achar a menor fence q contem ele
    for(int i = 0; i < n; i++){
        int achou = 0;
        //teoricamente eh pra estar achando a menor fence q contem um cara x 
        for(int j = 0; j < m; j++){
            int dx = points[i].first - fences[j].a;
            int dy = points[i].second - fences[j].b;
            if((dx)*(dx) + (dy)*(dy) > fences[j].r*fences[j].r) continue;
            achou = 1;
            conn[i] = j;
            break;
        }
        if(!achou) conn[i] = m;
    }

    // for(int i = 0; i < n; i++){
    //     cout << i << ": " << conn[i] << endl;
    // }

    for(int i = 0; i < m; i++){
        int achou = 0;
        for(int j = i+1; j < m; j++){
            int dx = fences[i].a - fences[j].a;
            int dy = fences[i].b - fences[j].b;
            if((dx*dx)+(dy*dy) > (fences[i].r - fences[j].r)*(fences[i].r - fences[j].r)) continue;
            //j contem i 
            achou = 1;
            graph[i].push_back(j);
            graph[j].push_back(i);
            break;
        }
        if(!achou){
            graph[i].push_back(m);
            graph[m].push_back(i);
        }
    }

    //cout << "passou da criacao do grafo\n";

    dfs(m, m);
    while(k--){
        //cout << "entrou no loop\n";
        int a, b; cin >> a >> b;
        a--; b--;
        int mac = lca(conn[a], conn[b]);
        cout << depth[conn[a]] + depth[conn[b]] - 2*depth[mac] << endl;
    }

}