#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2*(1e5)+7;
vector<int> graph[MAXN];
//p essa depth, quais sao os vertices assimilados a ela?
map<int, vector<int>> dep;
//p essa prof, qual subarvore v quero olhar e o indice?
map<int, vector<pair<int, int>>> queries;
int depth[MAXN], tin[MAXN], tout[MAXN];
int t = 0, profm = 0;

struct BIT {
    int n;
    vector<int> bit;
    void init(int _n){
        n = _n+1;
        bit.resize(n, 0);
    }

    void upd(int x, int v){
        for(; x <= n; x+=x&(-x)) bit[x] += v;
    }

    int sum(int x){
        int s = 0;
        for(; x > 0; x -= x&(-x)) s += bit[x];
        return s;
    }

    int query(int l, int r){
        return sum(r) - sum(l-1);
    }
};

void dfs(int v, int p){
    depth[v] = depth[p] + 1;
    profm = max(profm, depth[v]);
    tin[v] = ++t;
    for(auto u : graph[v]){
        if(u != p) dfs(u, v);
    }
    tout[v] = t;
}

signed main(){
    fastio;
    int n; cin >> n;
    for(int i = 2; i <= n; i++){
        int x; cin >> x;
        graph[i].push_back(x);
        graph[x].push_back(i);
    }
    //cout << "passou da leitura do grafo\n";
    dfs(1, 0);
    for(int i = 1; i <= n; i++){
        dep[depth[i]].push_back(i);
    }
    int q; cin >> q;
    for(int i = 0; i < q; i++){
        int v, prof; cin >> v >> prof;
        prof++;
        queries[prof].push_back({v, i}); 
    }

    //cout << "passou da leitura das queries\n";

    // for(auto u : dep){
    //     cout << "para profundidade u " << u.first << " os vertices associdados sao\n";
    //     for(auto v : u.second){
    //         cout << v << " ";
    //     }
    //     cout << endl;
    // }

    // for(auto u : queries){
    //     cout << "para query de profundidade u " << u.first << " os vertices associdados sao\n";
    //     for(auto v : u.second){
    //         cout << v.first << " ";
    //     }
    //     cout << endl;
    // }

    BIT bit;
    bit.init(n);
    vector<int> ans(q, 0);
    //cout << "profm " << profm << endl;
    for(int i = profm; i > 0; i--){
        /*
        passando por todo vertice v q tem prof i e atualizando ele
        */
        //cout << "dado a prof " << i << " esses sao os vertices q vao ser atualizados\n";
        for(auto u : dep[i]){
            //cout << u << " na posicao " << tin[u] << endl;
            bit.upd(tin[u], 1);
        }
        //cout << endl;

        //passando por toda query q tem essa profundidade
        for(auto u : queries[i]){
            //p cada query, quero saber quantos caras tem marcado na subarvore de i q tem essa profundidade
            ans[u.second] = bit.query(tin[u.first], tout[u.first]);
        }

        for(auto u : dep[i]){
            bit.upd(tin[u], -1);
        }
    }

    for(int i = 0; i < q; i++){
        cout << ans[i] << endl;
    }
}