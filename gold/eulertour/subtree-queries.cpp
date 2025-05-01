#include <bits/stdc++.h>
using namespace std;

#define endl "\n"
#define fastio ios_base::sync_with_stdio(0); cin.tie(0)
#define int long long
const int MAXN = 2*(1e5)+7;

vector<int> graph[MAXN];
int tin[MAXN], tout[MAXN], visited[MAXN];

int timer = 0;

void dfs(int v){
    tin[v] = ++timer;
    visited[v] = 1;
    for(auto u : graph[v]){
        if(!visited[u]) dfs(u);
    }
    tout[v] = timer;
}

struct segtree{
    int n;
    vector<int> t;
    void init(int _n){
        n = _n;
        t.assign(4*n, 0);
    }

    void build(vector<int> &arr, int v, int l, int r){
        if(l == r){
            t[v] = arr[l];
            return;
        }
        int m = (l+r)/2;
        build(arr, 2*v+1, l, m);
        build(arr, 2*v+2, m+1, r);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void build(vector<int> &arr){
        build(arr, 0, 0, n-1);
    }

    int query(int v, int l, int r, int ql, int qr){
        if(qr < l || r < ql) return 0;
        if(ql <= l && r <= qr) return t[v];
        int m = (l+r)/2;
        return query(2*v+1, l, m, ql, qr) + query(2*v+2, m+1, r, ql, qr);
    }

    int query(int l, int r){
        if(l > r) return 0;
        return query(0, 0, n-1, l, r);
    }

    void update(int v, int l, int r, int idx, int x){
        if(l == r){
            t[v] += x;
            return;
        }

        int m = (l+r)/2;
        if(idx <= m) update(2*v+1, l, m, idx, x);
        else update(2*v+2, m+1, r, idx, x);
        t[v] = t[2*v+1] + t[2*v+2];
    }

    void update(int idx, int x){
        update(0, 0, n-1, idx, x);
    }
};

signed main(){
    fastio;
    int n, q; cin >> n >> q;
    vector<int> arr(n);
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
    for(int i = 0; i < n-1; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }   
    
    dfs(0);
    // for(int i = 0; i < n; i++){
    //     cout << tin[i] << " ";
    // }
    // cout << endl;
    // for(int i = 0; i < n; i++){
    //     cout << tout[i] << " ";
    // }
    // cout << endl;
    segtree st;
    st.init(n);
    for(int i = 0; i < n; i++){
        st.update(tin[i]-1, arr[i]);
    }
    while(q--){
        int op; cin >> op;
        op--;
        if(!op){
            int s, x; cin >> s >> x;
            s--;
            st.update(tin[s]-1, x - arr[s]);
            arr[s] = x;
        }else{
            int s; cin >> s;
            s--;
            cout << st.query(tin[s]-1, tout[s]-1) << endl;
        }
    }
    
}