#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define endl "\n"

const int MAXL = 20;
const int MAXN = 1e6+ 7;
vector<int> graph[MAXN];
int depth[MAXN]; 
int anc[MAXN][MAXL];

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];
    for(int i = MAXL-1; i >= 0; i--){
        if(k & (1 << i)){
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

int dist(int a, int b){
    int mac = lca(a, b);
    return depth[a] + depth[b] - 2 * depth[mac];
}

signed main(){
    fastio;

    depth[1] = 0;
    anc[1][0] = 1; 
    for (int i = 2; i <= 4; i++){
        depth[i] = 1;
        anc[i][0] = 1;
    }

    int q; cin >> q;
    int n = 4;
    int dim = 2, node1 = 2, node2 = 3;
    
    while(q--){
        int v; cin >> v;
        
        depth[n+1] = depth[v] + 1;
        depth[n+2] = depth[v] + 1;
        
        anc[n+1][0] = v;
        anc[n+2][0] = v;
        for (int i = 1; i < MAXL; i++){
            anc[n+1][i] = anc[anc[n+1][i-1]][i-1];
            anc[n+2][i] = anc[anc[n+2][i-1]][i-1];
        }

        for (int i = n+1; i <= n+2; i++){
            int d1 = dist(node1, i);
            int d2 = dist(node2, i);
            if(d1 > dim){
                dim = d1;
                node2 = i;
            }
            if(d2 > dim){
                dim = d2;
                node1 = i;
            }
        }
        
        cout << dim << "\n";
        n += 2;
    }
    return 0;
}
