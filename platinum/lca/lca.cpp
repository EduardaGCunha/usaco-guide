#include <bits/stdc++.h>
using namespace std;

const int MAXL = 20;
const int MAXN = 1007;
vector<int> graph[MAXN];
int depth[MAXN];
int up[MAXN][MAXL];

//percorrendo o grafo e montando os jumps
void dfs(int v, int p){
    up[v][0] = p;
    depth[v] = depth[p]+1;
    for(int i = 1; i < MAXL; i++){
        up[v][i] = up[up[v][i-1]][i-1];
    }
    for(auto u : graph[v]){
        if(u != p) dfs(u, v);
    }
}

int lca(int a, int b){
    if(depth[a] < depth[b]) swap(a, b);
    int k = depth[a] - depth[b];

    //deixando eles no msm nivel
    for(int i = MAXL-1; i >= 0; i--){
        //se esse bit estiver ativo, ent iremos pular isso de diferença
        if(k&(1<<i)){
            a = up[a][i];
        }
    }

    if(a == b) return a;
    
    for(int i = MAXL-1; i >= 0; i--){
        //se nn forem igual, significa q essa eh a primeira posicao q eles sao diferentes
        if(up[a][i] != up[b][i]){
            a = up[a][i];
            b = up[b][i];
        }
    }
    return up[a][0];
}

int main(){
    int t; cin >> t;
    for(int tt = 1; tt <= t; tt++){
        int n; cin >> n;
        memset(up, 0, sizeof(up));
        memset(depth, 0, sizeof(depth));

        for(int i = 0; i < n; i++){
            graph[i].clear();
        }
        for(int i = 1; i <= n; i++){
            int k; cin >> k;
            if(!k) continue;
            for(int j = 0; j < k; j++){
                int a; cin >> a;
                graph[i].push_back(a);
                graph[a].push_back(i);
            }
        }

        depth[1] = 0;
        dfs(1, 1);

        int q; cin >> q;
        cout << "Case " << tt << ":\n";
        while(q--){
            int a, b; cin >> a >> b;
            cout << lca(a, b) << endl;
        }
    }
}