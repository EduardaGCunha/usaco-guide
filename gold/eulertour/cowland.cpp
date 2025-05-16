#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 1e5+7;
const int MAXL = 30;
int arr[MAXN], tin[MAXN], tout[MAXN], xorpref[MAXN], depth[MAXN];
vector<int> graph[MAXN];
int anc[MAXN][MAXL];
int t = -1;

struct segtree {
    int n;
    vector<int> t;
    vector<int> lazy;
    void init(int _n) {
        n = _n;
        t.assign(4*n, 0);
        lazy.assign(4*n, 0);
    }

    void propagate(int v, int l, int r){
        if(lazy[v] != 0){
            if((r - l + 1) & 1){
                t[v] ^= lazy[v];
            }
            if(l != r){
                lazy[2*v+1] = op(lazy[2*v+1], lazy[v]);
                lazy[2*v+2] = op(lazy[2*v+2], lazy[v]);
            }
            lazy[v] = 0;
        }
    }

    int op(int a, int b){
        return (a ^ b);
    }

    void updateRange(int v, int l, int r, int lx, int rx, int x){
        propagate(v, l, r);
        if(rx < l || r < lx) return;
        if(lx <= l && r <= rx){
            lazy[v] ^= x;
            propagate(v, l, r);
            return;
        }

        int m = (l+r)/2;
        updateRange(2*v+1, l, m, lx, rx, x);
        updateRange(2*v+2, m+1, r, lx, rx, x);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }

    void updateRange(int l, int r, int val){
        updateRange(0, 0, n-1, l, r, val);
    }

    int queryRange(int v, int l, int r, int lx, int rx){
        propagate(v, l, r);
        if(rx < l || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return op(queryRange(2*v+1, l, m, lx, rx), queryRange(2*v+2, m+1, r, lx, rx));
    }

    int query(int l, int r){
        return queryRange(0, 0, n-1, l, r);
    }

    void build(vector<int> &a, int v, int l, int r) {
        if (l == r) {
            t[v] = a[l];
            return;
        }
        int m = (l + r)/2;
        build(a, 2*v+1, l, m);
        build(a, 2*v+2, m+1, r);
        t[v] = op(t[2*v+1], t[2*v+2]);
    }
    void build(vector<int> &a) {
        build(a, 0, 0, n-1);
    }

};

void dfs(int v, int p, int x){
    depth[v] = depth[p] + 1;
    anc[v][0] = p;
    for(int i = 1; i < MAXL; i++){
        anc[v][i] = anc[anc[v][i-1]][i-1];
    }

    tin[v] = ++t;
    xorpref[v] = x;
    for(auto u : graph[v]){
        if(u != p){
            dfs(u, v, (x ^ arr[u]));
        }
    }
    tout[v] = t;
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
    freopen("cowland.in", "r", stdin);
    freopen("cowland.out", "w", stdout);
    int n, q; cin >> n >> q;
    //leitura dos valores
    for(int i = 0; i < n; i++) cin >> arr[i];

    //leitura do grafo
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    //chamada da dfs
    dfs(0, 0, arr[0]);

    segtree st;
    st.init(n);

    vector<int> vxor(n);
    /*
    p cada start time, vou pegar o valor 
    */
    for(int i = 0; i < n; i++){
        //cout << i+1 << " " << tin[i] << " " << tout[i] << " " << xorpref[i] << endl;
        vxor[tin[i]] = xorpref[i];
        //cout << vxor[i] << " ";
    }
    //cout << endl;
    st.build(vxor);
    while(q--){
        int op; cin >> op;
        op--;
        //query de update
        if(!op){
            int i, v; cin >> i >> v;
            i--; 
            int val = (arr[i] ^ v);
            st.updateRange(tin[i], tout[i], val);
            arr[i] = v;
        }else{
            int i, j; cin >> i >> j;
            i--, j--;
            int x1 = st.query(tin[i], tin[i]);
            int x2 = st.query(tin[j], tin[j]);
            int mac = lca(i, j);
            //int x3 = st.query(tin[mac], tout[mac]);
            int ans = (x1 ^ x2 ^ arr[mac]);
            cout << ans << endl;
        }
    }
}