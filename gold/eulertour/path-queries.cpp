#include <bits/stdc++.h>
using namespace std;

#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
#define endl "\n"

const int MAXN = 2*(1e5)+7;
int arr[MAXN], visited[MAXN], somas[MAXN], tin[MAXN], tout[MAXN];
vector<int> graph[MAXN];
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
            t[v] += (r - l + 1)*lazy[v];
            if(l != r){
                lazy[2*v+1] += lazy[v];
                lazy[2*v+2] += lazy[v];
            }
            lazy[v] = 0;
        }
    }

    void updateRange(int v, int l, int r, int lx, int rx, int x){
        propagate(v, l, r);
        if(rx < l || r < lx) return;
        if(lx <= l && r <= rx){
            lazy[v] += x;
            propagate(v, l, r);
            return;
        }

        int m = (l+r)/2;
        updateRange(2*v+1, l, m, lx, rx, x);
        updateRange(2*v+2, m+1, r, lx, rx, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void updateRange(int l, int r, int val){
        updateRange(0, 0, n-1, l, r, val);
    }

    int queryRange(int v, int l, int r, int lx, int rx){
        propagate(v, l, r);
        if(rx < l || r < lx) return 0;
        if(lx <= l && r <= rx) return t[v];
        int m = (l+r)/2;
        return queryRange(2*v+1, l, m, lx, rx) + queryRange(2*v+2, m+1, r, lx, rx);
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
        t[v] = t[2*v+1] + t[2*v+2];
    }
    void build(vector<int> &a) {
        build(a, 0, 0, n-1);
    }

};

void dfs(int v, int sum){
    visited[v] = 1;
    tin[v] = ++t;
    somas[v] = sum;
    for(auto u : graph[v]){
        if(!visited[u]){
            dfs(u, sum + arr[u]);
        }
    }
    tout[v] = t;
}

signed main(){
    //fastio;
    int n, q; cin >> n >> q;

    for(int i = 0; i < n; i++) cin >> arr[i];
    
    for(int i = 0; i < n-1; i++){
        int a, b; 
        cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    dfs(0, arr[0]);

    //a soma baseado na ordem de entrada
    vector<int> vsums(n);
    for(int i = 0; i < n; i++){
        //checando se ta certo o vetor
        //cout << i+1 << " " << tin[i] << " " << tout[i] << " " << somas[i] << endl;
        vsums[tin[i]] = somas[i];
    }

    //ok construcao ta certa
    // for(int i = 0; i < n; i++){
    //     cout << i << ": " << vsums[i] << endl;
    // }

    segtree st;
    st.init(n);
    st.build(vsums);

    // for(int i = 0; i < 4*n; i++){
    //     cout << st.t[i] << " ";
    // }
    // cout << endl;

    while(q--){
        int op; cin >> op;
        op--;
        if(!op){
            int s, x; cin >> s >> x;
            s--;
            int val = x - arr[s];
            //cout << val << endl;
            arr[s] = x;
            st.updateRange(tin[s], tout[s], val);
            // for(int i = 0; i < n; i++){
            //     cout << st.t[i] << " ";
            // }
            // cout << endl;
        }else{
            int s; cin >> s;
            s--;
            //cout << s+1 << " " << tin[s] << " " << tout[s] << endl; 
            cout << st.query(tin[s], tin[s]) << endl;
        }
    }
}